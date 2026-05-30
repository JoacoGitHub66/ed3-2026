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

	GPIO_SetPinState(PORT_0, PIN_1, RESET);

	return;
}

void startLamp(void){

	GPIO_SetPinState(PORT_0, PIN_1, SET);

	return ;
}

void configPinLamp(void){

	//Todo: configurar pin para la lamparita

	//pin 0.01 -> Lamp
	PINSEL_CFG_T pinLamp;
	pinLamp.pin = PIN_1;
	pinLamp.port = PORT_0;
	pinLamp.func = PINSEL_FUNC_00;
	pinLamp.mode = PINSEL_TRISTATE;
	pinLamp.openDrain = DISABLE;

	PINSEL_ConfigPin(&pinLamp);

	GPIO_SetDir(PORT_0 ,PIN_0, GPIO_OUTPUT);

	return;
}
