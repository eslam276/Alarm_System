#include "stdint.h"
#include "APP.h"
#include "Service.h"
#include "I2C_interface.h"
#include "DS1307_interface.h"



I2C_config_t 		I2C1_SysConfig;
RTC_Config_t RTC_DS1307_Config;

GPIO_PIN_CFG_t PINA5 =
	{
			.Port = PORTA ,
			.PinNum = PIN5 ,
			.Mode = OUTPUT ,
			.OutputType = PUSH_PULL

	};




void UART_init(void);





void APP_voidInit(void)
{

	 RCC_AHB1EnableClk(AHB1_GPIOA);
	 RCC_AHB1EnableClk(AHB1_GPIOB);

	 RCC_APB1Enable(APB1_USART2);
	 RCC_APB1Enable(APB1_UART4);
	 RCC_APB1Enable(APB1_I2C1);


	




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


	USART_Cnfg_t UART4 =
	{
			.USART_Num = UART_4 ,
			.Parity = PARITY_DISABLED ,
			.Word = EIGHT ,
			.OverSampling = OVER8 ,
			.Mode = RX_TX ,
			.RX_INT = RXINT_DISABLE


	};
	GPIO_PIN_CFG_t UART4_TX_PIN = {
			.AltFunc=AF8, .Mode=ALTERNATIVE_FUNCTION, .OutputType=PUSH_PULL,
			.PinNum=PIN0, .Port=PORTA
	};

	GPIO_PIN_CFG_t UART4_RX_PIN = {
			.AltFunc=AF8, .Mode=ALTERNATIVE_FUNCTION, .OutputType=PUSH_PULL,
			.PinNum=PIN1, .Port=PORTA
	};


	GPIO_PIN_CFG_t GPIO_SDA =
	{
			.Port = PORTB, .PinNum = PIN7, .Mode  = ALTERNATIVE_FUNCTION, .OutputType = OPEN_DRAIN,
			.AltFunc  = AF4, .PullType = PULL_UP, .Speed  = HIGH_
	};
	GPIO_PIN_CFG_t GPIO_SCL=
	{
			.Port     = PORTB,	.PinNum        = PIN6,	.Mode          = ALTERNATIVE_FUNCTION,
			.OutputType = OPEN_DRAIN, .AltFunc  = AF4, .PullType = PULL_UP, .Speed   = HIGH_
	};


	I2C1_SysConfig.I2C_NUMBER 				  = I2C_1					;
	I2C1_SysConfig.I2C_ACKNOWLEDGE 		      = I2C_ACK					;
	I2C1_SysConfig.I2C_SPEED_MODE 			  = SM_MODE					;
	I2C1_SysConfig.I2C_STRETCHING 			  = NO_STRETCH				;
	I2C1_SysConfig.I2C_SCL_FREQ 			  = 100						;
	I2C1_SysConfig.I2C_FREQ 				  = 16						;
	I2C1_SysConfig.I2C_PEC 				      = NO_PEC					;
	I2C1_SysConfig.I2C_ADD_MODE 			  = _7_BIT_SLAVE_ADD		;
	I2C1_SysConfig.I2C_OWN_ADD 			      = 0						;

	

		






	 GPIO_u8PinInit(&PINA5);

	 GPIO_u8PinInit(&USART_TX_PIN);
	 GPIO_u8PinInit(&USART_RX_PIN);

	 GPIO_u8PinInit(&GPIO_SDA);
	 GPIO_u8PinInit(&GPIO_SCL);

	 GPIO_u8PinInit(&UART4_TX_PIN);
	 GPIO_u8PinInit(&UART4_RX_PIN);




	USART_u8Init(&UART4);
	USART_u8Init(&UART2);
	I2C_Init(&I2C1_SysConfig);


	

}




void APP_voidLogin(void)
{ 
	uint8_t Local_u8Check = LOGIN_IsValid() ;

	if (Local_u8Check == VALID)
	{
		Print((uint8_t*)"\r\n\r\n Welcome Eslam .................");
		/* turn on green LED on the kit */
		SendCharLogin('1');
	}
	else if (Local_u8Check == INVALID)
	{

		Print((uint8_t*)"\r\n\r\n The System is closed :(  ");
		/* turn on red LED on the kit */
			SendCharLogin('2');

		while (1)
		{
			/* code */
			
		}
		
	}
	
	
	
}


void APP_voidMenu(void)
{
	
	uint8_t Local_u8Number ;

	
	Print((uint8_t*)"\r\n\r\n Menu : ");
	Print((uint8_t*)"\r\n\r\n 1) Display time and date ");
	Print((uint8_t*)"\r\n 2) Set time and date ");
	Print((uint8_t*)"\r\n 3) Set Alarm ");
	Print((uint8_t*)"\r\n 4) Exit \r\n");

	Input(&Local_u8Number , 1);

	while (Local_u8Number < '1' || Local_u8Number > '4')
	{
		Print((uint8_t*)"\r\n Please enter a valid number ... ");
		Input(&Local_u8Number , 1);
	}

	switch (Local_u8Number)
	{
		case '1' :
			SRV_ShowTimeNDate();
			break;

		case '2' :
			SRV_SetTimeNDate();
			Print((uint8_t*)"\r\nTime and Date is set successfully. ;)");
			break;

		case '3' :
			//Set_Alarm();
			uint8_t Local_u8AlarmNumber=0;
			//Read Time and Date from user
			Print( (uint8_t*)"\nWhich alarm you want to set?");
			Print( (uint8_t*)"\nAlarm 1");
			Print( (uint8_t*)"\nAlarm 2");
			Print( (uint8_t*)"\nAlarm 3");
			Print( (uint8_t*)"\nAlarm 4");
			Print( (uint8_t*)"\nAlarm 5");

			Print( (uint8_t*)"\nAlarm [");
			Input( &Local_u8AlarmNumber , 1);
			Print( (uint8_t*)"]");

			SRV_SetAlarm((Local_u8AlarmNumber-49));
			break;

		

		case '4' :
			while (1)
			{
				/* Do nothing  */
			}
			
			break;
		
		default:
			break;
	}
	


}





void APP_FirstSetUp(void)
{
	SRV_SetTimeNDate();

}











