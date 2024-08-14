
#include <stdint.h>
#include "Service.h"
#include "USART_interface.h"
#include "I2C_interface.h"
#include "DS1307_interface.h"



extern I2C_config_t 		I2C1_SysConfig;
extern RTC_Config_t RTC_DS1307_Config;
uint8_t Alarm[5][7]={0};



void Print(uint8_t* Copy_pu8String)
{
    USART_voidTransmitStringSynch(USART_2 , Copy_pu8String);
}

void Input(uint8_t* Copy_pu8String , uint8_t Copy_u8size)
{
    USART_u8ReceiveBufferSynch(USART_2 , Copy_pu8String  , Copy_u8size );
}


void SendChar(uint8_t Copy_u8DataChar)
{
    USART_voidTransmitCharSynch(USART_2, Copy_u8DataChar);
}



void InputString(uint8_t* Copy_pu8String , uint8_t Copy_u8MaxSize)
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








void Send(uint8_t* Copy_pu8Buffer ,  uint8_t Copy_u8size )
{
	 USART_voidTransmitBufferSynch( USART_2 ,  Copy_pu8Buffer  ,  Copy_u8size );

}





