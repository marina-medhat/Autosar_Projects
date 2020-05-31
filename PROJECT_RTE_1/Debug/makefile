################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SWC/RightDoor/subdir.mk
-include SWC/LeftDoor/subdir.mk
-include SWC/DoorContact/subdir.mk
-include RTE/subdir.mk
-include BSW/UART/subdir.mk
-include BSW/Scheduler/subdir.mk
-include BSW/DIO/subdir.mk
-include BSW/COMM/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
PROJECT_RTE_1.lss \

FLASH_IMAGE += \
PROJECT_RTE_1.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: PROJECT_RTE_1.elf secondary-outputs

# Tool invocations
PROJECT_RTE_1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,PROJECT_RTE_1.map -mmcu=atmega16 -o "PROJECT_RTE_1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PROJECT_RTE_1.lss: PROJECT_RTE_1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S PROJECT_RTE_1.elf  >"PROJECT_RTE_1.lss"
	@echo 'Finished building: $@'
	@echo ' '

PROJECT_RTE_1.hex: PROJECT_RTE_1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex PROJECT_RTE_1.elf  "PROJECT_RTE_1.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: PROJECT_RTE_1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 PROJECT_RTE_1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) PROJECT_RTE_1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
