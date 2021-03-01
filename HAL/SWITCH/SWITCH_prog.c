/*
 *  Author: El-Gharib
 *  Created on: 2/2/2021
 */


#include "avr/io.h"
#include "avr/delay.h"

#include "../UTIL/STD_Types.h"
#include "../UTIL/BIT_Math.h"
#include "../MCAL/DIO_int.h"
#include "SWITCH_prev.h"
#include "SWITCH_config.h"
#include "SWITCH_int.h"

#include "LED_int.h"
#include "SEVSEG_int.h"






u8 SWITCH_u8GetState(u8 switch_num)
{
    u8 x, ret;

    if (switch_num == SWITCH0)
    {
        #if (SWITCH_0_CONNECTION == PULLUP)
        {
            x=DIO_u8GetPin(SWITCH_0_PIN);
            if (x == HIGH)
            {
                ret= NOT_PRESSED;
            }
            else
            {
                ret= PRESSED;
            }
            
        }
        #else
        {
            x=DIO_u8GetPin(SWITCH_0_PIN);
            if (x == HIGH)
            {
                ret= PRESSED;
            }
            else
            {
                ret= NOT_PRESSED;
            }
        }
        #endif
    }
    else if (switch_num == SWITCH1)
    {
        #if (SWITCH_1_CONNECTION == PULLUP)
        {
            x=DIO_u8GetPin(SWITCH_1_PIN);
            if (x == HIGH)
            {
                ret= NOT_PRESSED;
            }
            else
            {
                ret= PRESSED;
            }
            
        }
        #else
        {
            x=DIO_u8GetPin(SWITCH_1_PIN);
            if (x == HIGH)
            {
                ret= PRESSED;
            }
            else
            {
                ret= NOT_PRESSED;
            }
        }
        #endif
    }
    return ret;
    
}
