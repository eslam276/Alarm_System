/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: GPIO_interface.h		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/***************/
/*
 * @Port_t enum
 */
typedef enum{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH
}Port_t;

/***************/
/*
 * @Pin_t enum
 */
typedef enum{
	PIN0=0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}Pin_t;

/***************/
/*
 * @Mode_t enum
 */
typedef enum{
	INPUT=0,
	OUTPUT_SPEED_10MHz,
	OUTPUT_SPEED_2MHz,
	OUTPUT_SPEED_50MHz

}Mode_t;

/***************/
/*
 * @PinVal_t enum
 */
typedef enum{
	PIN_LOW=0,
	PIN_HIGH
}PinVal_t;

/***************/
/*
 * @InputType_t enum
 */
typedef enum{
	ANALOGE =0,
	FLOATING,
	PULLUP_PULLDOWN
}InputType_t;

/***************/
/*
 * @OutputType_t enum
 */
typedef enum
{
	OUTPUT_PUSH_PULL=0,
	OUTPUT_OPENDRAIN,
	AF_PUSH_PULL,
	AF_OPENDRAIN
}OutputType_t;

/***************/
/*
 * @GPIO_PinConfig_t struct
 */
typedef struct{
	Port_t Port;
	Pin_t PinNum;
	Mode_t Mode;
	InputType_t Input;
	OutputType_t Output;
}GPIO_PinConfig_t;


uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t *PinConfig);

uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal);

uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum);

uint8_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t* PinVal);



#endif /* GPIO_INTERFACE_H_ */
