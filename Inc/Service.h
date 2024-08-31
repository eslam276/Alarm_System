
#ifndef SERVICE_H_
#define SERVICE_H_

#include <stdint.h>


// uint8_t Local_u8ErrorStatu = OK;
// uint8_t
// if(Copy_stClkCfg != NULL)
// Local_u8ErrorStatu = NULL_PTR_ERR;




void SRV_SetTimeNDate(void);
void SRV_ShowTimeNDate(void);
void SRV_SetAlarm(uint8_t copy_u8AlarmNumber);


uint8_t Print(uint8_t* Copy_pu8String);
uint8_t Print_Time_Date(uint8_t* Copy_pu8String);

uint8_t Input(uint8_t* Copy_pu8String , uint8_t Copy_u8size);
uint8_t Send(uint8_t* Copy_pu8Buffer ,  uint8_t Copy_u8size );
uint8_t SendOUT(uint8_t* Copy_pu8Buffer ,  uint8_t Copy_u8size );


void SendChar(uint8_t Copy_u8DataChar);
void SendCharLogin(uint8_t Copy_u8DataChar);


uint8_t InputString(uint8_t* Copy_pu8String , uint8_t Copy_u8MaxSize);




#endif
