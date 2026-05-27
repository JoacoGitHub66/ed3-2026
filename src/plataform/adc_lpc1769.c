/*
 * adc_lpc1769.c
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */

#include "plataform.h"
#include "lpc17xx_adc.h"

void configAdc(void) {
	/*
	 * La temperatura es una variable de evolución lenta, cuya frecuencia máxima es muy inferior a 1 Hz. Aplicando el criterio de Nyquist,
	 * bastarían algunas muestras por segundo para reconstruir la señal. Sin embargo, se eligió una frecuencia de muestreo de 10 Hz (100 ms
	 * entre muestras) para mejorar la capacidad de filtrado mediante promediado, obtener una respuesta más rápida del sistema y justificar
	 * el uso del DMA para la adquisición de datos.
	 */
	ADC_Init(10);
	ADC_PinConfig(ADC_CHANNEL_0);
	ADC_StartCmd(ADC_START_CONTINUOUS);
	ADC_BurstEnable();
	ADC_ChannelEnable(ADC_CHANNEL_0);
}
