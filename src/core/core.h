/*
 * core.h
 *
 *  Created on: 3 jun. 2026
 *      Author: matic
 */

#ifndef CORE_CORE_H_
#define CORE_CORE_H_

/*
 *
 * */
volatile uint32_t calcularPromedioSensor(uint32_t*);

void promedioDac(void);

volatile uint32_t getPromedioBuffer1(void);

volatile uint32_t getPromedioBuffer2(void);

volatile uint32_t getPromedioBuffer3(void);

#endif /* CORE_CORE_H_ */
