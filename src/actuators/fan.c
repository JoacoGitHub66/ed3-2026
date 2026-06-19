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

	GPIO_ClearPins(PORT_2, (1 << 0));

	return;
}

void startFan(void){

	GPIO_SetPins(PORT_2, (1<<0));

	return ;
}

void configPinFan(void){

	//Todo: configurar pin para el ventilador

	//pin 0.00 -> fAN
	PINSEL_CFG_T pinfan;

	pinfan.pin = PIN_0;
	pinfan.port = PORT_2;
	pinfan.func = PINSEL_FUNC_00;
	pinfan.mode = PINSEL_PULLDOWN;
	pinfan.openDrain = DISABLE;

	PINSEL_ConfigPin(&pinfan);

	GPIO_SetDir(PORT_2 ,(1<<0), GPIO_OUTPUT);

	stopFan();

	return;
}
