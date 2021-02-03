/*
 *  Author: El-Gharib
 *  Created on: 2/2/2021
 */

#ifndef SWITCH_INT_H_
#define SWITCH_INT_H_

u8 SWITCH_u8GetState(u8 switch_num);

void SWITCH_voidEmergency(void);



#define PRESSED         1
#define NOT_PRESSED     0 

#define SWITCH0     0     
#define SWITCH1     1




#endif /* SWITCH_INT_H_ */