/*
 * thermal_control.h
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */

#include "LPC17xx.h"
#include <cr_section_macros.h>

#ifndef THERMAL_CONTROL_THERMAL_CONTROL_H_
#define THERMAL_CONTROL_THERMAL_CONTROL_H_

void separarDatosBuffer(void);
volatile uint32_t *getBuffer1(void);
volatile uint32_t *getBuffer2(void);
volatile uint32_t *getBuffer3(void);

#endif /* THERMAL_CONTROL_THERMAL_CONTROL_H_ */
