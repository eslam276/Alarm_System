#include "stdint.h"
#include "APP.h"




void APP_voidInit(void)
{

	 RCC_AHB1EnableClk(AHB1_GPIOA);
	 RCC_APB1Enable(APB1_USART2);


	 GPIO_PIN_CFG_t PINA5 =
	 {
			 .Port = PORTA ,
			 .PinNum = PIN5 ,
			 .Mode = OUTPUT ,
			 .OutputType = PUSH_PULL

	 };




	 GPIO_PIN_CFG_t USART_TX_PIN = {
			.AltFunc=AF7, .Mode=ALTERNATIVE_FUNCTION, .OutputType=PUSH_PULL,
			.PinNum=PIN2, .Port=PORTA
	};

	 GPIO_PIN_CFG_t USART_RX_PIN = {
			.AltFunc=AF7, .Mode=ALTERNATIVE_FUNCTION, .OutputType=PUSH_PULL,
			.PinNum=PIN3, .Port=PORTA
	};




		USART_Cnfg_t UART2 =
		{
			.USART_Num = USART_2 ,
			.Parity = PARITY_DISABLED ,
			.Word = EIGHT ,
			.OverSampling = OVER8 ,
			.Mode = RX_TX ,
			.RX_INT = RXINT_DISABLE


		};






	 GPIO_u8PinInit(&PINA5);

	 GPIO_u8PinInit(&USART_TX_PIN);
	 GPIO_u8PinInit(&USART_RX_PIN);
	 USART_u8Init(&UART2);




}












// uint8_t RX_Data = '1' ;

// 	uint8_t password[5] = "1234";





// 	while(1)
// 	{

// 		USART_voidTransmitStringSynch(USART_2 , "\n please enter the   number : ");
// 		USART_u8ReceiveCharSynch(USART_2, &RX_Data);
// 		USART_voidTransmitStringSynch(USART_2 , "\n   the   number is  : ");
// 		USART_voidTransmitCharSynch(USART_2 , RX_Data);

// 		USART_voidTransmitStringSynch(USART_2 , "\n please enter the   password : ");
// 		USART_u8ReceiveBufferSynch(USART_2 , password , 4);
// 		USART_voidTransmitStringSynch(USART_2 , "\n  the   password is : ");
// 		USART_voidTransmitStringSynch(USART_2 , password);




// 		if(RX_Data == '1')
// 		{
// 			GPIO_u8SetPinValue(PORTA, PIN5, HIGH);

// 		}

// 		else if (RX_Data == '2')
// 		{
// 			GPIO_u8SetPinValue(PORTA, PIN5, LOW);



// 		}

// 	//	SYSTIC_delay_ms(1000);


// 	}
