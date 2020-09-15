/*
 * HML.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: osama hejazi
 */


#include "keypad.h"
#include "uart.h"
#include"LCD.h"
#include"HML.h"

                                                   /*FUNCTIONS DEFINITION*/
/************************************************************************************************************************************/

                                            /*RECEIVING PASSWORD FROM MC2 */
void GET_password(){

	for(counter=0;counter<5;counter++){

		UART_sendByte(send);  /* CONFIRMING RECEIVING PROCESS*/

		Old_password[counter]=UART_recieveByte(); /*SAVING PASSWORD TO COMPARING IT LATER  */

	}

}


                        /* ASK AND GET THE PASSWORD FROM THE USER TO COMPARE IT WITH THE REAL PASSWORD*/

void GAC_password(){

	while(1){
		counter=0;

		LCD_displayStringRowColumn(0,0,"enter password");

		LCD_goToRowColumn(1,0);


		for(counter=0;counter<5;counter++){  // SENDING THE PASSWORD USING UART


			key = KeyPad_getPressedKey(); //get the pressed key

			User_password[counter]=key;

			_delay_ms(2000);

			LCD_intgerToString(key);// DISPLAY
		}

		LCD_clearScreen();

		if((User_password[0] == Old_password[0])&&(User_password[1] == Old_password[1])&&(User_password[2] == Old_password[2])&&(User_password[3] == Old_password[3])&&(User_password[4] == Old_password[4]))
		{
			LCD_displayStringRowColumn(0,0,"matched");

			_delay_ms(40000);

			LCD_clearScreen();

			break;

		}

		else {
			LCD_displayStringRowColumn(0,0," pass Not matched");

			_delay_ms(40000);

			LCD_goToRowColumn(0,0);

			LCD_clearScreen();



		}

	}


}










void GASAC_password(){

	while(1){


		LCD_displayStringRowColumn(0,0," options");

		LCD_displayStringRowColumn(1,0," '+' To open");

		LCD_displayStringRowColumn(2,0," '-' To change pass");

		_delay_ms(40000);

		LCD_clearScreen();

		/*OPENING DOOR OR CHANGING THE PASSWORD*/

		if(KeyPad_getPressedKey() == '-'){

			UART_sendByte(send);// tell MC2 to enter to save fuction

			LCD_displayStringRowColumn(0,0,"Enter new pass");

			while(1){

				LCD_displayStringRowColumn(1,0,"enter it ");
				_delay_ms(5000);

				LCD_goToRowColumn(2,0);

				LCD_clearScreen();



				for(counter=0;counter<5;counter++){  // SENDING THE PASSWORD USING UART

					key = KeyPad_getPressedKey(); //get the pressed key

					_delay_ms(2000);

					LCD_intgerToString(key);// DISPLAY

					Old_password[counter]=key;
				}



				for(counter=0;counter<5;counter++){  // SENDING THE PASSWORD USING UART

					while(UART_recieveByte() != send){}

					UART_sendByte(Old_password[counter]); //send the pressed key to the second MC using uart
				}




				//UART_sendByte(send); //send the pressed key to the second MC using uart


				LCD_displayStringRowColumn(0,0,"re enter it ");

				_delay_ms(5000);

				LCD_clearScreen();



				//////////Note here you must use Enter buttton to get out of the loops

				for(counter=0;counter<5;counter++){  // SENDING THE PASSWORD USING UART

					key = KeyPad_getPressedKey(); //get the pressed key

					LCD_intgerToString(key);// DISPLAY

					_delay_ms(2000);

					New_password[counter]=key;

				}
				_delay_ms(5000);

				LCD_clearScreen();

				/*CHEACKING THE FIRST PASSWORD WITH THE SECOND PASSWORD*/
				if((Old_password[0] == New_password[0])&& (Old_password[1] == New_password[1])&& (Old_password[2] == New_password[2]) && (Old_password[3] == New_password[3])&& (Old_password[4] == New_password[4])){

					LCD_displayStringRowColumn(1,0,"matched");

					_delay_ms(10000);

					LCD_clearScreen();

					GAC_password();


					break;
				}

				else {
					LCD_displayStringRowColumn(1,0,"Not matched");

					_delay_ms(10000);

					LCD_displayStringRowColumn(2,0,"enter it again");

					_delay_ms(10000);

					LCD_clearScreen();


				}
			}//END OF SECOND WHILE LOOP & BEGIN OF FIRST BREAK


			//REPEATING STEPS


		}



		else {

			UART_sendByte(open); // enter the password Directiy

			break;// MOVING TO FUNCTION TO OPEN THE DOOR

		}

	}

}                          //END OF FUNCTION

/*Receiving the password again from user to conform opening door*/
