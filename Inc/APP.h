#ifndef APP_H_
#define APP_H_

#include "Login.h"
#include "ErrType.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTIC_interface.h"
#include "USART_interface.h"


#define NUM_OF_ALARMS      5
#define ALARM_NAME_LEGTH   30


void APP_voidInit(void);
void APP_voidLogin(void);

void APP_voidMenu(void);


#endif