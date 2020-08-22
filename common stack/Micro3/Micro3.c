


#include "i2c.h"
#include "uart.h"

#include "micro_config.h"

int main(void)
{
	UART_init();
    TWI_init();


	while(1)

	{


		   TWI_readWithACK();// receiving address and sending address


		   TWI_read_StrwithAck(); // receiving the Data from micro 2


	}
	return 0;
}
