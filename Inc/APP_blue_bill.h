/*
 * APP_blue_bill.h
 *
 *  Created on: Aug 9, 2024
 *      Author: user
 */

#ifndef APP_BLUE_BILL_H_
#define APP_BLUE_BILL_H_

typedef enum
{
	NO_RECEIVE = 0,
	RED_LED_RECEIVED = 1,
	GREEN_LED_RECEIVED = 2 ,
	ALARM_RECEIVED = 3,
	DISPLAY_RECEIVED = 4

} RECEIVING_VAL_t;

typedef enum
{
	RED_LED_CODE = 1 , DISPLAY_CODE = 4 , GREEN_LED_CODE = 2 , ALARMCODE = 3

} RECEIVE_CODES_t;

void RCC_Clock_Init(void);
void Pins_Init(void);
void SPI1_Init(void);
void EXTI13_Init(void);
void Interrupts_Init(void);
void DisplayAlarmInfo(void);
void Display_Time(void);
void Display_Date(void);
void TURN_ON_LED(void);
void Receive_withInterrupt(void);
void CLEAR_DISPLAY(void);
void _delay_1s( void );
void SPI1_CallBack(void);
void EXTI13_ISR();

#endif /* APP_BLUE_BILL_H_ */
