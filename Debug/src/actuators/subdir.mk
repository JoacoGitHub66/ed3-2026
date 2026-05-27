################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/actuators/fan.c 

C_DEPS += \
./src/actuators/fan.d 

OBJS += \
./src/actuators/fan.o 


# Each subdirectory must supply rules for building sources it contributes
src/actuators/%.o: ../src/actuators/%.c src/actuators/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSISv2p00_LPC17xx -D__LPC17XX__ -D__REDLIB__ -I"/home/joaquin/Documents/MCUXpresso_25.6.136/workspace/CMSISv2p00_LPC17xx/inc" -I/home/joaquin/Documents/MCUXpresso_25.6.136/workspace/CMSISv2p00_LPC17xx/Drivers/inc -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-actuators

clean-src-2f-actuators:
	-$(RM) ./src/actuators/fan.d ./src/actuators/fan.o

.PHONY: clean-src-2f-actuators

