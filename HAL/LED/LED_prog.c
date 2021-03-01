/*
 *  Author: El-Gharib
 *  Created on: 2/2/2021
 */



#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO_int.h"
#include "LED_priv.h"
#include "LED_config.h"
#include "LED_int.h"



void LED_voidInitialize(void)
{

}

void LED_voidLedOn(u8 led_num)
{
    if(led_num == LED0)
    {
        #if(LED_0_CONNECTION == FORWARD)
        {
            DIO_voidSetPin(LED_0_PIN, HIGH);
        }
        #else
        {
            DIO_voidSetPin(LED_0_PIN,LOW);
        }
        #endif
    }

    if(led_num == LED1)
    {
        #if(LED_1_CONNECTION == FORWARD)
        {
            DIO_voidSetPin(LED_1_PIN, HIGH);
        }
        #else
        {
            DIO_voidSetPin(LED_1_PIN,LOW);
        }
        #endif
    }

    if(led_num == LED2)
    {
        #if(LED_2_CONNECTION == FORWARD)
        {
            DIO_voidSetPin(LED_2_PIN, HIGH);
        }
        #else
        {
            DIO_voidSetPin(LED_2_PIN,LOW);
        }
        #endif
    }

}
void LED_voidLedOff(u8 led_num)
{
    if(led_num == LED0)
    {
        #if(LED_0_CONNECTION == FORWARD)
        {
            DIO_voidSetPin(LED_0_PIN, LOW);
        }
        #else
        {
            DIO_voidSetPin(LED_0_PIN,HIGH);
        }
        #endif
    }

    if(led_num == LED1)
    {
        #if(LED_1_CONNECTION == FORWARD)
        {
            DIO_voidSetPin(LED_1_PIN, LOW);
        }
        #else
        {
            DIO_voidSetPin(LED_1_PIN,HIGH);
        }
        #endif
    }

    if(led_num == LED2)
    {
        #if(LED_2_CONNECTION == FORWARD)
        {
            DIO_voidSetPin(LED_2_PIN, LOW);
        }
        #else
        {
            DIO_voidSetPin(LED_2_PIN,HIGH);
        }
        #endif
    }
}


void LED_voidLedToggle(u8 led_num)
{
    if(led_num == LED0)
    {
        DIO_voidTogPin(LED_0_PIN);
    }

    else if(led_num == LED1)
    {
        DIO_voidTogPin(LED_1_PIN);  
    }

    else if(led_num == LED2)
    {
        DIO_voidTogPin(LED_2_PIN);
    }

}