/*
 * TFTT_Interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: osama hejazi
 */

#ifndef TFTT_INTERFACE_H_
#define TFTT_INTERFACE_H_










// Color definitions
#define   ST7735_BLACK   0x0000
#define   ST7735_BLUE    0x001F
#define   ST7735_RED     0xF800
#define   ST7735_GREEN   0x07E0
#define   ST7735_CYAN    0x07FF
#define   ST7735_MAGENTA 0xF81F
#define   ST7735_YELLOW  0xFFE0
#define   ST7735_WHITE   0xFFFF


#define   TFT_CHAR_WIDTH      6
#define   TFT_CHAR_HIGHT      8

#define    TFT_MAX_ROW       132
#define    TFT_MAX_COL       162


void TFT_voidInit (void);

void TFT_voidDisplayImage(const uint16* copy_uint16Image);

void TFT_voidDrawRectangle (uint16 copy_uint16X ,uint16 copy_uint16Y , uint16 copy_uint16Width , uint16 copy_uint16Hight , uint16 copy_uint16Color );

void TFT_voidFillDisplay (uint16 copy_uint16Colour);

void TFT_voidPrintChar(sint8 copy_sint8Char , uint16 copy_uint16X , uint16 copy_uint16Y, uint8 copy_uint8Size , uint16 copy_uint16Color, uint16 copy_uint16BackColor);

void TFT_voidPrintText(sint8 *copy_sint8Text , uint16 copy_uint16X , uint16 copy_uint16Y, uint8 copy_uint8Size , uint16 copy_uint16Color, uint16 copy_uint16BackColor);


























#endif /* TFTT_INTERFACE_H_ */
