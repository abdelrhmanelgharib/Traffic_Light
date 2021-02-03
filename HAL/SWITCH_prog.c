/*
 *  Author: El-Gharib
 *  Created on: 2/2/2021
 */


#include "avr/io.h"
#include "avr/delay.h"

#include "STD_Types.h"
#include "Bit_Math.h"

#include "DIO_int.h"
#include "SWITCH_prev.h"
#include "SWITCH_config.h"
#include "SWITCH_int.h"

#include "LED_int.h"
#include "SEVSEG_int.h"




u8 SWITCH_u8GetState(u8 switch_num)
{
    u8 x;

    if (switch_num == SWITCH0)
    {
        #if (SWITCH_0_CONNECTION == PULLUP)
        {
            x=DIO_u8GetPin(SWITCH_0_PIN);
            /*  */
            if (x == PRESSED)
            {
                return NOT_PRESSED;   
            }
            else
            {
                return PRESSED;
            }
            
        }
        #else
        {
            x=DIO_u8GetPin(SWITCH_0_PIN);
            if (x == PRESSED)
            {
                return PRESSED;   
            }
            else
            {
                return NOT_PRESSED;
            }
        }
        #endif
    }
    else if (switch_num == SWITCH1)
    {
        #if (SWITCH_1_CONNECTION == PULLUP)
        {
            x=DIO_u8GetPin(SWITCH_1_PIN);
            if (x == PRESSED)
            {
                return NOT_PRESSED;   
            }
            else
            {
                return PRESSED;
            }
            
        }
        #else
        {
            x=DIO_u8GetPin(SWITCH_1_PIN);
            if (x == PRESSED)
            {
                return PRESSED;   
            }
            else
            {
                return NOT_PRESSED;
            }
        }
        #endif
    }
    
}

void SWITCH_voidEmergency(void)
{
    u8 i;
    
    /* turn off left seg */
    SEVSEG_voidDisable(SEG1);

    /* turn on right seg */
    SEVSEG_voidEnable(SEG0);

     /* SEVSEG && for red LED */
    /* start counting 1-9 */
    for(i=1; i<10; i++)
    {
        /* turn on red led*/
        LED_voidLedOn(LED0);
        
        SEVSEG_voidDisplay(SEG0, i);
        _delay_ms(300);
    }

    SEVSEG_voidDisplay(SEG0, 0);
    _delay_ms(20);

    /* Disable seg0 and enable seg1 */
    SEVSEG_voidDisable(SEG0);
    SEVSEG_voidEnable(SEG1);

    /* display 10 on segment */
    SEVSEG_voidDisplay(SEG1, 1);
    _delay_ms(20);

    /* turn off red led */
    LED_voidLedOff(LED0);

    SEVSEG_voidDisable(SEG1);

    /* turn on the right seg to complete the the function that called from */
    SEVSEG_voidEnable(SEG0);

}