
#include <stdint.h>
#include "Service.h"
#include "USART_interface.h"




void print(uint8_t* Copy_pu8String)
{
    USART_voidTransmitStringSynch(USART_2 , Copy_pu8String);
}

void Input(uint8_t* Copy_pu8String , uint8_t Copy_u8size)
{
    USART_u8ReceiveBufferSynch(USART_2 , Copy_pu8String  , Copy_u8size );
}
