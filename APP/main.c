/*
 *  Author: El-Gharib
 *  Created on: 2/2/2021
 */


#include "avr/io.h"
#include "avr/delay.h"

#include "STD_Types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "LED_int.h"
#include "SWITCH_int.h"
#include "SEVSEG_int.h"
#include "Traffic_Light_int.h"



int main()
{
    DIO_voidInitialize();
    SEVSEG_voidInitilize();
    LED_voidInitialize();


    SEVSEG_voidEnable(SEG0);


    while(1)
    {
        TRAFFIC_voidLight_Count();
        
    }
    return 0;
}