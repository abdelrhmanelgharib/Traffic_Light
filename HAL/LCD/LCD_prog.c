/*
 *  Author: El-Gharib
 *  Created on: 2/2/2021
 *  Version: 17
 */

#include "avr/delay.h"

#include "../UTIL/STD_Types.h"
#include "../UTIL/BIT_Math.h"
#include "../MCAL/DIO_int.h"


#include "LCD_priv.h"
#include "LCD_config.h"
#include "LCD_int.h"


static void LCD_voidCmdData(u8 Command_Data)
{
   /* send command or data */
   /* send first 4 bit */

    /* send the most significant */
    DIO_voidSetPin(LCD_PIN4, GETBIT(Command_Data, 4));
    DIO_voidSetPin(LCD_PIN5, GETBIT(Command_Data, 5));
    DIO_voidSetPin(LCD_PIN6, GETBIT(Command_Data, 6));
    DIO_voidSetPin(LCD_PIN7, GETBIT(Command_Data, 7));

    DIO_voidSetPin(E_PIN, HIGH);
    _delay_ms(1);
    DIO_voidSetPin(E_PIN, LOW);
    _delay_ms(1);

    /* send the least significant bit */
    DIO_voidSetPin(LCD_PIN4, GETBIT(Command_Data, 0));
    DIO_voidSetPin(LCD_PIN5, GETBIT(Command_Data, 1));
    DIO_voidSetPin(LCD_PIN6, GETBIT(Command_Data, 2));
    DIO_voidSetPin(LCD_PIN7, GETBIT(Command_Data, 3));

    DIO_voidSetPin(E_PIN, HIGH);
    _delay_ms(1);
    DIO_voidSetPin(E_PIN, LOW);
	_delay_ms(1);
}



void LCD_voidWriteData(u8 Data)
{
    DIO_voidSetPin(RS_PIN, HIGH);
    DIO_voidSetPin(RW_PIN, LOW);

    LCD_voidCmdData(Data);
}


void LCD_voidCommand(u8 Command)
{
    DIO_voidSetPin(RS_PIN, LOW);
    DIO_voidSetPin(RW_PIN, LOW);

    LCD_voidCmdData(Command);
}



void LCD_voidInit(void)
{
    _delay_ms(35);

    /*******************
     * clear display	*
     * change to 4 bit	*
     * two line			*
     * display on		*
     * clear display	*
     ********************/

    LCD_voidCommand(CLR_DISPLAY);
    _delay_ms(2);
    /* 4 bit mode */
    LCD_voidCommand(LCD_MODE);
    _delay_ms(2);
    /* 4 bit - two line */
    LCD_voidCommand(LCD_LINE);
    _delay_ms(2);
    /* display on */
    LCD_voidCommand(DISPLAY_ON_CURSOR_OFF);
    _delay_ms(2);

//    LCD_voidCommand(0b00000101);
//    _delay_ms(2);

    LCD_voidCommand(0b00010100);
    _delay_ms(2);

    LCD_voidCommand(CLR_DISPLAY);
    _delay_ms(2);

}


void LCD_voidSentSTR(char* Str)
{
    u8 i=0;

    while (Str[i] !='\0')
    {
        LCD_voidWriteData(Str[i]);
        i++;
    }
}
    


