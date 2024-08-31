
#include <stdint.h>
#include "Service.h"
#include "USART_interface.h"
#include "I2C_interface.h"
#include "DS1307_interface.h"
#include "Service_prv.h"
#include "SYSTIC_interface.h"
#include "GPIO_interface.h"
#include "defines.h"


extern GPIO_PIN_CFG_t PINA5 ;

extern I2C_config_t 		I2C1_SysConfig;
extern RTC_Config_t RTC_DS1307_Config;
uint8_t Alarm[5][7]={0};



uint8_t Print(uint8_t* Copy_pu8String)
{
	uint8_t Local_u8ErrorState = OK;
	if ( Copy_pu8String != NULL)
	{
		USART_voidTransmitStringSynch(USART_2 , Copy_pu8String);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState ;
	
}

uint8_t Print_Time_Date(uint8_t* Copy_pu8String)
{

	uint8_t Local_u8ErrorState = OK;
	if ( Copy_pu8String != NULL)
	{
		SendChar(Copy_pu8String[4]);
		SendChar(Copy_pu8String[5]);
		Print(":");
		SendChar(Copy_pu8String[2]);
		SendChar(Copy_pu8String[3]);
		Print(":");
		SendChar(Copy_pu8String[0]);
		SendChar(Copy_pu8String[1]);
		Print("  ");

		switch(Copy_pu8String[7])
		{
		case '1' :
			Print("Monday  ");
			break;
		case '2':
			Print("Tuesday  ");
			break;
		case '3':
			Print("Wednesday  ");
			break;
		case '4':
			Print("Thursday  ");
			break;
		case '5':
			Print("Friday  ");
			break;
		case '6':
			Print("Saturday  ");
			break;
		case '7':
			Print("Sunday  ");
			break;
		}

		SendChar(Copy_pu8String[8]);
		SendChar(Copy_pu8String[9]);
		Print("/");
		SendChar(Copy_pu8String[10]);
		SendChar(Copy_pu8String[11]);
		Print("/");
		SendChar(Copy_pu8String[12]);
		SendChar(Copy_pu8String[13]);
		Print("  ");
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState ;


	

}
uint8_t Input(uint8_t* Copy_pu8String , uint8_t Copy_u8size)
{

	uint8_t Local_u8ErrorState = OK;
	if ( Copy_pu8String != NULL)
	{
		USART_u8ReceiveBufferSynch(USART_2 , Copy_pu8String  , Copy_u8size );
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState ;

	
}


void SendChar(uint8_t Copy_u8DataChar)
{
	USART_voidTransmitCharSynch(USART_2, Copy_u8DataChar);
}
void SendCharLogin(uint8_t Copy_u8DataChar)
{
	USART_voidTransmitCharSynch(UART_4, Copy_u8DataChar);
}




uint8_t InputString(uint8_t* Copy_pu8String , uint8_t Copy_u8MaxSize)
{

	uint8_t Local_u8ErrorState = OK;

	if ( Copy_pu8String != NULL)
	{
		uint8_t LOCAL_u8LoopIterator = 0 ;

		USART_u8ReceiveCharSynch(USART_2 , &Copy_pu8String[LOCAL_u8LoopIterator]);


		while(Copy_pu8String[LOCAL_u8LoopIterator] != '\r' )
		{


			LOCAL_u8LoopIterator++;

			if (LOCAL_u8LoopIterator == Copy_u8MaxSize - 1 )
			{
				break; 
			}

			USART_u8ReceiveCharSynch(USART_2 , &Copy_pu8String[LOCAL_u8LoopIterator]);


		}

		Copy_pu8String[LOCAL_u8LoopIterator] = 0 ;
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState ;

	
}








uint8_t Send(uint8_t* Copy_pu8Buffer ,  uint8_t Copy_u8size )
{

	uint8_t Local_u8ErrorState = OK;
	if ( Copy_pu8Buffer != NULL)
	{
		USART_voidTransmitBufferSynch( USART_2 ,  Copy_pu8Buffer  ,  Copy_u8size );
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState ;
	

}
uint8_t SendOUT(uint8_t* Copy_pu8Buffer ,  uint8_t Copy_u8size )
{
	uint8_t Local_u8ErrorState = OK;
	if ( Copy_pu8Buffer != NULL)
	{
		USART_voidTransmitBufferSynch( UART_4 ,  Copy_pu8Buffer  ,  Copy_u8size );
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState ;
	
}
































/*


**********************************************************
							Yousef
**********************************************************



*/











void SRV_SetTimeNDate(void)
{

	uint8_t Local_u8TimeNDate[17];

	Print ( (uint8_t*)"\r\n Set Time and Date for the first time: ");
	Print ( (uint8_t*)"\r\n [1mHH:MM:SS DAY DD/MM/YY Format(0 for 12h, 1 for 24h)\r\n");
	//Hours
	ReadCurrentDnTFromUser(Local_u8TimeNDate);

	RTC_DS1307_Config.SECONDS   = StringToHex(Local_u8TimeNDate[5], Local_u8TimeNDate[4]);
	RTC_DS1307_Config.MINUTES   = StringToHex(Local_u8TimeNDate[3], Local_u8TimeNDate[2]);
	RTC_DS1307_Config.HOURS     = StringToHex(Local_u8TimeNDate[1], Local_u8TimeNDate[0]);
	RTC_DS1307_Config.WEEK_DAY  = DayOfWeekToNumber(&Local_u8TimeNDate[6]);
	RTC_DS1307_Config.DAY		= StringToHex(Local_u8TimeNDate[10], Local_u8TimeNDate[9]);
	RTC_DS1307_Config.MONTH  	= StringToHex(Local_u8TimeNDate[12], Local_u8TimeNDate[11]);
	RTC_DS1307_Config.YEAR  	= StringToHex(Local_u8TimeNDate[14], Local_u8TimeNDate[13]);

	RTC_DS1307_Config.TIME_FORMAT = Local_u8TimeNDate[15];

	RTC_DS1307_Config.AM_PM_NOTATION = Local_u8TimeNDate[16];

	RTC_SetTimeDate_(&I2C1_SysConfig,&RTC_DS1307_Config , 0);

}

void SRV_ShowTimeNDate(void)
{
	static uint8_t local_u8TimeNDate[RECEIVED_RTC_DATA_NUMBER]={0};
	static uint8_t Local_u8StringBridge[14]={0};
	uint8_t Local_u8Iterator;
	RTC_ReadTimeDate(&I2C1_SysConfig, &RTC_DS1307_Config, local_u8TimeNDate);

	local_u8TimeNDate[2] &=~ (0x60);

	for(Local_u8Iterator=0;Local_u8Iterator <= RECEIVED_RTC_DATA_NUMBER;Local_u8Iterator++)
	{
		//local_u8TimeNDate[Local_u8Iterator] = BCDToDecimal(local_u8TimeNDate[Local_u8Iterator]);
		HexToString(local_u8TimeNDate[Local_u8Iterator],&Local_u8StringBridge[Local_u8Iterator*2] );
	}
	Print (  (uint8_t*)"\r\n Time and Date:  ");
	//Send( Local_u8StringBridge ,14);
	SendOUT(Local_u8StringBridge ,14);
	Print_Time_Date(Local_u8StringBridge);
}

void SRV_SetAlarm(uint8_t copy_u8AlarmNumber)
{
	uint8_t Local_u8Station[17];

	Print ( (uint8_t*)"\r\n Set Time and Date: ");
	Print ( (uint8_t*)"\r\n [1mHH:MM:SS DAY DD/MM/YY Format(0 for 12h, 1 for 24h)\r\n");

	ReadCurrentDnTFromUser(Local_u8Station);

	Alarm[copy_u8AlarmNumber][0]   = StringToHex(Local_u8Station[1], Local_u8Station[0]);
	Alarm[copy_u8AlarmNumber][1]   = StringToHex(Local_u8Station[3], Local_u8Station[2]);
	Alarm[copy_u8AlarmNumber][2]   = StringToHex(Local_u8Station[5], Local_u8Station[4]);
	Alarm[copy_u8AlarmNumber][3]   = DayOfWeekToNumber(&Local_u8Station[6]);
	Alarm[copy_u8AlarmNumber][4]   = StringToHex(Local_u8Station[10], Local_u8Station[9]);
	Alarm[copy_u8AlarmNumber][5]   = StringToHex(Local_u8Station[12], Local_u8Station[11]);
	Alarm[copy_u8AlarmNumber][6]   = StringToHex(Local_u8Station[14], Local_u8Station[13]);

	SYSTIC_delay_ms_IT(1000);
}

static uint8_t StringToHex(uint8_t Arg1,uint8_t Arg2)
{
	uint8_t Local_u8Hex;
	Local_u8Hex = ((Arg1 - 48) | ((Arg2 - 48) << 4));
	return Local_u8Hex;
}

static uint8_t DayOfWeekToNumber(uint8_t* copy_u8Day)
{
	uint8_t Local_u8DayNumber=0;

	if((copy_u8Day[1] == 'O') || (copy_u8Day[1]=='o')){
		//M'O'NDAY
		Local_u8DayNumber=MONDAY;
	}
	else if((copy_u8Day[1] == 'U') || (copy_u8Day[1]=='u')){

		if((copy_u8Day[0] == 'T') || (copy_u8Day[0]=='t')){
			//T'U'SDAY
			Local_u8DayNumber=TUESDAY;
		}else
		{//S'U'NDAY
			Local_u8DayNumber=SUNDAY;
		}
	}
	else if((copy_u8Day[1] == 'E') || (copy_u8Day[1]=='e')){
		//T'H'URSDAY
		Local_u8DayNumber=WEDNESDAY;
	}
	else if((copy_u8Day[1] == 'H') || (copy_u8Day[1]=='h')){
		//T'H'URSDAY
		Local_u8DayNumber=THURSDAY;
	}
	else if((copy_u8Day[1] == 'R') || (copy_u8Day[1]=='r')){
		//F'R'IDAY
		Local_u8DayNumber=FRIDAY;
	}
	else if((copy_u8Day[1] == 'A') || (copy_u8Day[1]=='a')){
		//S'A'TURDAY
		Local_u8DayNumber=SATURDAY;
	}

	return Local_u8DayNumber;
}

static void ReadCurrentDnTFromUser(uint8_t* copy_u8array)
{
	Input( &copy_u8array[0] , 1);
	Input( &copy_u8array[1] , 1);
	SendChar(':');
	//Min
	Input( &copy_u8array[2] ,1);
	Input( &copy_u8array[3] , 1);
	SendChar( ':');
	//sec
	Input( &copy_u8array[4] , 1);
	Input( &copy_u8array[5] , 1);
	SendChar( ' ');

	//Day
	Input( &copy_u8array[6] , 1);
	Input( &copy_u8array[7] , 1);
	Input( &copy_u8array[8] , 1);
	SendChar( ' ');

	//Date
	Input( &copy_u8array[9] , 1);
	Input( &copy_u8array[10] , 1);
	SendChar( '/');
	//Month
	Input( &copy_u8array[11] , 1);
	Input( &copy_u8array[12] , 1);
	SendChar( '/');
	//Year
	Input( &copy_u8array[13] , 1);
	Input( &copy_u8array[14] , 1);
	SendChar( ' ');
	Input( &copy_u8array[15] , 1);

	if(copy_u8array[15] == '0')
	{
		Print((uint8_t*)" AM or PM ?  ");
		Input( &copy_u8array[16] , 1);
	}
}


void SysTick_Handler(void)
{
	uint8_t Local_u8Index1,Local_u8Index2;
	uint8_t Local_u8Validate=0;
	uint8_t Local_u8CurrentTD[7]={0};
	uint8_t Local_u8StringBridge[14]={0};
	uint8_t Local_u8Iterator;

	Local_u8CurrentTD[2] &=~ (0x60);
	


	RTC_ReadTimeDate(&I2C1_SysConfig, &RTC_DS1307_Config, Local_u8CurrentTD);
	for(Local_u8Iterator=0;Local_u8Iterator <= RECEIVED_RTC_DATA_NUMBER;Local_u8Iterator++)
		{
			//local_u8TimeNDate[Local_u8Iterator] = BCDToDecimal(local_u8TimeNDate[Local_u8Iterator]);
			HexToString(Local_u8CurrentTD[Local_u8Iterator],&Local_u8StringBridge[Local_u8Iterator*2] );
		}
		SendOUT(Local_u8StringBridge ,14);

	for(Local_u8Index1=0 ; Local_u8Index1<5 ; Local_u8Index1++)
	{
		for(Local_u8Index2=0 ; Local_u8Index2<7 ; Local_u8Index2++)
		{
			if(Alarm[Local_u8Index1][Local_u8Index2] != Local_u8CurrentTD[Local_u8Index2])
			{
				Local_u8Validate=0;
				break;
			}
			else
			{
				Local_u8Validate++;
			}
			if(Local_u8Validate == 7)
			{
				SendOUT(Local_u8StringBridge ,14);
				Print( (uint8_t*)"\r\n ALARM NOTIFICATION   ");
				GPIO_u8SetPinValue(PORTA, PIN5 , LOW);
				SYSTIC_delay_ms(500);
				GPIO_u8SetPinValue(PORTA, PIN5 , HIGH);
			}
		}
	}
	SYSTIC_delay_ms_IT(500);

}

static void HexToString(uint8_t copy_u8HexVal, uint8_t* copy_u8buffer)
{

	copy_u8buffer[0] = (copy_u8HexVal >> 4) + '0';
	copy_u8buffer[1] = (copy_u8HexVal & 0x0F) + '0';

}

