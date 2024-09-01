/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: GPIO_program.c		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#include <stdint.h>
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "stm32f103xx.h"
#include "BIT_MATH.h"
#include "ErrType.h"

static GPIO_RegDef_t * GPIOPORT[GPIO_PORT_NUM] = {GPIOA,GPIOB,GPIOC};


/********************************************/
/* @fn GPIO_u8PinInit
 * @brief the function initializes the GPIO pin according to the input parameters
 * @param[in] PinConfig : the initialization variables of the pins
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t *PinConfig)
{
	uint8_t Local_u8ErrorState = OK;
	if(PinConfig!=NULL)
	{
		if((PinConfig->Port <= PORTH)&&(PinConfig->PinNum <=PIN15))
		{
			/*Select GPIO mode : Input , Output  */
			uint8_t Local_u8RegNum = (PinConfig->PinNum / 8);
			uint8_t Local_u8BitNum = (PinConfig->PinNum % 8);
			(GPIOPORT[PinConfig->Port])->CR[Local_u8RegNum] &= ~(MODE_MASK << (Local_u8BitNum * MODE_PIN_ACCESS));
			(GPIOPORT[PinConfig->Port])->CR[Local_u8RegNum] |= ((PinConfig->Mode) << (Local_u8BitNum * MODE_PIN_ACCESS));
			(GPIOPORT[PinConfig->Port])->CR[Local_u8RegNum] &= ~(CNF_MASK << ((Local_u8BitNum * CNF_PIN_ACCESS) + CNF_PIN_SHIFT));
			if((PinConfig->Mode) == INPUT)
			{
				/*Select input type : Analog, Floating, PULLUP PULLDOWN*/
				(GPIOPORT[PinConfig->Port])->CR[Local_u8RegNum] |= ((PinConfig->Input) << ((Local_u8BitNum * CNF_PIN_ACCESS) + CNF_PIN_SHIFT));
			}
			else
			{
				/*Select output type : OUTPUT Push Pull, Output OpenDrain, Alternate function Push Pull, Alternate function OpenDrain*/
				(GPIOPORT[PinConfig->Port])->CR[Local_u8RegNum] |= (PinConfig->Output << ((Local_u8BitNum * CNF_PIN_ACCESS) + CNF_PIN_SHIFT));
			}
		}
		else
		{
			Local_u8ErrorState =NOK;
		}
	}
	else{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}

/***************************************************************/
/*@fn GPIO_u8SetPinValue
 * @brief the function outputs a certain value on an output pin
 * @param[in] port : the port number, get options @Port_t enum
 * @param[in] PinNum : the pin number, get options @Pin_t enum
 * @param[in] PinVal : the pin value, get options @PinVal_t enum
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal)
{
	uint8_t Local_u8ErrorState = OK;
	if((Port<=PORTH)&&(PinNum<=PIN15))
	{
		if(PinVal == PIN_LOW)
		{
			GPIOPORT[Port]->ODR &= ~(1<<PinNum);
			/* GPIOPort[Port]->BSRR = 1<< 16 + PinNum ; */
		}


		else if(PinVal == PIN_HIGH)
		{
			GPIOPORT[Port]->ODR |= (1<<PinNum);
			/* GPIOPort[Port]->BSRR = 1<<  PinNum ; */
		}
		else{
			Local_u8ErrorState =NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}
	return Local_u8ErrorState;
}

/***************************************************************/
/*@fn GPIO_u8TogglePinValue
 * @brief the function outputs a certain toggle value on an output pin
 * @param[in] port : the port number, get options @Port_t enum
 * @param[in] PinNum : the pin number, get options @Pin_t enum
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum)
{

	uint8_t Local_u8ErrorState =OK;
	if((Port <= PORTH)&&(PinNum <=PIN15)  )
	{
        TOG_BIT(GPIOPORT[Port]->ODR,PinNum);
	}
	else
	{
        Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

/***************************************************************/
/*@fn GPIO_u8ReadPinValue
 * @brief the function outputs a certain value on an output pin
 * @param[in] port : the port number, get options @Port_t enum
 * @param[in] PinNum : the pin number, get options @Pin_t enum
 * @param[in] PinVal : the pin value, get options @PinVal_t enum
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t* PinVal)
{

	uint8_t Local_u8ErrorStatus = OK;
	if(PinVal != NULL)
	{
		if((Port <= PORTH) && (PinNum <= PIN15))
		{
			*PinVal = (((GPIOPORT[Port]->IDR) >> PinNum) & 1u);
		}
		else
		{
			Local_u8ErrorStatus = NOK;
		}
	}
	else
	{
		Local_u8ErrorStatus = NULL_PTR_ERR;
	}

	return Local_u8ErrorStatus;
}
