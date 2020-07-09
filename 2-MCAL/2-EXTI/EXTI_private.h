/************************************************************/
/********************* Author : Karim Hassan ****************/
/********************* Data   : 26/6/2020    ****************/
/********************* Driver : External Interrupt  *********/
/********************* Version: 1.0          ****************/
/************************************************************/
#ifndef  EXTI_PRIVATE_H
#define  EXTI_PRIVATE_H

/* External Interrupt registers */

#define MCUCR                *((volatile u8 *)0x55) 
#define MCUCSR               *((volatile u8 *)0x54)
#define GICR                 *((volatile u8 *)0x5B)
#define GIFR                 *((volatile u8 *)0x5A)

/* Macros for MCUCR Bits */
#define MCUCR_ISC11                 3
#define MCUCR_ISC10                 2
#define MCUCR_ISC01                 1
#define MCUCR_ISC00                 0

/* Macro for MCUCSR */
#define MCUCSR_ISC2                 6

/* Macros for GICR */
#define GICR_INT1                   7
#define GICR_INT0                   6
#define GICR_INT2                   5

/* Macros for GIFR */
#define GIFR_INTF1                  7
#define GIFR_INTF0                  6
#define GIFR_INTF2                  5

/* Prototype for EXT INT0 ISR function */

void __vector_1(void)     __attribute__((signal));

void __vector_2(void)     __attribute__((signal));

void __vector_3(void)     __attribute__((signal));



#endif
