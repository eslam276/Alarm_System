/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: BZR_prog.c		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/


/********************************************************************************
 *********************** ### INCLUDE SECTION ### ********************************
 ********************************************************************************/
#include <stdint.h>

#include "ErrType.h"

#include "GPIO_private.h"
#include "GPIO_interface.h"

#include "BZR_prv.h"
#include "BZR_interface.h"
/********************************************************************************/

/********************************************************************************
 *************** ### FUNCTION IMPLEMENTATION SECTION ### ************************
 ********************************************************************************/
void BZR_Init(void)
{
	GPIO_PinConfig_t Copy_PinConfig={
				.Port 		= BZR_PORT				,
				.PinNum 	= BZR_PIN				,
				.Mode		= OUTPUT_SPEED_2MHz	,
				.Output	= OUTPUT_PUSH_PULL		,
				.Input	= ANALOGE
		};
		/*GPIO pin initialization*/
		GPIO_u8PinInit(&Copy_PinConfig);
		GPIO_u8SetPinValue(BZR_PORT, BZR_PIN, PIN_LOW);
}

void BZR_On(void)
{
	GPIO_u8SetPinValue(BZR_PORT, BZR_PIN, PIN_HIGH);
}

void BZR_Off(void)
{
	GPIO_u8SetPinValue(BZR_PORT, BZR_PIN, PIN_LOW);
}

/********************************************************************************/
