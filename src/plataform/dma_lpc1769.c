/*
 * dma_lpc1769.c
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */
#include "plataform.h"
#include "lpc17xx_gpdma.h"
#include "../thermal_control/thermal_control.h"

#include "lpc17xx_uart.h"

#define cant_transf 10//Vamos a tomar 30 muestras como maximo. Para un adc a 10Hz -> 1 m cada 100ms -> 30m x 100ms = 3 seg,
static volatile uint32_t muestrasADC[30]; //Almacena las 30 muestras por adc. 10 por cada canal.
static volatile uint8_t dmaTermino= 0;


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
			.srcMemAddr= (uint32_t)&LPC_ADC->ADGDR,
			.dstMemAddr= (uint32_t)&muestrasADC,
			.srcConn= GPDMA_ADC,
			.dstConn= 0,
			.src= srcc,
			.dst= dstt,
			.intTC= ENABLE,
			.intErr= DISABLE,
			.linkedList= 0
	};
	GPDMA_SetupChannel(&dmaCfg);
	GPDMA_ChannelStart(GPDMA_CH_0);
	NVIC_EnableIRQ(DMA_IRQn);
	dmaTermino= 0;
}

//Cuando realiza todas las transferencias (30) DMA interrumpe
void DMA_IRQHandler(void) {

	UART_Send(UART0, (uint8_t*) "5", 1, BLOCKING);

	separarDatosBuffer();

		GPDMA_ClearIntPending(GPDMA_CLR_INTTC, GPDMA_CH_0);


		dmaTermino = 1;

}

//Devuelve la direccion del buffer
volatile uint32_t *getAdcBuffer(void) {
	return muestrasADC;
}


volatile uint8_t getDmaTermino(void) {
	return dmaTermino;
}


void resetDma(void) {

	GPDMA_ChannelStop(GPDMA_CH_0);

	for (uint8_t i = 0; i < cant_transf; i++) {
		muestrasADC[i] = 0;
	}

	dmaTermino = 0;

	configDma();
}

