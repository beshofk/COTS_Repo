/*
 * LCD_interface.h
 *
 *  Created on: Jun 5, 2020
 *      Author: KAPOO
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidInit(void);

void LCD_voidWriteCmnd(u8 Copy_u8Cmnd);

void LCD_voidWriteChar(u8 Copy_u8Char);

void LCD_voidWriteString(u8 * Copy_pu8String);

void LCD_voidGoToXY(u8 Copy_u8X,u8 Copy_u8Y);

void LCD_voidLCDClearScreen(void);

void LCD_voidWriteSpecialChar(u8 Copy_u8CharIndex, u8 * Copy_pu8Pattern, u8 Copy_u8X,u8 Copy_u8Y);

void LCD_voidWriteNumber(u16 Copy_u16Number);

#endif /* LCD_INTERFACE_H_ */
