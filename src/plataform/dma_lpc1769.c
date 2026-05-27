/*
 * dma_lpc1769.c
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */
#include "plataform.h"
#include "lpc17xx_gpdma.h"

static GPDMA_LLI_T dmaLli;
#define cant_transf 60 //Vamos a tomar 60 muestras como maximo
static volatile uint32_t muestrasADC[60];

void configDma(void) {
	GPDMA_Init();
	GPDMA_Endpoint_T srcc= {
			.width= GPDMA_WORD,
			.burst= GPDMA_BSIZE_1,
			.increment= DISABLE
	};
	GPDMA_Endpoint_T dstt= {
			.width= GPDMA_WORD,
			.burst= GPDMA_BSIZE_1,
			.increment= ENABLE
	};
	GPDMA_Channel_CFG_T dmaCfg= {
			.channelNum= GPDMA_CH_0,
			.transferSize= cant_transf,
			.type= GPDMA_P2M,
			.srcMemAddr= 0,
			.dstMemAddr= (uint32_t)&muestrasADC,
			.srcConn= GPDMA_ADC,
			.dstConn= 0,
			.src= srcc,
			.dst= dstt,
			.intTC= ENABLE,
			.intErr= DISABLE,
			.linkedList= (uint32_t)&dmaLli
	};
	GPDMA_SetupChannel(&dmaCfg);
	GPDMA_ChannelStart(GPDMA_CH_0);
}

void DMA_IRQHandler(void) {
	GPDMA_ClearIntPending(GPDMA_CLR_INTTC, GPDMA_CH_0);
	//TODO: Completar funcion
	//TODO: Calcular promedio
	//TODO: Decidir en donde enviamos los datos al DAC
}

//Devuelve la direccion del buffer
volatile uint32_t *getAdcBuffer(void) {
	return muestrasADC;
}




