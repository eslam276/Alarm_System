/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: SYSTIC_program.c		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#include <stdint.h>
#include "SYSTIC_interface.h"
#include "stm32f103xx.h"
#include "ErrType.h"
#include "BIT_MATH.h"


uint8_t SYSTIC_delay_ms(uint32_t time)
{
    uint8_t Local_u8ErrorState = OK ;
    uint32_t Local_u32Value =(time * 1000 *AHB_CLOCK /8);
    /*check if the value > the register available bits*/
    if(Local_u32Value > 0xffffff)
    {
    	Local_u32Value = 0xffffff ;
    }
    /*Select the SYSTIC CLOCK to the processor clock source AHB /8 */
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_CLKSOURCE);
    /*Reset the count flag*/
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_COUNTFLAG);
    /* Clear the value in the SysTick reload value register */
    SYSTIC->STK_LOAD &= 0b11111111<<24;
    /*set the value in the SysTick reload value register */
    SYSTIC->STK_LOAD |=Local_u32Value;
    /* Clear the VAL Register to load the start of the down counter from the LOAD register */
    SYSTIC->STK_VAL &=0b11111111<<24;
    /*Enable SysTick*/
    SET_BIT(SYSTIC->STK_CTRL,STK_CTRL_ENABLE);
    /*Waiting flag */
    while((GET_BIT(SYSTIC->STK_CTRL,STK_CTRL_COUNTFLAG))==0)
    {
    	/*Code*/
    }

    /*disable SysTick*/
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_ENABLE);

    return Local_u8ErrorState;

}
uint8_t SYSTIC_delay_us(uint32_t time)
{
    uint8_t Local_u8ErrorState = OK ;
    uint32_t Local_u32Value =(time * AHB_CLOCK /8);
    /*check if the value > the register available bits*/
    if(Local_u32Value > 0xffffff)
    {
    	Local_u32Value = 0xffffff ;
    }
    /*Select the SYSTIC CLOCK to the processor clock source AHB /8 */
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_CLKSOURCE);
    /*Reset the count flag*/
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_COUNTFLAG);
    /* Clear the value in the SysTick reload value register */
    SYSTIC->STK_LOAD &= 0b11111111<<24;
    /*set the value in the SysTick reload value register */
    SYSTIC->STK_LOAD |=Local_u32Value;
    /* Clear the VAL Register to load the start of the down counter from the LOAD register */
    SYSTIC->STK_VAL &=0b11111111<<24;
    /*Enable SysTick*/
    SET_BIT(SYSTIC->STK_CTRL,STK_CTRL_ENABLE);
    /*Waiting flag */
    while((GET_BIT(SYSTIC->STK_CTRL,STK_CTRL_COUNTFLAG))==0)
    {
    	/*Code*/
    }

    /*disable SysTick*/
    CLR_BIT(SYSTIC->STK_CTRL,STK_CTRL_ENABLE);

    return Local_u8ErrorState;

}
