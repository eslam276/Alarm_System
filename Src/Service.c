
#include <stdint.h>
#include "Service.h"
#include "USART_interface.h"




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
	void USART_voidTransmitBufferSynch( USART_NUM_t Copy_USARTindex , uint8_t * Copy_pu8Buffer  , uint8_t Copy_u8size );

}





