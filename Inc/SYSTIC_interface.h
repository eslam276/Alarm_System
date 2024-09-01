/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: SYSTIC_interface.h	*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#ifndef SYSTIC_INTERFACE_H_
#define SYSTIC_INTERFACE_H_

#define AHB_CLOCK           8u   /* IN MHz */


uint8_t SYSTIC_delay_ms(uint32_t time);
uint8_t SYSTIC_delay_us(uint32_t time);



#endif /* SYSTIC_INTERFACE_H_ */
