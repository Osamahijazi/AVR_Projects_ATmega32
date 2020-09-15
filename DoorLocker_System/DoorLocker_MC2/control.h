/*
 * HML.h
 *
 *  Created on: 25/10/2019
 *      Author: osama hejazi
 */

#ifndef CONTROL_H_
#define CONTROL_H_


#include "uart.h"
#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
                                                   /* preprocessor Macros */
#define send   0x20
#define open   0x30

                                                      /*   variables  */
static uint8 Old_password [5];
static uint8 counter = 0;
static uint8 Data = 0 ;




                        /**********************************************************************/
                                                   /* FUNCTIONS PROTOTYPES*/

void Receive_New_password (void);//receive password from MC1 and save it in the EEPROM
void Load_password(void);// load the password from the EEPROM
void send_password(void);//send password to MC1




















#endif /* CONTROL_H_ */
