/*
 *  Author: El-Gharib
 *  Created on: 2/2/2021
 */


#include "avr/io.h"
#include "avr/delay.h"

#include "../LIB/STD_Types.h"     
#include "../LIB/Bit_Math.h"
#include "../MCAL/DIO_int.h"
#include "../HAL/LED/LED_int.h"
#include "../HAL/SWITCH/SWITCH_int.h"
#include "../HAL/SEVSEG/SEVSEG_int.h"
#include "../SERVICE/Traffic_Light_int.h"



int main()
{
    DIO_voidInitialize();
    SEVSEG_voidInitilize();
    LED_voidInitialize();


    SEVSEG_voidEnable(SEG0);
    SEVSEG_voidDisable(SEG1);


    while(1)
    {
        TRAFFIC_voidLight_Count();
        
    }
    return 0;
}
