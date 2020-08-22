/*
 * MC2.c
 *
 * Created: 25/04/2014 11:09:26 ã
 *  Author: osama hijazi
 */ 

#include "spi.h"
#include "sar.h"
#include "i2c.h"



int main(void)
{


	uint8 Size; // where we store The coming Data size

	SPI_initSlave(); // INITIALIZING SLAVE

	TWI_init();   //   INITIALIZING TWI

	while(1)

	{
		Size= SPI_recieveByte();  // Receiving The Data Size

		PORTD=Size;

		uint8* Data = (uint8*)malloc(Size * sizeof(uint8)); // Allocate Array to Store Data

		SPI_ReceiveString(Data);  // Receiving The Data and Store it

		// Sending the Data to micro 3

		TWI_start();  // sending Start Bit

		TWI_write(0b00000010);//Sending the address of Micro3

		while(TWI_getStatus() != TW_MT_SLA_W_ACK){} // checking for ack to prove transfer is correct

		Micro2_writeData(Data); // Sending the Data To micro3

		free(Data); // free the array
	}
}
