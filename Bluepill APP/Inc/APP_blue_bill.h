/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: APP_blue_bill.h		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#ifndef APP_BLUE_BILL_H_
#define APP_BLUE_BILL_H_


void RCC_Clock_Init(void);
void Pins_Init(void);
void Interrupts_Init(void);
void DisplayAlarmInfo(void);
void Display_Time(void);
void Display_Date(void);
void TURN_ON_LED(void);
void CLEAR_DISPLAY(void);
void _delay_1s( void );


#endif /* APP_BLUE_BILL_H_ */
