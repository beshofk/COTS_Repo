#include"STD_TYPES.h"
#include"BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPAD_interface.h"
#include "KPAD_private.h"
#include "KPAD_config.h"

u8 KPAD_Au8KPADKeys[4][4]  = KPAD_KEYS_CONFG;
u8 KPAD_Au8KPADRowsPins[4] = {KPAD_u8_R1_PIN,KPAD_u8_R2_PIN,KPAD_u8_R3_PIN,KPAD_u8_R4_PIN};
u8 KPAD_Au8KPADColsPins[4] = {KPAD_u8_C1_PIN,KPAD_u8_C2_PIN,KPAD_u8_C3_PIN,KPAD_u8_C4_PIN};

u8 KPAD_u8KPADGetState(u8 * Copy_pu8KeyState)
{
	u8 Local_u8ReturnState = STD_OK;
	u8 Local_u8RowsCounter,Local_u8ColsCounter;
	u8 Local_u8PinValue;
	u8 Local_u8BreakFlag = 0;
	//Check The Pointer Validation
	if(Copy_pu8KeyState != NULL)
	{
		//Initial value for the returned key
		*Copy_pu8KeyState = KPAD_u8_KEY_NOT_PRESSED;
		//Loop On the Rows to activate them
		for(Local_u8RowsCounter = 0 ; Local_u8RowsCounter <= 3 ; Local_u8RowsCounter++)
		{
			//Activate Row R = 0
			DIO_u8SetPinValue(KPAD_u8_PORT,KPAD_Au8KPADRowsPins[Local_u8RowsCounter],DIO_u8_LOW);
			//Loop On Cols 
			for(Local_u8ColsCounter = 0 ; Local_u8ColsCounter <= 3 ; Local_u8ColsCounter++)
			{
				//Read Cols Pin
				DIO_u8GetPinValue(KPAD_u8_PORT,KPAD_Au8KPADColsPins[Local_u8ColsCounter],&Local_u8PinValue);
				//Check if value = 0 => Return the Value of the array
				if(Local_u8PinValue == 0)
				{
					*Copy_pu8KeyState = KPAD_Au8KPADKeys[Local_u8RowsCounter][Local_u8ColsCounter];
					//Flag = 1 to Terminate outer loop
					Local_u8BreakFlag = 1;
					//Terminate Loops
					break;
				}
			}
			if(Local_u8BreakFlag == 1)
			{
				break;
			}
			//Deactivate Row 
			DIO_u8SetPinValue(KPAD_u8_PORT,KPAD_Au8KPADRowsPins[Local_u8RowsCounter],DIO_u8_HIGH);
		}
	}
	else
	{
		Local_u8ReturnState = STD_NOTOK;
	}
	return Local_u8ReturnState;
}
