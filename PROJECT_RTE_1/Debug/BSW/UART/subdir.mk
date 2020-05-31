################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/UART/UART.c \
../BSW/UART/UART_lcfg.c 

OBJS += \
./BSW/UART/UART.o \
./BSW/UART/UART_lcfg.o 

C_DEPS += \
./BSW/UART/UART.d \
./BSW/UART/UART_lcfg.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/UART/%.o: ../BSW/UART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


