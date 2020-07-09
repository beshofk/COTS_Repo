/************************************************************/
/********************* Author : Karim Hassan ****************/
/********************* Data   : 26/6/2020    ****************/
/********************* Driver : External Interrupt  *********/
/********************* Version: 1.0          ****************/
/************************************************************/
#ifndef  EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H

/* Macros for External Interrupts */
#define EXTI_u8_EXTINT0                             1
#define EXTI_u8_EXTINT1                             2
#define EXTI_u8_EXTINT2                             3

/* Macros for edge sources */
#define EXTI_u8_EXTINT_SOURCE_FALLING_EDGE          1
#define EXTI_u8_EXTINT_SOURCE_RAISING_EDGE          2
#define EXTI_u8_EXTINT_SOURCE_ANY_LOGICAL_CHANGE    3
#define EXTI_u8_EXTINT_SOURCE_LOW_LEVEL             4

u8    EXTI_u8ExtIEnable(u8 Copy_u8ExtIntIndex, u8 Copy_u8ExtIntEdgeSource);

u8    EXTI_u8ExtIDisable(u8 Copy_u8ExtIntIndex);

void  EXTI_voidExtINT0SetCallBack(void (*Copy_pf)(void));

void  EXTI_voidExtINT1SetCallBack(void (*Copy_pf)(void));

void  EXTI_voidExtINT2SetCallBack(void (*Copy_pf)(void));

#endif