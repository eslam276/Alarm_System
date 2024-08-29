################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AFIO_Program.c \
../Src/APP_blue_bill.c \
../Src/BZR_prog.c \
../Src/CLCD_program.c \
../Src/EXTI_Program.c \
../Src/GPIO_Program.c \
../Src/LED_prog.c \
../Src/NVIC_program.c \
../Src/RCC_Program.c \
../Src/SCB_program.c \
../Src/SYSTIC_program.c \
../Src/USART_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/AFIO_Program.o \
./Src/APP_blue_bill.o \
./Src/BZR_prog.o \
./Src/CLCD_program.o \
./Src/EXTI_Program.o \
./Src/GPIO_Program.o \
./Src/LED_prog.o \
./Src/NVIC_program.o \
./Src/RCC_Program.o \
./Src/SCB_program.o \
./Src/SYSTIC_program.o \
./Src/USART_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/AFIO_Program.d \
./Src/APP_blue_bill.d \
./Src/BZR_prog.d \
./Src/CLCD_program.d \
./Src/EXTI_Program.d \
./Src/GPIO_Program.d \
./Src/LED_prog.d \
./Src/NVIC_program.d \
./Src/RCC_Program.d \
./Src/SCB_program.d \
./Src/SYSTIC_program.d \
./Src/USART_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/AFIO_Program.cyclo ./Src/AFIO_Program.d ./Src/AFIO_Program.o ./Src/AFIO_Program.su ./Src/APP_blue_bill.cyclo ./Src/APP_blue_bill.d ./Src/APP_blue_bill.o ./Src/APP_blue_bill.su ./Src/BZR_prog.cyclo ./Src/BZR_prog.d ./Src/BZR_prog.o ./Src/BZR_prog.su ./Src/CLCD_program.cyclo ./Src/CLCD_program.d ./Src/CLCD_program.o ./Src/CLCD_program.su ./Src/EXTI_Program.cyclo ./Src/EXTI_Program.d ./Src/EXTI_Program.o ./Src/EXTI_Program.su ./Src/GPIO_Program.cyclo ./Src/GPIO_Program.d ./Src/GPIO_Program.o ./Src/GPIO_Program.su ./Src/LED_prog.cyclo ./Src/LED_prog.d ./Src/LED_prog.o ./Src/LED_prog.su ./Src/NVIC_program.cyclo ./Src/NVIC_program.d ./Src/NVIC_program.o ./Src/NVIC_program.su ./Src/RCC_Program.cyclo ./Src/RCC_Program.d ./Src/RCC_Program.o ./Src/RCC_Program.su ./Src/SCB_program.cyclo ./Src/SCB_program.d ./Src/SCB_program.o ./Src/SCB_program.su ./Src/SYSTIC_program.cyclo ./Src/SYSTIC_program.d ./Src/SYSTIC_program.o ./Src/SYSTIC_program.su ./Src/USART_program.cyclo ./Src/USART_program.d ./Src/USART_program.o ./Src/USART_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

