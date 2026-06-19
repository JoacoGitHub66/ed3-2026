/*
 * core.c
 *
 *  Created on: 3 jun. 2026
 *      Author: matic
 */

#include "core.h"

#define ADC_MAX_VALUE 4095.0f
#define VREF_V        3.3f

/*
 * @Brief: Calcula la temperatura de un sensor recibiendo como parametro la dir de memoria de un buffer
 * @Param: uint32_t* dir de memoria del buferr del sensor que queremos calcular el promedio
 * @Retrun: uint32_t con el valor del promedio
 * */
volatile uint32_t calcularPromedioSensor(volatile uint32_t* bufferSensor){

	volatile uint32_t val = 0;
	for (int i=0; i<10 ; i++){
		val += bufferSensor[i];
	}
	return val/10;
}
