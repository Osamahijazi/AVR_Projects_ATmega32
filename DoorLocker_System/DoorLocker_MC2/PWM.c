/*
 * PWM.C
 *
 *  Created on: 29/10/2019
 *      Author: osama hejazi

*/
#include"PWM.h"

                                         /* FUNCTION DEFINITIONS*/



                                             /*Motor INIT*/
void Motor_Init(void){

	DDRC = DDRC | (1<<PC2) ;          // configure pin 3 of PORTC as output pin
	DDRC = DDRC | (1<<PC4) ;          // configure pin 3 of PORTC as output pin

	DDRC = DDRC | (1<<PC3) ;           // configure pin 4 of PORTC as output pin

	                               /* Assuming stop at the beginning*/
	CLEAR_BIT(PORTC,PC2);

	CLEAR_BIT(PORTC,PC3);
}

                                   /* PULSE WIDTH MODULATION INIT */

void PWM_Timer0_Init(unsigned char set_duty_cycle){

	TCNT0 = 0; //initial timer value // @suppress("Symbol is not resolved")

	OCR0  = set_duty_cycle;

	DDRB  = DDRB | (1<<PB3); //set OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
                                    /* OPENING AND CLOSING THE DOOR & TURN ON AND TURN OFF THE BUZZER*/

void Move_Motor(void){

	                                             /* ROTATING RIGHT */
	SET_BIT(PORTC,PC2);
	CLEAR_BIT(PORTC,PC3);
	SET_BIT(PORTC,PC4);
	_delay_ms(50000000000000);
	                                             /* ROTATING LEFT */

	SET_BIT(PORTC,PC3);
	CLEAR_BIT(PORTC,PC2);
	_delay_ms(50000000000000);

                                                     /*STOP*/

	CLEAR_BIT(PORTC,PC2);
    CLEAR_BIT(PORTC,PC3);
	CLEAR_BIT(PORTC,PC4);


}










