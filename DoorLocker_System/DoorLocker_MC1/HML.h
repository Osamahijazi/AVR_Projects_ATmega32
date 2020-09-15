/*
 * HML.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: osama hejazi
 */

#ifndef HML_H_
#define HML_H_


#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
                                   /********************PREPROCESSSING MACROS*************************************/

#define send   0x20
#define open  0x30
                          /******************************VARIABLES***************************************************************/

static uint8 key ;
static uint8 Old_password[5];
static uint8 New_password[5];
static uint8 counter;






/***************************************************************************************************************************************/
                                            /* FUNCTIONS PROTOTYPES*/

void GASAC_password (void);// to get for the first time
void GAC_password(void);// to get the password from the user to open the door
void GET_password(void);// to receive the password from uart




















#endif /* HML_H_ */
