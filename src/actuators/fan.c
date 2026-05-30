/*
 * fan.c
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */

#include "fan.h"
#include "LPC17xx.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_gpio.h"

void stopFan(void){

	GPIO_SetPinState(PORT_0, PIN_0, RESET);

	return;
}

void startFan(void){

	GPIO_SetPinState(PORT_0, PIN_0, SET);

	return ;
}

void configPinFan(void){

	//Todo: configurar pin para el ventilador

	//pin 0.00 -> fAN
	PINSEL_CFG_T pinfan;
	pinfan.pin = PIN_0;
	pinfan.port = PORT_0;
	pinfan.func = PINSEL_FUNC_00;
	pinfan.mode = PINSEL_TRISTATE;
	pinfan.openDrain = DISABLE;

	PINSEL_ConfigPin(&pinfan);

	GPIO_SetDir(PORT_0 ,PIN_0, GPIO_OUTPUT);

	return;
}
