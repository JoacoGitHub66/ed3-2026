/*
 * thermal_control.c
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */

#include "thermal_control.h"
#include "../plataform/plataform.h"

static volatile uint32_t bufferSensor1[10];
static volatile uint32_t bufferSensor2[10];
static volatile uint32_t bufferSensor3[10];

//TODO: Ver donde colocamos esta funcion. Capaz conviene hacerlo en sensors/sensors.c
void separarDatosBuffer(void) {
	volatile uint32_t *bufferADC= getAdcBuffer();
	uint8_t i1, i2, i3;

	for(int i= 0; i < 30; i++){
		uint32_t dato = bufferADC[i];
		uint8_t canal= (dato << 24) & 0x7;
		uint16_t valor= (dato << 4) & 0xFFF;

		if(canal == 0 && i1 < 10){
			bufferSensor1[i1]= valor;
			i1++;
		} else if(canal == 1 && i1 < 10) {
			bufferSensor2[i2]= valor;
			i2++;
		} else if(canal == 2 && i2 < 10) {
			bufferSensor3[i3]= valor;
			i3++;
		}

	}
}

volatile uint32_t *getBuffer1(void){
	return bufferSensor1;
}

volatile uint32_t *getBuffer2(void){
	return bufferSensor2;
}

volatile uint32_t *getBuffer3(void){
	return bufferSensor3;
}
