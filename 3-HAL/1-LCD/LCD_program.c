#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>


#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

void LCD_voidInit(void)
{
#if LCD_INIT_MODE == LCD_8_BIT_MODE
	_delay_ms(35);
	/* Func set */
	LCD_voidWriteCmnd(0b00111000);
	_delay_us(40);
	LCD_voidWriteCmnd(0b00001111);
	_delay_us(40);
	LCD_voidWriteCmnd(0x01);
	_delay_ms(2);
	LCD_voidWriteCmnd(0b00000110);

#elif LCD_INIT_MODE == LCD_4_BIT_MODE
	_delay_ms(35);
    /* send 4 bits high of the Func set cmnd */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,0b00100000);
	/* Enable Latch */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	/* Func set */
	LCD_voidWriteCmnd(0b00101000); //DB4 0
	_delay_us(40);
	LCD_voidWriteCmnd(0b00001111);
	_delay_us(40);
	LCD_voidWriteCmnd(0x01);
	_delay_ms(2);
	LCD_voidWriteCmnd(0b00000110);



#endif
}

void LCD_voidWriteCmnd(u8 Copy_u8Cmnd)
{
#if LCD_INIT_MODE == LCD_8_BIT_MODE
	/* RW = 0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* RS = 0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	/* SET Port value with Cmnd Byte */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmnd);
	/* Enable Latch */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
#elif LCD_INIT_MODE == LCD_4_BIT_MODE
	/* 4 bit mode */
	/* RW = 0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* RS = 0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	/* SET Port value with Cmnd 4 bit high */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmnd);
	/* Enable Latch */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);

	/*send 4 bit low*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmnd<<4);
	/* Enable Latch */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
#endif
}

void LCD_voidWriteChar(u8 Copy_u8Char)
{
#if LCD_INIT_MODE == LCD_8_BIT_MODE
	/* RW = 0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* RS = 1 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	/* SET Port value with Char Byte */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);
	/* Enable Latch */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
#elif LCD_INIT_MODE == LCD_4_BIT_MODE
	/* RW = 0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* RS = 1 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	/* SET Port value with Char 4 bit high  */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);
	/* Enable Latch */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	/*send 4 bit low */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char<<4);
	/* Enable Latch */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1);
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);

#endif
}
void LCD_voidWriteString(u8 * Copy_pu8String)
{
	for(u8 Local_u8counter = 0; Copy_pu8String[Local_u8counter]!= '\0' ; Local_u8counter++)
	{
		LCD_voidWriteChar(Copy_pu8String[Local_u8counter]);
	}
}
void LCD_voidGoToXY(u8 Copy_u8X,u8 Copy_u8Y)
{
	switch (Copy_u8X)
	{
	case 1:LCD_voidWriteCmnd(0x80+Copy_u8Y-1);break;
	case 2:LCD_voidWriteCmnd(0xc0+Copy_u8Y-1);break;
	}
}

void LCD_voidLCDClearScreen(void)
{
	LCD_voidWriteCmnd(0x01);
	_delay_ms(2);
}

void LCD_voidWriteSpecialChar(u8 Copy_u8CharIndex, u8 * Copy_pu8Pattern, u8 Copy_u8X,u8 Copy_u8Y)
{
	u8 Local_u8CGRAMAdd = Copy_u8CharIndex * 8;
	/* Set CGRAM Add */
	LCD_voidWriteCmnd(0b01000000 + Local_u8CGRAMAdd);
	/* Put the Pattern in CGRAM */
	for(u8 Local_u8Counter = 0; Local_u8Counter < 8 ; Local_u8Counter++)
	{
		LCD_voidWriteChar(Copy_pu8Pattern[Local_u8Counter]);
	}
	/* Set DDRAM Add */
	LCD_voidGoToXY(Copy_u8X,Copy_u8Y);
	/* Write on LCD */
	LCD_voidWriteChar(Copy_u8CharIndex);
}

void LCD_voidWriteNumber(u16 Copy_u16Number)
{
	u16 Local_u16Rev = 0;
	// to reverse number
	while(Copy_u16Number != 0)
	{
		Local_u16Rev = (Local_u16Rev *10 ) + (Copy_u16Number % 10);
		Copy_u16Number = Copy_u16Number / 10;

	}

	// to split number
	Copy_u16Number = Local_u16Rev;
	while(Copy_u16Number != 0)
	{
		LCD_voidWriteChar(Copy_u16Number % 10 + '0');
		Copy_u16Number = Copy_u16Number / 10;

	}
}
