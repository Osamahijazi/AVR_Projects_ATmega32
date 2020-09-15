/*
 * MC2.c
 *
 * Created: 25/04/2014 11:12:30 ã
 *  Author: Mohamed Tarek
 */ 

#include "control.h"
#include "uart.h"
#include "external_eeprom.h"
#include"PWM.h"

int main(void)
{

	UART_init(); /* UART INIT*/
	EEPROM_init(); /* EEPROM INIT*/
	PWM_Timer0_Init(255); /* PMW WITH DUTY CYCLE 50%*/
	Motor_Init(); /*MOTOR INIT*/


	Load_password();  /* LOADING PASSWORD FROM EEPROM*/
	send_password();  /*SENDING OLD PASSWORD TO MC1*/


	if((UART_recieveByte() == send))     /*WAITING MC1 TO CONFIRM SAVING A NEW PASSWORD*/

		Receive_New_password();  /*SAVING PASSSWORD*/

	while((UART_recieveByte() != open)){}  /*WAITING MC1 TO CONFIRM OPENING THE DOOR*/

	Move_Motor(); /* OPENING THE DOOR*/


	while(1){



	}


}
