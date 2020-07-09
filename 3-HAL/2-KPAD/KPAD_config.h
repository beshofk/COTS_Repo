/************************************************************/
/********************* Author : Karim Hassan ****************/
/********************* Data   : 12/6/2020    ****************/
/********************* Driver : Keypad       ****************/
/********************* Version: 1.0          ****************/
/************************************************************/
#ifndef KPAD_CONFIG_H
#define KPAD_CONFIG_H

/* Configuration for KPAD Port */
#define KPAD_u8_PORT           DIO_u8_PORTC
/* Configuration for KPAD ROWS Pins */
#define KPAD_u8_R1_PIN         DIO_u8_PIN0
#define KPAD_u8_R2_PIN         DIO_u8_PIN1
#define KPAD_u8_R3_PIN         DIO_u8_PIN2
#define KPAD_u8_R4_PIN         DIO_u8_PIN3

//#define KPAD_ROWS_CONFIG       {KPAD_u8_R1_PIN,KPAD_u8_R2_PIN,KPAD_u8_R3_PIN,KPAD_u8_R4_PIN}

/* Configuration for KPAD COLS Pins */
#define KPAD_u8_C1_PIN         DIO_u8_PIN4
#define KPAD_u8_C2_PIN         DIO_u8_PIN5
#define KPAD_u8_C3_PIN         DIO_u8_PIN6
#define KPAD_u8_C4_PIN         DIO_u8_PIN7

#define KPAD_KEYS_CONFG       {{'1','2','3','+'},             \
	                           {'4','5','6','-'},             \
							   {'7','8','9','*'},             \
	                           {'0','=','%','/'}}             


#endif