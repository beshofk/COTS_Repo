/************************************************************/
/********************* Author : Karim Hassan ****************/
/********************* Data   : 12/6/2020    ****************/
/********************* Driver : Keypad       ****************/
/********************* Version: 1.0          ****************/
/************************************************************/
#ifndef KPAD_INTERFACE_H
#define KPAD_INTERFACE_H

#define KPAD_u8_KEY_NOT_PRESSED    0xff

u8 KPAD_u8KPADGetState(u8 * Copy_pu8KeyState);

#endif