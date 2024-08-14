#include "stdint.h"
#include "APP.h"
#include "Service.h"
#include "I2C_interface.h"
#include "DS1307_interface.h"



I2C_config_t 		I2C1_SysConfig;
RTC_Config_t RTC_DS1307_Config;


static uint8_t Global_u8Alarms[NUM_OF_ALARMS][ALARM_NAME_LEGTH] = { "Alarm 1" , "Alarm 2" , "Alarm 3" ,"Alarm 4" , "Alarm 5"};


static void Display_Time_And_Date(void);
static void Set_Time_And_Date(void);
static void Set_Alarm(void);
static void Display_Alarms(void);





void APP_voidInit(void)
{

	 RCC_AHB1EnableClk(AHB1_GPIOA);
	 RCC_APB1Enable(APB1_USART2);
	 RCC_APB1Enable(APB1_I2C1);


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

	 GPIO_u8PinInit(&GPIO_SDA);
	 GPIO_u8PinInit(&GPIO_SCL);


	 USART_u8Init(&UART2);
	 I2C_Init(&I2C1_SysConfig);




}




void APP_voidLogin(void)
{ 
	uint8_t Local_u8Check = LOGIN_IsValid() ;

	if (Local_u8Check == VALID)
	{
		Print("\r\n\r\n Welcome Eslam .................");
		/* turn on green LED on the kit */
	}
	else if (Local_u8Check == INVALID)
	{

		Print("\r\n\r\n The System is closed :(  ");
		while (1)
		{
			/* code */
			/* turn on red LED on the kit */
		}
		
	}
	
	
	
}


void APP_voidMenu(void)
{
	
	uint8_t Local_u8Number ;

	
	Print("\r\n\r\n Menu : ");
	Print("\r\n\r\n 1) Display time and date ");
	Print("\r\n 2) Set time and date ");
	Print("\r\n 3) Set Alarm ");
	Print("\r\n 4) Display all Alarms ");
	Print("\r\n 5) Exit \r\n");

	Input(&Local_u8Number , 1);

	while (Local_u8Number < '1' || Local_u8Number > '5')
	{
		Print("\r\n Please enter a valid number ... ");
		Input(&Local_u8Number , 1);
	}

	switch (Local_u8Number)
	{
		case '1' :
			Display_Time_And_Date();
			break;

		case '2' :
			Set_Time_And_Date();
			break;

		case '3' :
			Set_Alarm();
			break;

		case '4' :
			Display_Alarms();
			break;

		case '5' :
			while (1)
			{
				/* Do nothing  */
			}
			
			break;
		
		default:
			break;
	}
	


}








 void Display_Time_And_Date(void)
{

	Print("\r\n Display function...");

}


 void Set_Time_And_Date(void)
{

	Print("\r\n Set time and date  function...");

}


 void Set_Alarm(void)
{
	uint8_t Local_u8AlarmNumber ; 


	Print("\r\n\r\n please Enter the alarm number from 1 to 5 : ");
	Input(&Local_u8AlarmNumber,1);

	while (Local_u8AlarmNumber < '1' || Local_u8AlarmNumber > '5')
	{
		Print("\r\n Please enter a valid number ... ");
		Input(&Local_u8AlarmNumber , 1);
	}


	Local_u8AlarmNumber  = Local_u8AlarmNumber - 48 ;

	Print("\r\n\r\n please Enter the alarm Name : ");
	InputString( &Global_u8Alarms[Local_u8AlarmNumber - 1] , ALARM_NAME_LEGTH);

	

}


 void Display_Alarms(void)
 {
	uint8_t LOCAL_u8LoopIterator ;

	Print("\r\n");

	for(LOCAL_u8LoopIterator = 0 ; LOCAL_u8LoopIterator < NUM_OF_ALARMS  ; LOCAL_u8LoopIterator++)
	{
		Print("\r\n");
		SendChar(LOCAL_u8LoopIterator + 1 + 48 );
		Print(") ");
		Print(&Global_u8Alarms[LOCAL_u8LoopIterator]);
	}
	
 }













//  uint8_t RX_Data = '1' ;

// 	 	uint8_t password[5] = "1234";





// 	 	while(1)
// 	 	{

// 	 		Print("\r\n please enter the   number : ");
// 	 		Input(&RX_Data ,1);
// 	 		Print("\r\n   the   number is  : ");
// 	 		SendChar(RX_Data);

// 	 		Print("\r\n please enter the   password : ");
// 	 		Input(password , 4);
// 	 		Print("\r\n  the   password is : ");
// 	 		Print( password);




// 	 		if(RX_Data == '1')
// 	 		{
// 	 			GPIO_u8SetPinValue(PORTA, PIN5, HIGH);

// 	 		}

// 	 		else if (RX_Data == '2')
// 	 		{
// 	 			GPIO_u8SetPinValue(PORTA, PIN5, LOW);



// 	 		}

// 	 	//	SYSTIC_delay_ms(1000);


// 	 	}

	
