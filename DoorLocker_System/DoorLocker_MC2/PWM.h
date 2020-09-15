/*
 * PWM.h
 *
 *  Created on: 29/10/2019
 *      Author: osama hejazi
 */

#ifndef PWM_H_
#define PWM_H_



#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
                                                /*  FUNCTIONS PROTOTYPES  */

void PWM_Timer0_Init(unsigned char); // ACTIVATE PWM OF TIMER 0
void Motor_Init(void);
void Move_Motor(void);








#endif /* PWM_H_ */
