/************************************************************/
/********************* Author : Karim Hassan ****************/
/********************* Data   : 26/6/2020    ****************/
/********************* Driver : External Interrupt  *********/
/********************* Version: 1.0          ****************/
/************************************************************/
/* Lib */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/* Global pointer to function for each INT */

static void (*EXTI_pfunEXTINT0)(void) = NULL;
static void (*EXTI_pfunEXTINT1)(void) = NULL;
static void (*EXTI_pfunEXTINT2)(void) = NULL;


u8 EXTI_u8ExtIEnable(u8 Copy_u8ExtIntIndex, u8 Copy_u8ExtIntEdgeSource)
{
	u8 Local_u8ReturnedState = STD_TYPES_OK;
	if((Copy_u8ExtIntIndex >= EXTI_u8_EXTINT0) && (Copy_u8ExtIntIndex <= EXTI_u8_EXTINT2) 
		&& (Copy_u8ExtIntEdgeSource >= EXTI_u8_EXTINT_SOURCE_FALLING_EDGE) && 
		(Copy_u8ExtIntEdgeSource <= EXTI_u8_EXTINT_SOURCE_LOW_LEVEL))
		{
			//Switch on INT
			switch (Copy_u8ExtIntIndex)
			{
				case EXTI_u8_EXTINT0:
				switch(Copy_u8ExtIntEdgeSource)
				{
					case EXTI_u8_EXTINT_SOURCE_FALLING_EDGE:
					SET_BIT(MCUCR,MCUCR_ISC01);
					CLR_BIT(MCUCR,MCUCR_ISC00);
					break;
					case EXTI_u8_EXTINT_SOURCE_RAISING_EDGE:
					SET_BIT(MCUCR,MCUCR_ISC01);
					SET_BIT(MCUCR,MCUCR_ISC00);
					break;
					case EXTI_u8_EXTINT_SOURCE_ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR,MCUCR_ISC00);
					CLR_BIT(MCUCR,MCUCR_ISC01);
					break;
					case EXTI_u8_EXTINT_SOURCE_LOW_LEVEL:
					CLR_BIT(MCUCR,MCUCR_ISC01);
					CLR_BIT(MCUCR,MCUCR_ISC00);
					break;
				}
				//Enable EXTINT 0
				SET_BIT(GICR,GICR_INT0);	
				break;
				case EXTI_u8_EXTINT1:
				switch(Copy_u8ExtIntEdgeSource)
				{
					case EXTI_u8_EXTINT_SOURCE_FALLING_EDGE:
					SET_BIT(MCUCR,MCUCR_ISC11);
					CLR_BIT(MCUCR,MCUCR_ISC10);
					break;
					case EXTI_u8_EXTINT_SOURCE_RAISING_EDGE:
					SET_BIT(MCUCR,MCUCR_ISC11);
					SET_BIT(MCUCR,MCUCR_ISC10);
					break;
					case EXTI_u8_EXTINT_SOURCE_ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR,MCUCR_ISC10);
					CLR_BIT(MCUCR,MCUCR_ISC11);
					break;
					case EXTI_u8_EXTINT_SOURCE_LOW_LEVEL:
					CLR_BIT(MCUCR,MCUCR_ISC11);
					CLR_BIT(MCUCR,MCUCR_ISC10);
					break;
				}
				//Enable EXTINT 1
				SET_BIT(GICR,GICR_INT1);
				break;
				case EXTI_u8_EXTINT2:
				switch(Copy_u8ExtIntEdgeSource)
				{
					case EXTI_u8_EXTINT_SOURCE_FALLING_EDGE:
					CLR_BIT(MCUCSR,MCUCSR_ISC2);
					//Enable EXTINT 2
					SET_BIT(GICR,GICR_INT2);
					break;
					case EXTI_u8_EXTINT_SOURCE_RAISING_EDGE:
					SET_BIT(MCUCSR,MCUCSR_ISC2);
					//Enable EXTINT 2
					SET_BIT(GICR,GICR_INT2);
					break;
					default :
					Local_u8ReturnedState = STD_TYPES_NOK;
				}				
				break;
			}
		}
		else
		{
			Local_u8ReturnedState = STD_TYPES_NOK;
		}
	return Local_u8ReturnedState;
}

u8 EXTI_u8ExtIDisable(u8 Copy_u8ExtIntIndex)
{
	u8 Local_u8Returned = STD_TYPES_OK;
	switch(Copy_u8ExtIntIndex)
	{
		case EXTI_u8_EXTINT0:
		//Disable PIE for EXT int 0
		CLR_BIT(GICR,GICR_INT0);
		break;
		case EXTI_u8_EXTINT1:
		//Disable PIE for EXT int 1
		CLR_BIT(GICR,GICR_INT1);
		break;
		case EXTI_u8_EXTINT2:
		//Disable PIE for EXT int 2
		CLR_BIT(GICR,GICR_INT2);
		break;		
	}
	return Local_u8Returned;
}

void  EXTI_voidExtINT0SetCallBack(void (*Copy_pf)(void))
{
	if(Copy_pf != NULL)
	{
		//Set global pointer to function
		EXTI_pfunEXTINT0 = Copy_pf;
	}
}

void  EXTI_voidExtINT1SetCallBack(void (*Copy_pf)(void))
{
	if(Copy_pf != NULL)
	{
		//Set global pointer to function
		EXTI_pfunEXTINT1 = Copy_pf;
	}
}

void  EXTI_voidExtINT2SetCallBack(void (*Copy_pf)(void))
{
	if(Copy_pf != NULL)
	{
		//Set global pointer to function
		EXTI_pfunEXTINT2 = Copy_pf;
	}	
}

//ISR for External Interrupt 0
void __vector_1(void)
{
	//Code when Interrupt of EXT Int 0 happened
	if(EXTI_pfunEXTINT0 != NULL)
	{
		EXTI_pfunEXTINT0();
	}
}
//ISR for External Interrupt 1
void __vector_2(void)
{
	//Code when Interrupt of EXT Int 0 happened
	if(EXTI_pfunEXTINT1 != NULL)
	{
		EXTI_pfunEXTINT1();
	}
}

//ISR for External Interrupt 2
void __vector_3(void)
{
	//Code when Interrupt of EXT Int 0 happened
	if(EXTI_pfunEXTINT2 != NULL)
	{
		EXTI_pfunEXTINT2();
	}
}
