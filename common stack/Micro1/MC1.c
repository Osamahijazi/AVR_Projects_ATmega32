/*
 * MC1.c
 *
 * Created: 25/04/2014 11:09:26 ã
 *  Author: osama hijazi
 */ 

#include "uart.h"
#include "spi.h"


    uint8 Data[100];
    uint8 counter = 0 ;
    uint8 flag;


ISR(USART_RXC_vect){


    Data[counter]  = UDR;
    counter++;
    PORTA = counter;

}




int main(void)
{
	DDRA=0XFF;
	UART_init();

      SREG |=(1<<7);

	SPI_initMaster();

    while(1)

    {


    	if( Data[counter-1] == '#' ){

        	    SPI_sendByte(counter); // sending the size of the Data to Micro2

    			SPI_SendString(Data); // sending Data to Micro2

    			Data[counter-1] = 0 ;

    			counter=0;
    	}


    }
}
