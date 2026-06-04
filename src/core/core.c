/*
 * core.c
 *
 *  Created on: 3 jun. 2026
 *      Author: matic
 */

#include "core.h"
#include "lpc17xx_dac.h"
#include "thermal_control.h"

/*
 * @Brief: Calcula la temperatura de un sensor recibiendo como parametro la dir de memoria de un buffer
 * @Param: uint32_t* dir de memoria del buferr del sensor que queremos calcular el promedio
 * @Retrun: uint32_t con el valor del promedio
 * */
volatile uint32_t calcularPromedioSensor(uint32_t* bufferSensor){

	volatile uint32_t val = 0;
	for (int i=0; i<10 ; i++){
		val += bufferSensor[i];
	}
	return val/10;
}

/*
 * @Brief: Calcula el promedio de temperatura registrado por los 3 sensores y envia dicho valor al DAC
 */
void promedioDac(void){

	volatile uint32_t val = 0;
	val += calcularPromedioSensor(getBuffer1());
	val += calcularPromedioSensor(getBuffer2());
	val += calcularPromedioSensor(getBuffer3());
	val = val/3;

	DAC_UpdateValue(val >> 2);
}

volatile uint32_t getPromedioBuffer1(void){
	return calcularPromedioSensor(getBuffer1());
}

volatile uint32_t getPromedioBuffer2(void){
	return calcularPromedioSensor(getBuffer2());
}

volatile uint32_t getPromedioBuffer3(void){
	return calcularPromedioSensor(getBuffer3());
}

