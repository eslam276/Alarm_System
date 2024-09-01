/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: USART_program.c		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

static void USART1_SetBaudRate(u32 clock, u32 baudRate)
{
    // Calculate the BRR value
    u32 brr_value = (clock / (16 * baudRate));
    u32 fraction = (clock % (16 * baudRate)) * 16 / (16 * baudRate);
    
    // Set the BRR register
    USART1->BRR = (brr_value << 4) | (fraction & 0x0F);
}
void MUSART1_voidInit(void)
{
	/*	baud rate = 9600		*/
	// USART1 -> BRR = 0x341;
	USART1_SetBaudRate(8000000,9600);

	SET_BIT((USART1-> CR[0]), 3);
	SET_BIT((USART1-> CR[0]), 2);
	SET_BIT((USART1-> CR[0]), 13);
	
	USART1 -> SR = 0;
}

void MUSART1_voidTransmit(const char *arr)
{
	u8 i = 0;
	while(arr[i] != '\0'){
		USART1 -> DR = arr[i];
		while((GET_BIT((USART1 -> SR), 6)) == 0);
		i++;
	}
	
}

u8 MUSART1_u8Receive(void)
{
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((USART1 -> SR), 5)) == 0);
	Loc_u8ReceivedData = USART1 -> DR;
	return (Loc_u8ReceivedData);
}




















