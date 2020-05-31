################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/COMM/COMM.c \
../BSW/COMM/COMM_lcfg.c 

OBJS += \
./BSW/COMM/COMM.o \
./BSW/COMM/COMM_lcfg.o 

C_DEPS += \
./BSW/COMM/COMM.d \
./BSW/COMM/COMM_lcfg.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/COMM/%.o: ../BSW/COMM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


