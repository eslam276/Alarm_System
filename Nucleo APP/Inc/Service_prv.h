
#ifndef SERVICE_PRV_H_
#define SERVICE_PRV_H_

#include <stdint.h>

#define RECEIVED_RTC_DATA_NUMBER	7


/********************************************************************/
static uint8_t DayOfWeekToNumber(uint8_t* copy_u8Day);
static uint8_t StringToHex(uint8_t Arg1,uint8_t Arg2);
static void ReadCurrentDnTFromUser(uint8_t* copy_u8array);
static void HexToString(uint8_t copy_u8HexVal, uint8_t* copy_u8buffer);
/********************************************************************/
#endif /* SERVICE_PRV_H_ */
