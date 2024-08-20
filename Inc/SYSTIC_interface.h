#ifndef SYSTIC_INTERFACE_H
#define SYSTIC_INTERFACE_H


#include <stdint.h>


#define AHB_CLOCK           16u   /* IN MHz */


uint8_t SYSTIC_delay_ms(uint32_t time);
uint8_t SYSTIC_delay_us(uint32_t time);
void SYSTIC_delay_ms_IT(uint32_t time);












#endif
