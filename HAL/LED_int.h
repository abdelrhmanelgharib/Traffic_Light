/*
 *  Author: El-Gharib
 *  Created on: 2/2/2021
 */


#ifndef LED_INT_H_
#define LED_INT_H_

void LED_voidInitialize(void);

void LED_voidLedOn(u8 led_num);
void LED_voidLedOff(u8 led_num);
void LED_voidLedToggle(u8 led_num);



#define LED0  0
#define LED1  1
#define LED2  2



#endif  /* LED_INT_H_ */