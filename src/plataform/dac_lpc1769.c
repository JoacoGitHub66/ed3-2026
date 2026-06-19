/*
 * dac_lpc1769.c
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */

#include "plataform.h"
#include "lpc17xx_dac.h"

void configDac(void) {
	DAC_Init();
	DAC_CONVERTER_CFG_T dacCfg= {
			.doubleBuffer= DISABLE,
			.dmaCounter= DISABLE,	//Pasamos el dato con "DAC_UpdateValue()", solo pasamos el promedio. No necesitamos DMA.
			.dmaRequest= DISABLE
	};
	DAC_ConfigDAConverterControl(&dacCfg);
	DAC_UpdateValue(0);
	DAC_SetBias(DAC_350uA);
}
