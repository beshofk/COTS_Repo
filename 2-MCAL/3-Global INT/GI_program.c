/************************************************************/
/********************* Author : Karim Hassan ****************/
/********************* Data   : 26/6/2020    ****************/
/********************* Driver : Global Interrupt    *********/
/********************* Version: 1.0          ****************/
/************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GI_interface.h"

#define SREG       *((volatile u8 *)0x5F)

void GI_voidGlobalIntEnable(void)
{
	SET_BIT(SREG,7);
}

void GI_voidGlobalIntDisable(void)
{
	CLR_BIT(SREG,7);
}