/*
 * timer_lpc1769.c
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */

#include "plataform.h"
#include "lpc17xx_timer.h"
#include "lpc17xx_uart.h"

void configTimer(void) {
	UART_Send(UART0, (uint8_t*) "T", 1, BLOCKING);
	TIM_TIMERCFG_T timerCfg= {
			.prescaleOpt= TIM_US,
			.prescaleValue= 1000
	};
	TIM_InitTimer(LPC_TIM0, &timerCfg);
	TIM_MATCHCFG_T matchCfg= {
			.channel= TIM_MATCH_1,
			.intEn= DISABLE,
			.stopEn= DISABLE,
			.resetEn= ENABLE,
			.extOpt= TIM_TOGGLE,
			.matchValue= 100
	};
	TIM_ConfigMatch(LPC_TIM0, &matchCfg);
	TIM_Enable(LPC_TIM0);
}

//TODO: Configurar el MAT0.1 para el adc cada 100ms


/*void TIMER0_IRQHandler(void) {

	UART_Send(UART0, (uint8_t*) "p", 1, BLOCKING);
	TIM_ClearIntPending(LPC_TIM0, TIM_MR0_INT);
}*/
