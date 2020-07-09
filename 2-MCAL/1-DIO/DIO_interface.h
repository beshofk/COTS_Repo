/*
 * DIO_interface.h
 *
 *  Created on: May 22, 2020
 *      Author: KAPOO
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Macros For Ports */
#define DIO_u8_PORTA            0
#define DIO_u8_PORTB            1
#define DIO_u8_PORTC            2
#define DIO_u8_PORTD            3

/* Macros for Pins */
#define DIO_u8_PIN0             0
#define DIO_u8_PIN1             1
#define DIO_u8_PIN2             2
#define DIO_u8_PIN3             3
#define DIO_u8_PIN4             4
#define DIO_u8_PIN5             5
#define DIO_u8_PIN6             6
#define DIO_u8_PIN7             7

/* Macros for the output values */
#define DIO_u8_HIGH             1
#define DIO_u8_LOW              2

/* Macros for the output values for the whole port */
#define DIO_u8_PORT_HIGH        0xff
#define DIO_u8_PORT_LOW          0

/* Set Initial directions and values for PINS */
u8 DIO_u8Init(void);

/* Set Pin Value */
u8 DIO_u8SetPinValue(u8 Copy_u8PortId,u8 Copy_u8PINId,u8 Copy_u8PinValue);

/* If the Pin is input, Read the value of the PIN */
u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PINId,u8 * Copy_pu8ReturnedPinValue);

/* Set Port Value */
u8 DIO_u8SetPortValue(u8 Copy_u8PortId,u8 Copy_u8PortValue);

/* Read Port Value */
u8 DIO_u8GetPortValue(u8 Copy_u8PortId,u8 * Copy_pu8ReturnedPortValue);


#endif /* DIO_INTERFACE_H_ */
