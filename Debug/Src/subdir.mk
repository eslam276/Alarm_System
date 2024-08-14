################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/APP.c \
../Src/DS1307_prog.c \
../Src/GPIO_program.c \
../Src/I2C_prog.c \
../Src/Login.c \
../Src/RCC_prog.c \
../Src/SYSTIC_program.c \
../Src/Service.c \
../Src/USART_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/APP.o \
./Src/DS1307_prog.o \
./Src/GPIO_program.o \
./Src/I2C_prog.o \
./Src/Login.o \
./Src/RCC_prog.o \
./Src/SYSTIC_program.o \
./Src/Service.o \
./Src/USART_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/APP.d \
./Src/DS1307_prog.d \
./Src/GPIO_program.d \
./Src/I2C_prog.d \
./Src/Login.d \
./Src/RCC_prog.d \
./Src/SYSTIC_program.d \
./Src/Service.d \
./Src/USART_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/APP.cyclo ./Src/APP.d ./Src/APP.o ./Src/APP.su ./Src/DS1307_prog.cyclo ./Src/DS1307_prog.d ./Src/DS1307_prog.o ./Src/DS1307_prog.su ./Src/GPIO_program.cyclo ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/GPIO_program.su ./Src/I2C_prog.cyclo ./Src/I2C_prog.d ./Src/I2C_prog.o ./Src/I2C_prog.su ./Src/Login.cyclo ./Src/Login.d ./Src/Login.o ./Src/Login.su ./Src/RCC_prog.cyclo ./Src/RCC_prog.d ./Src/RCC_prog.o ./Src/RCC_prog.su ./Src/SYSTIC_program.cyclo ./Src/SYSTIC_program.d ./Src/SYSTIC_program.o ./Src/SYSTIC_program.su ./Src/Service.cyclo ./Src/Service.d ./Src/Service.o ./Src/Service.su ./Src/USART_program.cyclo ./Src/USART_program.d ./Src/USART_program.o ./Src/USART_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

