

#include "sar.h"
#include "i2c.h"


uint8 Data;


uint8 Micro2_writeData( const uint8 *u8data)
{

	   uint8 i = 0 ;

	   while(u8data[i] != '#' ){

      TWI_write(u8data[i]);

            while (TWI_getStatus() != TW_MT_DATA_ACK){ }

         	      	_delay_ms(50);


           i++;
	   }

	      TWI_write('#');


             // End if function

    /* Send the Stop Bit */
    TWI_stop();
	
    return SUCCESS;
}



