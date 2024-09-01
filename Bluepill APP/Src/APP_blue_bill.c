/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: APP_blue_bill.c		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#include <stdint.h>
#include "stm32f103xx.h"
#include "ErrType.h"
#include "RCC_Interface.h"
#include "AFIO_Interface.h"
#include "EXTI_Interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "USART_interface.h"
#include "SYSTIC_interface.h"

#include "LED_interface.h"
#include "BZR_interface.h"
#include "CLCD_interface.h"

#include "APP_blue_bill.h"


uint8_t RecivedData[14] ={0};

void RCC_Clock_Init(void)
{
	RCC_SetClkSts(CLK_SRC_HSE,RCC_ON);
	RCC_SetSysClk(CLK_SRC_HSE);
    RCC_APB2EnableClock(APB2_IOPA);
    RCC_APB2EnableClock(APB2_IOPB);
	RCC_APB2EnableClock(APB2_IOPC);
/*	RCC_APB2EnableClock(APB2_SPI1);*/
	RCC_APB2EnableClock(APB2_AFIO);
	RCC_APB2EnableClock(APB2_USART);
}
void Pins_Init(void)
{
	/* RED LED1 Configuration*/
	LED_Init(PORTA ,PIN2);
	/* GREEN LED Configuration*/
	LED_Init(PORTC ,PIN15);
	LED_Init(PORTC ,PIN14);
	/*BUZZER Configuration*/
	BZR_Init();

	/* Initialize the Read Pin */
	GPIO_PinConfig_t Read_Pin = {.Port = PORTB, .PinNum = PIN13, .Mode = INPUT,  .Input = PULLUP_PULLDOWN};

	/* Initialize the EXTI Pin */
	GPIO_u8PinInit(&Read_Pin);
    /*USART PINS Configuration*/
	GPIO_PinConfig_t Local_TxConfig={
				.Port = PORTA,
				.PinNum = PIN9,
				.Mode = OUTPUT_SPEED_10MHz,
				.Output = AF_PUSH_PULL,
				.Input = FLOATING
		};
	GPIO_u8PinInit(&Local_TxConfig);
	GPIO_PinConfig_t Local_RxConfig={
				.Port = PORTA,
				.PinNum = PIN10,
				.Mode = INPUT,
				.Output = AF_PUSH_PULL,
				.Input = FLOATING
		};
	GPIO_u8PinInit(&Local_RxConfig);

}

void Interrupts_Init(void)
{
	NVIC_EnableIRQ(NVIC_IRQ_SPI1);
	NVIC_EnableIRQ(NVIC_IRQ_EXTI15_10);
	NVIC_EnableIRQ(NVIC_IRQ_USART1);
}
void DisplayAlarmInfo(void)
{
	CLCD_voidSendCmd(1);

	uint8_t counter=0;
	for(counter=1 ; RecivedData[counter] != 13 ;counter++)
	{
		if(counter == 1)
		{
			CLCD_u8SendString("Alarm Number=");
			CLCD_voidSendData(RecivedData[counter] + 48);
			CLCD_voidGoToXY(1, 0);
		}
		else
		{
			CLCD_voidSendData(RecivedData[counter]);
		}
	}
	for(counter=0 ; counter<4 ;counter++)
	{
		SYSTIC_delay_ms(890);
	}

	CLCD_voidSendCmd(1);
}
void Display_Time(void)
{
	CLCD_voidGoToXY(1, 0);

	CLCD_voidSendNumber(RecivedData[4]);
	CLCD_voidSendNumber(RecivedData[5]);
	CLCD_voidSendData(':');

	CLCD_voidSendNumber(RecivedData[2]);
	CLCD_voidSendNumber(RecivedData[3]);
	CLCD_voidSendData(':');

	CLCD_voidSendNumber(RecivedData[0]);
	CLCD_voidSendNumber(RecivedData[1]);
	CLCD_voidSendData(':');

}
void Display_Date(void)
{
	CLCD_voidGoToXY(0, 0);

	switch (RecivedData[7])
	{
	case '1'    : CLCD_u8SendString( (char *)"MON") ; break;
	case '2'    : CLCD_u8SendString( (char *)"TUE") ; break;
	case '3'    : CLCD_u8SendString( (char *)"TUE") ; break;
	case '4'    : CLCD_u8SendString( (char *)"WED") ; break;
	case '5'    : CLCD_u8SendString( (char *)"THU") ; break;
	case '6'    : CLCD_u8SendString( (char *)"FRI") ; break;
	case '7'    : CLCD_u8SendString( (char *)"SAT") ; break;
	}

	CLCD_voidSendNumber(RecivedData[8]);
	CLCD_voidSendNumber(RecivedData[9]);
	CLCD_voidSendData('/');

	CLCD_voidSendNumber(RecivedData[10]);
	CLCD_voidSendNumber(RecivedData[11]);
	CLCD_voidSendData('/');

	CLCD_voidSendNumber(2025);

}
void TURN_ON_LED(void)
{
	LED_On(PORTA, PIN2);
}
void CLEAR_DISPLAY(void)
{
	CLCD_ClearDisplay();
}
void _delay_1s( void)
{
	SYSTIC_delay_ms(890);
}

