/*
 * HML.c
 *
 *  Created on: 25/10/2019
 *      Author: osama hejazi
 */


#include "control.h"
#include "external_eeprom.h"
#include"uart.h"

                                          /* Receive New password from the user */

void Receive_New_password(void){

	for(counter=0;counter<5;counter++){

		UART_sendByte(send);// send byte to MC2to get ready for transsimion
		Data=UART_recieveByte(); //receive the pressed key from UART
		EEPROM_writeByte((0x0311+counter),Data); /* Write Data in the external EEPROM */
		_delay_ms(10);

	}

                                         /*  loading the password from EEPROM to send it to MC1         */
}
void Load_password(){



	for(counter=0;counter<5;counter++){
		EEPROM_readByte((0x0311+counter),(&(Old_password[counter])));  /* to save the password in the array  */
		_delay_ms(500);

	}


}

                        /* Sending password from EEPROM to MC1 to compare it with entered password by the user*/

void send_password(void){

	for (counter=0;counter<5;counter++){

		while(UART_recieveByte() !=  send){}// waiting to get ready from MC1

		UART_sendByte(Old_password[counter]);// sending password byte by byte


	}

}











