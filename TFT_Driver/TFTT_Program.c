/*
 * TFTT.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: osama hejazi
 */

#include "spi.h"
#include "TFTT_Private.h"
#include "TFTT_Interface.h"
#include "TFTT_Config.h"

void TFT_voidInit   (void){/*TFT Init*/
              /* Reset Pulse */
 SET_BIT(PORTA,PA0);
_delay_ms(100);
SET_BIT(PORTA,PA0);
_delay_ms(1);
SET_BIT(PORTA,PA0);
_delay_ms(100);
SET_BIT(PORTA,PA0);
_delay_ms(100);
SET_BIT(PORTA,PA0);
_delay_us(120000);

           	/* Sleep Out Command */
	TFT_voidWriteCommand(0x11);

          	/* Wait 150 ms */

	_delay_us(150000);

	        /* Color Mode Command */
	TFT_voidWriteCommand(0x3A);
	TFT_voidWriteData   (0x05);

	        /* Display On Command */
	TFT_voidWriteCommand(0x29);

}

static void voidSetAddress (uint16 copy_uint16StartX ,uint16 copy_uint16EndX , uint16 copy_uint16StartY , uint16 copy_uint16EndY)
{
	if ( (copy_uint16StartX < TFT_MAX_ROW ) && (copy_uint16StartY < TFT_MAX_COL )){
		/* Set x Address */
		TFT_voidWriteCommand(0x2A);
		/* Start byte */
		TFT_voidWriteData((copy_uint16StartX >> 8));  // UP byte first
		TFT_voidWriteData(copy_uint16StartX);

		/* Stop byte */
		TFT_voidWriteData((copy_uint16EndX >> 8));
		TFT_voidWriteData(copy_uint16EndX);

		/* Set x Address */
		TFT_voidWriteCommand(0x2B);
		/* Start byte */
		TFT_voidWriteData((copy_uint16StartY >> 8));  // UP byte first
		TFT_voidWriteData(copy_uint16StartY);
		/* Stop byte */
		TFT_voidWriteData((copy_uint16EndY >> 8));
		TFT_voidWriteData(copy_uint16EndY);

		/* RAM write */
		TFT_voidWriteCommand(0x2C);
	}
}


 void TFT_voidWriteCommand(uint8 Copy_uint8command){

                    /*SET A0 PIN TO LOW*/
	 CLEAR_BIT(PORTA,PA1);
	              /* Send Command over SPI */
  SPI_sendByte(Copy_uint8command); /*Sent command */

}

 void TFT_voidWriteData(uint8 Copy_uint8Data){

                /*SET A0 PIN TO HIGH*/
	 SET_BIT(PORTA,PA1);

              /* Send data over SPI */
	 SPI_sendByte(Copy_uint8Data); /*Sent Data */


}

 static void voidSetColour(uint16 copy_uint16Colour)
 {

 	            /* Write pixel */
 	uint8 high_byte = (copy_uint16Colour >> 8);
 	uint8 low_byte = (copy_uint16Colour & 0xff);
 	TFT_voidWriteData(high_byte);
 	TFT_voidWriteData(low_byte);
 }

 static void voidDrawPixel (uint16 copy_uint16X , uint16 copy_uint16Y , uint16 copy_uint16Colour)
 {
 	if ( (copy_uint16X < TFT_MAX_ROW ) && (copy_uint16Y < TFT_MAX_COL )){

 		/* Set address of the pixel */
 		voidSetAddress(copy_uint16X  , copy_uint16X+1 , copy_uint16Y , copy_uint16Y+1); // DRAW only one pixel

 		/* Write pixel colour */
 		voidSetColour(copy_uint16Colour);
 	}
 }

 void TFT_voidDisplayImage(const uint16* copy_uint16Image){ // DISPLAY IMAGE ALLOVER THE SCREEN

 	/* Set address range for the whole display */
 	voidSetAddress(0  , TFT_MAX_ROW , 0 , TFT_MAX_COL);

 	uint16 local_uint16Counter ;

 	for (local_uint16Counter = 0 ; local_uint16Counter < (TFT_MAX_ROW * TFT_MAX_COL); local_uint16Counter++){

 		voidSetColour(copy_uint16Image[local_uint16Counter]);
 	}
 }


 void TFT_voidDrawRectangle (uint16 copy_uint16X ,uint16 copy_uint16Y , uint16 copy_uint16Width , uint16 copy_uint16Hight , uint16 copy_uint16Color ){

 	uint16 loacal_uint16EndX = copy_uint16X + copy_uint16Width - 1;
 	uint16 loacal_uint16EndY = copy_uint16Y + copy_uint16Hight - 1;

 	/* Set area of addresses */
 	voidSetAddress(copy_uint16X ,loacal_uint16EndX,copy_uint16Y ,loacal_uint16EndY );

 	/* Draw the Rectangle*/
 	for (uint16 counter = 0 ; counter < (copy_uint16Width *copy_uint16Hight ) ; counter++){

 		voidSetColour(copy_uint16Color);
 	}
 }


 void TFT_voidPrintChar(sint8 copy_sint8Char , uint16 copy_uint16X , uint16 copy_uint16Y, uint8 copy_uint8Size , uint16 copy_uint16Color, uint16 copy_uint16BackColor)
 {
 	/* Get array index */
 	uint8 local_uint8CharIndex = 0 ;
 	if (( copy_sint8Char >= ' ' )){
 		local_uint8CharIndex = copy_sint8Char - 32 ;
 	}

 	/* Background */
 	//TFT_voidDrawRectangle( copy_uint16X, copy_uint16Y ,copy_uint8Size*TFT_CHAR_WIDTH ,copy_uint8Size*TFT_CHAR_HIGHT ,copy_uint16BackColor);

 	for (uint8 i = 0; i <TFT_CHAR_WIDTH ; i++ ){

 		for (uint8 j = 0 ; j <TFT_CHAR_HIGHT ; j++){

 			if (TFT_CHAR_font_ARRAY[local_uint8CharIndex][i] & (1 << j)){

 				if (copy_uint8Size == 1){

 					voidDrawPixel(copy_uint16X+i , copy_uint16Y+j , copy_uint16Color);

 				}

 				else {

 					uint16 local_x = copy_uint16X+(i*copy_uint8Size) ;

 					uint16 local_y = copy_uint16Y+(j*copy_uint8Size) ;

 					TFT_voidDrawRectangle( local_x, local_y ,copy_uint8Size ,copy_uint8Size ,copy_uint16Color);
 				}
 			}
 		}
 	}
 }

 void TFT_voidPrintText(sint8 *copy_sint8Text , uint16 copy_uint16X , uint16 copy_uint16Y, uint8 copy_uint8Size , uint16 copy_uint16Color, uint16 copy_uint16BackColor){

 	while (*copy_sint8Text){

 		TFT_voidPrintChar(*copy_sint8Text , copy_uint16X ,copy_uint16Y ,copy_uint8Size ,copy_uint16Color,copy_uint16BackColor );

 		copy_uint16X += (copy_uint8Size *TFT_CHAR_WIDTH)  ;

 		copy_sint8Text++;
 	}
 }

 void TFT_voidFillDisplay (uint16 copy_uint16Colour){
 	TFT_voidDrawRectangle(0 , 0 ,TFT_MAX_ROW , TFT_MAX_COL , copy_uint16Colour);
 }

