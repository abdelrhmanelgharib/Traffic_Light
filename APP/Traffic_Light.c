#include "avr/io.h"
#include "avr/delay.h"

#include "STD_Types.h"     
#include "Bit_Math.h"
#include "DIO_int.h"
#include "LED_int.h"
#include "SWITCH_int.h"
#include "SEVSEG_int.h"
#include "Traffic_Light_int.h"



void SEVSEG_voidPov(void)
{
    u8 i;
    /* delay 300ms */
    for (i=0; i<15*5; i++)
    {
        SEVSEG_voidDisable(SEG1);
        SEVSEG_voidDisplay(SEG0, 0);
        SEVSEG_voidEnable(SEG0);
        _delay_ms(10);

        /* Disable seg0 and enable seg1 */
        SEVSEG_voidDisable(SEG0);
        
        SEVSEG_voidDisplay(SEG1, 1);
        SEVSEG_voidEnable(SEG1);

        _delay_ms(10);


        /* check if Eemergency button is pressed */
        if (SWITCH_u8GetState(SWITCH0) == PRESSED)
        {
            /* waiting *_~_* */
            TRAFFIC_voidEmergency();
        }
    }
}



void TRAFFIC_voidEmergency(void)
{
    u8 i;
    
    /* turn off left seg */
    LED_voidLedOff(LED1);
    LED_voidLedOff(LED2);
    SEVSEG_voidDisable(SEG1);

    /* turn on right seg */
    SEVSEG_voidEnable(SEG0);

    /* turn on green led*/
    LED_voidLedOn(LED0);
     /* SEVSEG && for green LED */
    /* start counting 1-9 */
    for(i=1; i<10; i++)
    {
        SEVSEG_voidDisplay(SEG0, i);
        _delay_ms(1000);
    }
    SEVSEG_voidPov();

    /* turn off Green led */
    LED_voidLedOff(LED0);

    SEVSEG_voidDisable(SEG1);

    /* turn on the right seg to complete the the function that called from */
    SEVSEG_voidEnable(SEG0);
}



void TRAFFIC_voidLight_Count(void)
{
    u8 i;
    /* SEVSEG && for green LED */
    /* start counting 1-9 */
    for(i=1; i<10; i++)
    {
        /* turn on green led*/
        LED_voidLedOn(LED0);

        SEVSEG_voidDisplay(SEG0, i);
        _delay_ms(1000);

        /* check if EMERGENCY button pressed */
        // if (SWITCH_u8GetState(SWITCH0) == PRESSED)
        // {
        //     /* waiting *_~_* */
        //     TRAFFIC_voidEmergency();
        // }

    }
    /* POV SEVSEG */
    SEVSEG_voidPov();

    /* check EMERGENCY button pressed or not */
    if (SWITCH_u8GetState(SWITCH0) == PRESSED)
    {
        /* waiting *_~_* */
        TRAFFIC_voidEmergency();
    }

    /* right seg is already Enable in previous function */
    /* turn off seg1 to start count from 1 */
    SEVSEG_voidDisable(SEG1);

    /* turn off green led */
    LED_voidLedOff(LED0);

    /* turn on yellow led*/
    LED_voidLedOn(LED2);
    SEVSEG_voidEnable(SEG0);
    /* counting for yellow led 1-5*/
    for(i=1; i<6; i++)
    {
        SEVSEG_voidDisplay(SEG0, i);
        _delay_ms(1000);


        /* check EMERGENCY button pressed or not */
        if (SWITCH_u8GetState(SWITCH0) == PRESSED)
        {
            /* waiting *_~_* */
            TRAFFIC_voidEmergency();
            LED_voidLedOn(LED2);
        }

    }

    /* turn off yellow led */
    LED_voidLedOff(LED2);


    /* turn on red led*/
    LED_voidLedOn(LED1);
    /* SEVSEG for red LED */
    /* start counting 1-9 */
    for(i=1; i<10; i++)
    {
        SEVSEG_voidDisplay(SEG0, i);
        _delay_ms(1000);

        /* check EMERGENCY button pressed or not */
        if (SWITCH_u8GetState(SWITCH0) == PRESSED)
        {
            /* waiting *_~_* */
            TRAFFIC_voidEmergency();
            LED_voidLedOn(LED1);
        }

    }
    
    SEVSEG_voidPov();

    /* check EMERGENCY button pressed or not */
    if (SWITCH_u8GetState(SWITCH0) == PRESSED)
    {
       /* waiting *_~_* */
        TRAFFIC_voidEmergency();
    }

    
    SEVSEG_voidDisable(SEG1);
    SEVSEG_voidEnable(SEG0);
    /* turn off red led */
    LED_voidLedOff(LED1);
}