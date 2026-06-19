/*
 * Copyright 2022 NXP
 * NXP confidential.
 * This software is owned or controlled by NXP and may only be used strictly
 * in accordance with the applicable license terms.  By expressly accepting
 * such t erms or by downloading, installing, activating and/or otherwise using
 * the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include "lpc17xx_dac.h"
#include "plataform/plataform.h"
#include "core/core.h"
#include "actuators/fan.h"
#include "actuators/lamp.h"
#include "lpc17xx_uart.h"

#include <stdio.h>

#define TEMP_MIN_C     20
#define TEMP_MAX_C     30
#define ADC_MAX_VALUE  4095
#define VREF_V         3.3f

static void controlTemperature(uint32_t tAvg);
static void updateDacFromTemperature(uint32_t tAvg);
static uint32_t adcToTemperatureC(uint32_t adcValue);

static void uartSendString(const char *str);

static void uartSendUint(uint32_t value);

uint32_t filtrarTempertatura(uint32_t nuevaTemp);

volatile uint32_t* bufferOrigen;
volatile uint32_t bufferDestino[10];


int main(void) {

	configPinLamp();
	configPinFan();

	stopFan();
	stopLamp();

	configUart();
	configAdc();
	configDma();
	configDac();
	configTimer();


	UART_Send(UART0, (uint8_t*) "1", 1, BLOCKING);

	uartSendString("\r\nControl termico iniciado\r\n");

    while(1) {



    	if(getDmaTermino()) {
    		uartSendString("\r\nTermino\r\n");

    		volatile uint32_t *sensor1;

    		sensor1 = getBufferSensor1();


    	for (int i = 0; i<10; i++){


    			uartSendString(" Sensor1=");
    			//uartSendUint(adcToTemperatureC(sensor1[i]));

    			uint32_t conversion= adcToTemperatureC(sensor1[i]);

    			uartSendUint(conversion);

    			uartSendString(" C \r\n");

    		}

    	/*	uint32_t promedio= 0;

    		for (int i= 0; i < 10; i++){
    			promedio += sensor1[i];
    		}
    		promedio /= 10;

			uartSendString(" Sensor1=");
			uartSendUint(adcToTemperatureC(promedio));
			uartSendUint(promedio);

    		uartSendString("\r\n");*/

    		/*uint32_t tAvg = (t1 + t2 + t3) / 3; */

/*
    		uartSendString("T1=");
    		uartSendUint(t1);
    		uartSendString(" C | T2=");

    		uartSendUint(t2);
    		uartSendString(" C | T3=");

    		uartSendUint(t3);
    		uartSendString(" C | AVG=");

    		uartSendUint(tAvg);
    		uartSendString(" C\r\n"); */

    		resetDma();
    	}
    }
    return 0 ;
}

static void uartSendString(const char *str) {
    while (*str != '\0') {
        while (!(UART_GetLineStatus(UART0) & UART_LINESTAT_THRE)) {

        }_adc;
        UART_SendByte(UART0, (uint8_t)*str);
        str++;
    }
}

static void controlTemperature(uint32_t tAvg) {

	if (tAvg < TEMP_MIN_C) {
		startLamp();
		stopFan();
	}
	else if (tAvg > TEMP_MAX_C) {
		stopLamp();
		startFan();
	}
	else {
		stopLamp();
		stopFan();
	}
}


static void updateDacFromTemperature(uint32_t tAvg) {

	if (tAvg > 50) {
		tAvg = 50;
	}

	uint32_t dacValue = (uint32_t)((tAvg * 1023) / 50);

	DAC_UpdateValue(dacValue);
}



/*static uint32_t adcToTemperatureC(uint32_t adcValue) {

	uint32_t voltage = ((uint32_t)adcValue * 3300) / ADC_MAX_VALUE;

	uint32_t tempK = voltage / 10;   // LM335: 10 mV/K


	if (tempK < 273) {B0
		return 0;
	}

	return tempK - 273;
}*/

uint32_t adcToTemperatureC(uint32_t adcValue) {
    uint32_t mv_adc;

    mv_adc = (adcValue * 150) / 1891;

    return mv_adc;
}

static void uartSendUint(uint32_t value)
{
    char buffer[11];
    int i = 0;

    if(value == 0)
    {
        uartSendString("0");
        return;
    }

    while(value > 0)
    {
        buffer[i++] = '0' + (value % 10);
        value /= 10;
    }

    while(i > 0)
    {
        UART_SendByte(UART0, buffer[--i]);
    }
}


uint32_t filtrarTempertatura(uint32_t nuevaTemp){
	static uint32_t tempFiltrada = 0;

	if(tempFiltrada == 0){
		tempFiltrada = nuevaTemp;
	}
	tempFiltrada = (tempFiltrada * 8 + nuevaTemp*2)/10;
	return tempFiltrada;


}
