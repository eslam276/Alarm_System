/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: main.c        		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/


#include <stdint.h>
#include "stm32f103xx.h"
#include "ErrType.h"

#include "SYSTIC_interface.h"
#include "USART_interface.h"
#include "APP_blue_bill.h"
#include "LED_interface.h"
#include "BZR_interface.h"
#include "CLCD_interface.h"

extern uint8_t RecivedData[14]  ;


void MUSART1_u8ReceiveArray(uint8_t* arr, uint16_t size) {
    for (uint16_t i = 0; i < size; i++) {
        arr[i] = MUSART1_u8Receive();
    }
}

int main(void)
{

	RCC_Clock_Init();
	Pins_Init();
	CLCD_voidPinInit();
	CLCD_voidInit();
	Interrupts_Init();
	MUSART1_voidInit();
	CLCD_u8SendString("Welcome to Alarm");
	SYSTIC_delay_ms(2000);
	CLEAR_DISPLAY();
	uint8_t Check ;
	uint8_t Read_Pin ;

	Check = MUSART1_u8Receive();

	/* Loop forever */

	if(Check== '2')
	{
		TURN_ON_LED();
		CLCD_u8SendString("System is closed");
		while(1);
	}
	else if(Check== '1')
	{
		for(;;)
		{

			LED_On(PORTC, PIN15) ;
			CLCD_u8SendString("System is opened");
			SYSTIC_delay_ms(2000);
			CLEAR_DISPLAY();
			MUSART1_u8ReceiveArray(&RecivedData , 14);
			Display_Date();
			Display_Time();
			GPIO_u8ReadPinValue(PORTB, PIN13, &Read_Pin);
			if(Read_Pin== PIN_LOW)
			{
				DisplayAlarmInfo();
				LED_On(PORTC, PIN14);
			}
		}
	}
}
