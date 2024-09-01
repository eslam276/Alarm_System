/**************************************************************/
/**************************************************************/
/*********		Author: Mahmoud Hafez   	*******************/
/*********		File: stm32f103xx.h 		*******************/
/*********		Version: 1.00				*******************/
/**************************************************************/
/**************************************************************/

#ifndef STM32F103XX_H_
#define STM32F103XX_H_

/**********************************          Various Memories Base Addresses          **********************************/
#define FLASH_BASE_ADDRESS          0x08000000UL
#define SRAM_BASE_ADDRESS           0x20000000UL
/**********************************          Core Peripheral Base Addresses          **********************************/
#define SYSTIC_BASE_ADDRESS            0xE000E010UL
#define NVIC_BASE_ADDRESS              0xE000E100UL
#define SCB_ADDRESS_BASE			   0xE000E008UL
/**********************************          AHB Peripheral Base Addresses          **********************************/
#define RCC_BASE_ADDRESS 			    0x40021000UL
#define EXTI_BASE_ADDRESS        		0x40010400UL
#define AFIO_BASE_ADDRESS        		0x40010000UL
#define DMA1_ADDRESS_BASE               0x40020000UL
#define DMA2_ADDRESS_BASE               0x40020400UL

/**********************************          APB1 Peripheral Base Addresses          **********************************/
#define	USART5_BASE_ADDRESS			0x40005000UL				/*UNIVERASL SYNCH/ASYNCH RECEIVER TRANSMITTER 5*/
#define	USART4_BASE_ADDRESS			0x40004C00UL				/*UNIVERASL SYNCH/ASYNCH RECEIVER TRANSMITTER 4*/
#define	USART3_BASE_ADDRESS			0x40004800UL				/*UNIVERASL SYNCH/ASYNCH RECEIVER TRANSMITTER 3*/
#define	USART2_BASE_ADDRESS			0x40004400UL				/*UNIVERASL SYNCH/ASYNCH RECEIVER TRANSMITTER 2*/

#define SPI3_BASE_ADDRESS			0x40003C00UL				/*Serial Peripheral Interface 3*/
#define SPI2_BASE_ADDRESS			0x40003800UL	            /*Serial Peripheral Interface 2*/


/**********************************          APB2 Peripheral Base Addresses          **********************************/
#define GPIOA_BASE_ADDRESS         0x40010800UL
#define GPIOB_BASE_ADDRESS         0x40010C00UL
#define GPIOC_BASE_ADDRESS         0x40011000UL
#define GPIOD_BASE_ADDRESS         0x40011400UL
#define GPIOE_BASE_ADDRESS         0x40011800UL
#define GPIOF_BASE_ADDRESS         0x40011C00UL
#define GPIOG_BASE_ADDRESS         0x40012000UL

#define	USART1_BASE_ADDRESS			0x40013800UL				/*UNIVERASL SYNCH/ASYNCH RECEIVER TRANSMITTER 1*/
#define SPI1_BASE_ADDRESS			0x40013000UL				/*Serial Peripheral Interface 1*/

/***************RCC Register Definition Structure****************/
typedef struct{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_AHBENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RCC_APB1ENR;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	volatile uint32_t RCC_AHBRSTR;
	volatile uint32_t RCC_CFGR2;
}RCC_Reg_t;
/***************RCC Register Definition ****************/
#define RCC  ((RCC_Reg_t *)RCC_BASE_ADDRESS)

/**********************************          GPIO register definition Structure      **********************************/
typedef struct
{
	volatile uint32_t CR[2]; /*GPIO configuration registers*/
	volatile uint32_t IDR; /*GPIO input data register*/
	volatile uint32_t ODR; /*GPIO output data register*/
	volatile uint32_t BSRR; /*GPIO Bit set reset register*/
	volatile uint32_t BRR; /*GPIO Bit reset register*/
	volatile uint32_t LCKR; /*GPIO lock configuration register*/

}GPIO_RegDef_t;
/**********************************          GPIO Peripheral Defination          **********************************/
#define GPIOA                   ((GPIO_RegDef_t *)(GPIOA_BASE_ADDRESS))
#define GPIOB                   ((GPIO_RegDef_t *)(GPIOB_BASE_ADDRESS))
#define GPIOC                   ((GPIO_RegDef_t *)(GPIOC_BASE_ADDRESS))
#define GPIOD                   ((GPIO_RegDef_t *)(GPIOD_BASE_ADDRESS))
#define GPIOE                   ((GPIO_RegDef_t *)(GPIOE_BASE_ADDRESS))
#define GPIOF                   ((GPIO_RegDef_t *)(GPIOF_BASE_ADDRESS))
#define GPIOG                   ((GPIO_RegDef_t *)(GPIOG_BASE_ADDRESS))

/************************     	AFIO REGISTERS DEFINITION			************************/
typedef struct
{
	volatile uint32_t EVCR ;        /* Event control register                          */
	volatile uint32_t MAPR ;        /* SYSCFG memory remap register                    */
	volatile uint32_t EXTICR[4] ;   /*SYSCFG external interrupt configuration register */
	uint32_t Reserved1;             /* offset                                          */
	volatile uint32_t MAPR2 ;       /* AF remap and debug I/O configuration register2  */

}AFIO_RegDef_t;

#define 	AFIO            	    ((AFIO_RegDef_t *)(AFIO_BASE_ADDRESS))

/**********************************          SYSTICK register definition Structure       **********************************/
typedef struct{
	volatile uint32_t STK_CTRL;
	volatile uint32_t STK_LOAD;
	volatile uint32_t STK_VAL;
	volatile uint32_t STK_CALIB;
}SYSTIC_REG_t;

#define SYSTIC           ((SYSTIC_REG_t*)SYSTIC_BASE_ADDRESS)

#define STK_CTRL_COUNTFLAG              16u
#define STK_CTRL_CLKSOURCE              2u
#define STK_CTRL_TICKINT                1u
#define STK_CTRL_ENABLE                 0u

/**********************************          NVIC register definition Structure       **********************************/
typedef struct{
	volatile uint32_t ISER[8];
	uint32_t RESERVED0[24];
	volatile uint32_t ICER[8];
	uint32_t RESERVED1[24];
	volatile uint32_t ISPR[8];
	uint32_t RESERVED2[24];
	volatile uint32_t ICPR[8];
	uint32_t RESERVED3[24];
	volatile uint32_t IABR[8];
	uint32_t RESERVED4[56];
	volatile uint32_t IPR[240];
	 uint32_t RESERVED5[643];
	volatile uint32_t STIR;
}NVIC_RegDef_t;

#define NVIC                     ((NVIC_RegDef_t*)NVIC_BASE_ADDRESS)

/***************SCB Register Definition Structure****************/
typedef struct{

	volatile uint32_t ACTLR			;
			 uint32_t Reversed0[829];
	volatile uint32_t CPUID         ;
	volatile uint32_t ICSR          ;
	volatile uint32_t VTOR          ;
	volatile uint32_t AIRCR         ;
	volatile uint32_t SCR           ;
	volatile uint32_t CCR           ;
	volatile uint32_t SHPR1[3]      ;
	volatile uint32_t SHCRS         ;
	volatile uint32_t CFSR          ;
	volatile uint32_t MMSR          ;
	volatile uint32_t BFSR          ;
	volatile uint32_t UFSR          ;
	volatile uint32_t HFSR          ;
			 uint32_t Reversed1		;
	volatile uint32_t MMAR          ;
	volatile uint32_t BFAR          ;
	volatile uint32_t AFSR          ;

}SCB_RegDef_t;
/***************SCB Register Definition ****************/
#define SCB		((SCB_RegDef_t*)SCB_ADDRESS_BASE)

/********************    EXTI REGISTER DEFINITION STRUCTURE        ********************************/

typedef struct
{
	volatile uint32_t IMR ;       /* Interrupt mask register            */
	volatile uint32_t EMR ;       /* Event mask register                */
	volatile uint32_t RTSR ;      /* Rising trigger selection register  */
	volatile uint32_t FTSR ;      /* Falling trigger selection register */
	volatile uint32_t SWIER ;     /* Software interrupt event register  */
	volatile uint32_t PR ;        /* Pending register                   */

}EXTI_RegDef_t;

#define EXTI                      ( (EXTI_RegDef_t*)EXTI_BASE_ADDRESS )

/**********************************          SYSTICK register definition Structure       **********************************/
typedef struct{
	volatile uint32_t DMA_CCR ;
	volatile uint32_t DMA_CNDTR ;
	volatile uint32_t DMA_CPAR ;
	volatile uint32_t DMA_CMAR ;
	uint32_t DMA_RESERVED;
}DMA_ChannelReg_t;

typedef struct{
	volatile uint32_t DMA_ISR ;
	volatile uint32_t DMA_IFCR ;
    DMA_ChannelReg_t DMA_ChannelReg[8];
}DMA_RegDef_t;

#define DMA1		((DMA_RegDef_t *)DMA1_ADDRESS_BASE)
#define DMA2    	((DMA_RegDef_t *)DMA2_ADDRESS_BASE)


/***************USART Register Definition Structure****************/
typedef struct{

	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;

}USART_Reg_t;
/***************USART Register Definition ****************/
#define	USART1	((USART_Reg_t*)USART1_BASE_ADDRESS)
#define	USART2	((USART_Reg_t*)USART2_BASE_ADDRESS)
#define	USART3	((USART_Reg_t*)USART3_BASE_ADDRESS)
#define	USART4	((USART_Reg_t*)USART4_BASE_ADDRESS)
#define	USART5	((USART_Reg_t*)USART5_BASE_ADDRESS)

/***************SPI Register Definition Structure****************/
typedef struct{

	volatile uint32_t SPI_CR1;
	volatile uint32_t SPI_CR2;
	volatile uint32_t SPI_SR;
	volatile uint32_t SPI_DR;
	volatile uint32_t SPI_CRCPR;
	volatile uint32_t SPI_RXCRCR;
	volatile uint32_t SPI_TXCRCR;
	volatile uint32_t SPI_I2SCFGR;
	volatile uint32_t SPI_I2SPR;

}SPI_Reg_t;
/***************SPI Register Definition ****************/
#define SPI1		((SPI_Reg_t *) SPI1_BASE_ADDRESS)
#define SPI2		((SPI_Reg_t *) SPI2_BASE_ADDRESS)
#define SPI3		((SPI_Reg_t *) SPI3_BASE_ADDRESS)


#endif /* STM32F103XX_H_ */
