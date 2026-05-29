/*
 * timer_lpc1769.c
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */

#include "plataform.h"
#include "lpc17xx_timer.h"

void configTimer(void) {
	TIM_TIMERCFG_T timerCfg= {
			.prescaleOpt= TIM_US,
			.prescaleValue= 50
	};
	TIM_InitTimer(LPC_TIM0, &timerCfg);
	TIM_MATCHCFG_T matchCfg= {
			.channel= TIM_MATCH_0,
			.intEn= DISABLE,
			.stopEn= DISABLE,
			.extOpt= TIM_NOTHING,
			.matchValue= 1
	};
	TIM_ConfigMatch(LPC_TIM0, &matchCfg);
	TIM_Enable(LPC_TIM0);
}

//TODO: Configurar el MAT0.1 para el adc cada 100ms
