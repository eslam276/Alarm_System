/*
 * APP_blue_bill.c
 *
 *  Created on: Aug 9, 2024
 *      Author: user
 */
#include <stdint.h>
#include "stm32f103xx.h"
#include "ErrType.h"
#include "RCC_Interface.h"
#include "AFIO_Interface.h"
#include "SCB_interface.h"
#include "EXTI_Interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SPI_interface.h"
#include "SYSTIC_interface.h"

#include "LED_interface.h"
#include "BZR_interface.h"
#include "CLCD_interface.h"

#include "APP_blue_bill.h"
#include "APP_blue_bill_prv.h"


/* Global Pointer to SPI_CONFIGS_t Struct */
SPI_CONFIGS_t *SPICONFIG;

uint8_t RecivedData[30] ={0};

void RCC_Clock_Init(void)
{
    RCC_APB2EnableClock(APB2_IOPA);
    RCC_APB2EnableClock(APB2_IOPB);
	RCC_APB2EnableClock(APB2_IOPC);
	RCC_APB2EnableClock(APB2_SPI1);
	RCC_APB2EnableClock(APB2_AFIO);
}
void Pins_Init(void)
{
	/* RED LED1 Configuration*/
	LED_Init(PORTA ,PIN2);
	/* GREEN LED Configuration*/
	LED_Init(PORTC ,PIN15);
	/*BUZZER Configuration*/
	BZR_Init();

	/* Initialize the EXTI Pin */
	GPIO_PinConfig_t EXTI_PC1 = {.Port = PORTC, .PinNum = PIN13, .Mode = INPUT,  .Input = PULLUP_PULLDOWN};

	/* Initialize the EXTI Pin */
	GPIO_u8PinInit(&EXTI_PC1);

	/* SPI Pins Configuration */
	/* MOSI Pin */
	GPIO_PinConfig_t NSS  ={ PORTA , PIN4 , INPUT , FLOATING , PULLUP_PULLDOWN  };
	GPIO_u8PinInit(&NSS);
	GPIO_PinConfig_t SCK  ={ PORTA , PIN5 , INPUT , FLOATING , PULLUP_PULLDOWN  };
	GPIO_u8PinInit(&SCK);
	GPIO_PinConfig_t MISO ={ PORTA , PIN6 , OUTPUT_SPEED_2MHz , AF_PUSH_PULL , PULLUP_PULLDOWN  };
	GPIO_u8PinInit(&MISO);
	GPIO_PinConfig_t MOSI ={ PORTA , PIN7 , INPUT , FLOATING , PULLUP_PULLDOWN  };
	GPIO_u8PinInit(&MOSI);
}
void SPI1_Init(void)
{
	/* Initialize SPI Configuration */
		static SPI_CONFIGS_t SPI1_Config =
			{
				.CRC_State = CRC_STATE_DISABLED, .Chip_Mode = CHIP_MODE_SLAVE, .Clock_Phase = CLOCK_PHASE_CAPTURE_FIRST, .Clock_Polarity = CLOCK_POLARITY_IDLE_LOW, .Frame_Size = DATA_FRAME_SIZE_8BITS, .Frame_Type = FRAME_FORMAT_MSB_FIRST, .SPI_Num = SPI_NUMBER1, .Slave_Manage_State = SLAVE_MANAGE_SW_SLAVE_ACTIVE, .Transfer_Mode = TRANSFER_MODE_FULL_DUPLEX};

		/* Initialize SPI */
		SPI_Init(&SPI1_Config);

		/* Initialize SPI1 Configuration Struct Globally */
		SPICONFIG = &SPI1_Config;
}
void EXTI13_Init(void)
{
	/* Initialize the EXTI Configuration */
	EXTI_Confg PC1_EXTIConfig = {.LINE = EXTI13, .Mode = Enable, .Trigger = RaisingEdge, .EXTI_CallBackFunc = &EXTI13_ISR};

	/* Initialize the EXTI */
	EXTI_Init(&PC1_EXTIConfig);

	/* Initialize the AFIO For EXTI13 */
	AFIO_U8SetEXTIPort(AFIO_EXTI13, AFIO_PortC);
}
void Interrupts_Init(void)
{
	NVIC_EnableIRQ(NVIC_IRQ_SPI1);
	NVIC_EnableIRQ(NVIC_IRQ_EXTI15_10);
	NVIC_EnableIRQ(NVIC_IRQ_SPI1);
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

	CLCD_voidSendNumber(RecivedData[5]);
	CLCD_voidSendNumber(RecivedData[6]);
	CLCD_voidSendData(':');

	CLCD_voidSendNumber(RecivedData[3]);
	CLCD_voidSendNumber(RecivedData[4]);
	CLCD_voidSendData(':');

	CLCD_voidSendNumber(RecivedData[1]);
	CLCD_voidSendNumber(RecivedData[2]);
	CLCD_voidSendData(':');

}
void Display_Date(void)
{
	CLCD_voidGoToXY(0, 0);

	switch (RecivedData[7])
	{
	case '1'    : CLCD_u8SendString( (char *)"SUN") ; break;
	case '2'    : CLCD_u8SendString( (char *)"MON") ; break;
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

	CLCD_voidSendNumber(RecivedData[12]);
	CLCD_voidSendNumber(RecivedData[13]);

}
void TURN_ON_LED(void)
{
	LED_On(PORTA, PIN2);
}
void Receive_withInterrupt(void)
{
	SPI_Receive_IT(SPICONFIG, RecivedData, 30, &SPI1_CallBack);
}
void CLEAR_DISPLAY(void)
{
	CLCD_ClearDisplay();
}
void _delay_1s( void)
{
	SYSTIC_delay_ms(890);
}

