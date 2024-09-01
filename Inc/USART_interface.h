/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: USART_interface.h		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "STD_TYPES.h"
/* Defining Macros */

/* Macros for Word Length */
#define USART_U8_8_BIT_WORD					0
#define USART_U8_9_BIT_WORD					1

/* Macros for Parity Configuration */
#define USART_U8_PARITY_DISABLED			0
#define USART_U8_PARITY_ENABLED				1

#define USART_U8_EVEN_PARITY				0
#define USART_U8_ODD_PARITY					1

/* Macros for Parity Error Detection */
#define USART_U8_PE_DISABLED				0
#define USART_U8_PE_ENABLED					1

/* USART Configuration Options */
typedef enum {
    USART_WORD_LENGTH_8BIT = 0,
    USART_WORD_LENGTH_9BIT = 1
} USART_WordLength_t;

typedef enum {
    USART_PARITY_DISABLED = 0,
    USART_PARITY_ENABLED = 1
} USART_ParityEnable_t;

typedef enum {
    USART_PARITY_EVEN = 0,
    USART_PARITY_ODD = 1
} USART_ParityType_t;

typedef enum {
    USART_PARITY_ERROR_DISABLED = 0,
    USART_PARITY_ERROR_ENABLED = 1
} USART_ParityErrorEnable_t;


/* Function Prototypes */

/**
 * @brief Initialize USART1 with default settings.
 */
void MUSART1_voidInit(void);

/**
 * @brief Transmit an array of data via USART1.
 * @param data: Pointer to the data array to be transmitted.
 * @param length: Length of the data array.
 */
 void MUSART1_voidTransmit(const char *arr);
//void MUSART1_voidTransmit(const u8 *data, u8 length);
/**
 * @brief Receive a single byte of data from USART1.
 * @return Received byte of data.
 */
 u8 MUSART1_u8Receive(void);

#endif /* USART_INTERFACE_H */
