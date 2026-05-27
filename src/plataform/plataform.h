/*
 * plataform.h
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */

#include "LPC17xx.h"
#include <cr_section_macros.h>

#ifndef PLATAFORM_PLATAFORM_H_
#define PLATAFORM_PLATAFORM_H_

void configAdc(void);
void configDac(void);
void configDma(void);
volatile uint32_t *getAdcBuffer(void);
void configTimer(void);
void configUart(void);

#endif /* PLATAFORM_PLATAFORM_H_ */
