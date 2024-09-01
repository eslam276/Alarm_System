/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: USART_private.h		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

// Define base address for USART registers
#define USART1_BASE_ADDR  0x40013800

// USART Register structure definition
typedef struct {
    volatile u32 SR;    // Status Register
    volatile u32 DR;    // Data Register
    volatile u32 BRR;   // Baud Rate Register
    volatile u32 CR[3]; // Control Registers 1, 2, 3
    volatile u32 GTPR;  // Guard Time and Prescaler Register
} USART_Register;

// USART1 Register instance
#define 	USART1 		((USART_Register *) USART1_BASE_ADDR)

#endif
