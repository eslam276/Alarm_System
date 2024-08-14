
#ifndef SERVICE_H_
#define SERVICE_H_

#include <stdint.h>





void SRV_SetTimeNDate(void);
void SRV_ShowTimeNDate(void);
void SRV_SetAlarm(uint8_t copy_u8AlarmNumber);


void Print(uint8_t* Copy_pu8String);

void Input(uint8_t* Copy_pu8String , uint8_t Copy_u8size);
void Send(uint8_t* Copy_pu8Buffer ,  uint8_t Copy_u8size );

void SendChar(uint8_t Copy_u8DataChar);

void InputString(uint8_t* Copy_pu8String , uint8_t Copy_u8MaxSize);




#endif
