/*
 * core.h
 *
 *  Created on: 3 jun. 2026
 *      Author: matic
 */
#include"LPC17xx.h"
#include<cr_section_macros.h>

#ifndef CORE_CORE_H_
#define CORE_CORE_H_


/*
 *
 * */
volatile uint32_t calcularPromedioSensor(uint32_t*);

volatile uint32_t calcularPromedioGlobal(void);

void promedioDac(void);

volatile uint32_t getPromedioGlobal(void);

volatile uint32_t getPromedioBuffer1(void);

volatile uint32_t getPromedioBuffer2(void);

volatile uint32_t getPromedioBuffer3(void);


#endif /* CORE_CORE_H_ */
