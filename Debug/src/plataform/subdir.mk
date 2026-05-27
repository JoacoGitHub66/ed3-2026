################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/plataform/adc_lpc1769.c \
../src/plataform/dac_lpc1769.c \
../src/plataform/dma_lpc1769.c \
../src/plataform/timer_lpc1769.c \
../src/plataform/uart_lpc1769.c 

C_DEPS += \
./src/plataform/adc_lpc1769.d \
./src/plataform/dac_lpc1769.d \
./src/plataform/dma_lpc1769.d \
./src/plataform/timer_lpc1769.d \
./src/plataform/uart_lpc1769.d 

OBJS += \
./src/plataform/adc_lpc1769.o \
./src/plataform/dac_lpc1769.o \
./src/plataform/dma_lpc1769.o \
./src/plataform/timer_lpc1769.o \
./src/plataform/uart_lpc1769.o 


# Each subdirectory must supply rules for building sources it contributes
src/plataform/%.o: ../src/plataform/%.c src/plataform/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSISv2p00_LPC17xx -D__LPC17XX__ -D__REDLIB__ -I"/home/joaquin/Documents/MCUXpresso_25.6.136/workspace/CMSISv2p00_LPC17xx/inc" -I/home/joaquin/Documents/MCUXpresso_25.6.136/workspace/CMSISv2p00_LPC17xx/Drivers/inc -O0 -fno-common -g3 -gdwarf-4 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-plataform

clean-src-2f-plataform:
	-$(RM) ./src/plataform/adc_lpc1769.d ./src/plataform/adc_lpc1769.o ./src/plataform/dac_lpc1769.d ./src/plataform/dac_lpc1769.o ./src/plataform/dma_lpc1769.d ./src/plataform/dma_lpc1769.o ./src/plataform/timer_lpc1769.d ./src/plataform/timer_lpc1769.o ./src/plataform/uart_lpc1769.d ./src/plataform/uart_lpc1769.o

.PHONY: clean-src-2f-plataform

