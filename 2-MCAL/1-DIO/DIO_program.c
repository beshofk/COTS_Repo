/* Include Library Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"



/* Set Initial directions and values for PINS */
u8 DIO_u8Init(void)
{
	u8 Local_u8ReturnState = STD_TYPES_OK;
	DDRA_REG = CONC(DIO_u8_PIN7_PORTA_INITIAL_DIRC,DIO_u8_PIN6_PORTA_INITIAL_DIRC,DIO_u8_PIN5_PORTA_INITIAL_DIRC,
			   DIO_u8_PIN4_PORTA_INITIAL_DIRC,DIO_u8_PIN3_PORTA_INITIAL_DIRC,DIO_u8_PIN2_PORTA_INITIAL_DIRC,
			   DIO_u8_PIN1_PORTA_INITIAL_DIRC,DIO_u8_PIN0_PORTA_INITIAL_DIRC);

	DDRB_REG = CONC(DIO_u8_PIN7_PORTB_INITIAL_DIRC,DIO_u8_PIN6_PORTB_INITIAL_DIRC,DIO_u8_PIN5_PORTB_INITIAL_DIRC,
			   DIO_u8_PIN4_PORTB_INITIAL_DIRC,DIO_u8_PIN3_PORTB_INITIAL_DIRC,DIO_u8_PIN2_PORTB_INITIAL_DIRC,
			   DIO_u8_PIN1_PORTB_INITIAL_DIRC,DIO_u8_PIN0_PORTB_INITIAL_DIRC);

	DDRC_REG = CONC(DIO_u8_PIN7_PORTC_INITIAL_DIRC,DIO_u8_PIN6_PORTC_INITIAL_DIRC,DIO_u8_PIN5_PORTC_INITIAL_DIRC,
			   DIO_u8_PIN4_PORTC_INITIAL_DIRC,DIO_u8_PIN3_PORTC_INITIAL_DIRC,DIO_u8_PIN2_PORTC_INITIAL_DIRC,
			   DIO_u8_PIN1_PORTC_INITIAL_DIRC,DIO_u8_PIN0_PORTC_INITIAL_DIRC);

	DDRD_REG = CONC(DIO_u8_PIN7_PORTD_INITIAL_DIRC,DIO_u8_PIN6_PORTD_INITIAL_DIRC,DIO_u8_PIN5_PORTD_INITIAL_DIRC,
			   DIO_u8_PIN4_PORTD_INITIAL_DIRC,DIO_u8_PIN3_PORTD_INITIAL_DIRC,DIO_u8_PIN2_PORTD_INITIAL_DIRC,
			   DIO_u8_PIN1_PORTD_INITIAL_DIRC,DIO_u8_PIN0_PORTD_INITIAL_DIRC);
	/* Set Initial values for the Pins */
	PORTA_REG = CONC(DIO_u8_PIN7_PORTA_INITIAL_VALUE,DIO_u8_PIN6_PORTA_INITIAL_VALUE,DIO_u8_PIN5_PORTA_INITIAL_VALUE,
			         DIO_u8_PIN4_PORTA_INITIAL_VALUE,DIO_u8_PIN3_PORTA_INITIAL_VALUE,DIO_u8_PIN2_PORTA_INITIAL_VALUE,
			         DIO_u8_PIN1_PORTA_INITIAL_VALUE,DIO_u8_PIN0_PORTA_INITIAL_VALUE);

	PORTB_REG = CONC(DIO_u8_PIN7_PORTB_INITIAL_VALUE,DIO_u8_PIN6_PORTB_INITIAL_VALUE,DIO_u8_PIN5_PORTB_INITIAL_VALUE,
			         DIO_u8_PIN4_PORTB_INITIAL_VALUE,DIO_u8_PIN3_PORTB_INITIAL_VALUE,DIO_u8_PIN2_PORTB_INITIAL_VALUE,
			         DIO_u8_PIN1_PORTB_INITIAL_VALUE,DIO_u8_PIN0_PORTB_INITIAL_VALUE);

	PORTC_REG = CONC(DIO_u8_PIN7_PORTC_INITIAL_VALUE,DIO_u8_PIN6_PORTC_INITIAL_VALUE,DIO_u8_PIN5_PORTC_INITIAL_VALUE,
    			     DIO_u8_PIN4_PORTC_INITIAL_VALUE,DIO_u8_PIN3_PORTC_INITIAL_VALUE,DIO_u8_PIN2_PORTC_INITIAL_VALUE,
				     DIO_u8_PIN1_PORTC_INITIAL_VALUE,DIO_u8_PIN0_PORTC_INITIAL_VALUE);

	PORTD_REG = CONC(DIO_u8_PIN7_PORTD_INITIAL_VALUE,DIO_u8_PIN6_PORTD_INITIAL_VALUE,DIO_u8_PIN5_PORTD_INITIAL_VALUE,
			         DIO_u8_PIN4_PORTD_INITIAL_VALUE,DIO_u8_PIN3_PORTD_INITIAL_VALUE,DIO_u8_PIN2_PORTD_INITIAL_VALUE,
			         DIO_u8_PIN1_PORTD_INITIAL_VALUE,DIO_u8_PIN0_PORTD_INITIAL_VALUE);

	return Local_u8ReturnState;
}

/* Set Pin Value */
u8 DIO_u8SetPinValue(u8 Copy_u8PortId,u8 Copy_u8PINId,u8 Copy_u8PinValue)
{
	u8 Local_u8ReturnState = STD_TYPES_OK;
	/* Check if Port Number is within the range , Pin number within range , Pin Value within range */
	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PINId <= DIO_u8_PIN7) && ((Copy_u8PinValue == DIO_u8_HIGH) || (Copy_u8PinValue == DIO_u8_LOW)))
	{
		/* Set Pin value */
		/* Check the pin value */
		if(Copy_u8PinValue == DIO_u8_HIGH)
		{
			switch (Copy_u8PortId)
			{
			case DIO_u8_PORTA:SET_BIT(PORTA_REG,Copy_u8PINId);break;
			case DIO_u8_PORTB:SET_BIT(PORTB_REG,Copy_u8PINId);break;
			case DIO_u8_PORTC:SET_BIT(PORTC_REG,Copy_u8PINId);break;
			case DIO_u8_PORTD:SET_BIT(PORTD_REG,Copy_u8PINId);break;
			}

		}
		else if(Copy_u8PinValue == DIO_u8_LOW)
		{
			switch (Copy_u8PortId)
			{
			case DIO_u8_PORTA:CLR_BIT(PORTA_REG,Copy_u8PINId);break;
			case DIO_u8_PORTB:CLR_BIT(PORTB_REG,Copy_u8PINId);break;
			case DIO_u8_PORTC:CLR_BIT(PORTC_REG,Copy_u8PINId);break;
			case DIO_u8_PORTD:CLR_BIT(PORTD_REG,Copy_u8PINId);break;
			}
		}
	}
	else
	{
		Local_u8ReturnState = STD_TYPES_NOK;
	}
	return Local_u8ReturnState;
}

/* If the Pin is input, Read the value of the PIN */
u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PINId,u8 * Copy_pu8ReturnedPinValue)
{
	u8 Local_u8ReturnState = STD_TYPES_OK;
	/* Check if Port Number is within the range , Pin number within range , Pin Value within range */
	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PINId <= DIO_u8_PIN7) && (Copy_pu8ReturnedPinValue != NULL))
	{
		/* Get Pin Value */
		switch (Copy_u8PortId)
		{
		case DIO_u8_PORTA:*Copy_pu8ReturnedPinValue = GET_BIT(PINA_REG,Copy_u8PINId);break;
		case DIO_u8_PORTB:*Copy_pu8ReturnedPinValue = GET_BIT(PINB_REG,Copy_u8PINId);break;
		case DIO_u8_PORTC:*Copy_pu8ReturnedPinValue = GET_BIT(PINC_REG,Copy_u8PINId);break;
		case DIO_u8_PORTD:*Copy_pu8ReturnedPinValue = GET_BIT(PIND_REG,Copy_u8PINId);break;
		}
	}
	else
	{
		Local_u8ReturnState = STD_TYPES_NOK;
	}

	return Local_u8ReturnState;
}

/* Set Port Value */
u8 DIO_u8SetPortValue(u8 Copy_u8PortId,u8 Copy_u8PortValue)
{
	u8 Local_u8ReturnState = STD_TYPES_OK;
 /* Check Port ID is within range */
	if(Copy_u8PortId <= DIO_u8_PORTD)
	{
		switch (Copy_u8PortId)
		{
		case DIO_u8_PORTA:PORTA_REG = Copy_u8PortValue;break;
		case DIO_u8_PORTB:PORTB_REG = Copy_u8PortValue;break;
		case DIO_u8_PORTC:PORTC_REG = Copy_u8PortValue;break;
		case DIO_u8_PORTD:PORTD_REG = Copy_u8PortValue;break;
		}
	}
	else
	{
		Local_u8ReturnState = STD_TYPES_NOK;
	}
	return Local_u8ReturnState;
}

/* Read Port Value */
u8 DIO_u8GetPortValue(u8 Copy_u8PortId,u8 * Copy_pu8ReturnedPortValue)
{
	u8 Local_u8ReturnState = STD_TYPES_OK;
	if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_pu8ReturnedPortValue != NULL) )
	{
		switch (Copy_u8PortId)
		{
		case DIO_u8_PORTA: *Copy_pu8ReturnedPortValue = PINA_REG;break;
		case DIO_u8_PORTB: *Copy_pu8ReturnedPortValue = PINB_REG;break;
		case DIO_u8_PORTC: *Copy_pu8ReturnedPortValue = PINC_REG;break;
		case DIO_u8_PORTD: *Copy_pu8ReturnedPortValue = PIND_REG;break;
		}
	}
	else
	{
		/* Error */
		Local_u8ReturnState = STD_TYPES_NOK;
	}
	return Local_u8ReturnState;
}

