/*
 * lamp.c
 *
 *  Created on: May 28, 2026
 *      Author: mati
 */


#include "lamp.h"
#include "LPC17xx.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_gpio.h"

void stopLamp(void){

	GPIO_ClearPins(PORT_2, (1<<2));


	return;
}

void startLamp(void){

	GPIO_SetPins(PORT_2, (1<<2));


	return ;
}

void configPinLamp(void){

	//Todo: configurar pin para la lamparita

	PINSEL_CFG_T pinLamp;
	pinLamp.pin = PIN_2;
	pinLamp.port = PORT_2;
	pinLamp.func = PINSEL_FUNC_00;
	pinLamp.mode = PINSEL_PULLDOWN;
	pinLamp.openDrain = DISABLE;

	PINSEL_ConfigPin(&pinLamp);

	GPIO_SetDir(PORT_2,(1<<2), GPIO_OUTPUT);

	stopLamp();

	return;
}
