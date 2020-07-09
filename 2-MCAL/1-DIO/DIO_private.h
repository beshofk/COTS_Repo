/*
 * DIO_private.h
 *
 *  Created on: May 22, 2020
 *      Author: KAPOO
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DDRA_REG            *((volatile u8*)0x3A)
#define PORTA_REG           *((volatile u8*)0x3B)
#define PINA_REG            *((volatile u8*)0x39)

#define DDRB_REG            *((volatile u8*)0x37)
#define PORTB_REG           *((volatile u8*)0x38)
#define PINB_REG            *((volatile u8*)0x36)

#define DDRC_REG            *((volatile u8*)0x34)
#define PORTC_REG           *((volatile u8*)0x35)
#define PINC_REG            *((volatile u8*)0x33)

#define DDRD_REG            *((volatile u8*)0x31)
#define PORTD_REG           *((volatile u8*)0x32)
#define PIND_REG            *((volatile u8*)0x30)

/* Macros for INITIAL directions */
#define DIO_u8_INPUT               0
#define DIO_u8_OUTPUT              1
/* Macros for INITIAL Values */
#define DIO_u8_INITIAL_HIGH        1
#define DIO_u8_INITIAL_LOW         0
#define DIO_u8_INITIAL_PULLUP      1
/* Conc function like Macro */
#define CONC(P7,P6,P5,P4,P3,P2,P1,P0)                     CONC_HELP(P7,P6,P5,P4,P3,P2,P1,P0)
#define CONC_HELP(P7,P6,P5,P4,P3,P2,P1,P0)                0b##P7##P6##P5##P4##P3##P2##P1##P0

#endif /* DIO_PRIVATE_H_ */
