/*
 * MC1.c
 *
 * Created: 25/10/2019
 *  Author: OSAMA HEGAZI
 */ 
#include "keypad.h"
#include "uart.h"
#include"LCD.h"
#include"HML.h"

int main(void)
{                             /*INITIALIZING HARDWARES*/
	 LCD_init();
     UART_init();
     LCD_displayStringRowColumn(0,0," welcome osama ");
     _delay_ms(1000);
     LCD_clearScreen();
     LCD_goToRowColumn(0,0);
                                         /*RECEIVING PASSWORD FROM MC2*/
                          GET_password();

	                       GAC_password(); // get password from user and send it to MC to check it


                   LCD_displayStringRowColumn(0,0,"enter the password");

                     LCD_goToRowColumn(0,0);

                       GASAC_password();

               		UART_sendByte(open); //send the pressed key to the second MC using uart







               	    LCD_clearScreen();

while(1){


     LCD_displayStringRowColumn(0,0,"the motor should be rotated now");



}


































}

