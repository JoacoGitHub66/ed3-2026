/*
 * uart_lpc1769.c
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */

#include "plataform.h"
#include "lpc17xx_uart.h"

#warning "Estoy incluyendo lpc17xx_uart.h"

#include "../actuators/lamp.h"
#include "../actuators/fan.h"

void configUart(void) {
	UART_PinConfig(UART_TX3_P4_28);
	UART_PinConfig(UART_RX3_P4_29);

	UART_CFG_T uartCfg = {
		.baudRate = 115200,
		.parity   = UART_PARITY_NONE,
		.dataBits = UART_DBITS_8,
		.stopBits = UART_STOPBIT_1
	};

	UART_Init(UART3, &uartCfg);

	UART_FIFO_CFG_T fifoCfg = {
		.resetRxBuf = ENABLE,
		.resetTxBuf = ENABLE,
		.dmaMode    = DISABLE,
		.level      = UART_FIFO_TRGLEV0
	};

	UART_FIFOConfig(UART3, &fifoCfg);

	UART_IntConfig(UART3, UART_INT_RBR, ENABLE);

	UART_TxEnable(UART3);

	NVIC_EnableIRQ(UART3_IRQn);
}


void UART3_IRQHandler(void) {

	uint32_t intId = UART_GetIntId(UART3);

	if ((intId & UART_IIR_INTID_MASK) == UART_IIR_INTID_RDA) {

		char dato = UART_ReceiveByte(UART3);

		switch(dato) {
			case 'l':
				stopLamp();
				break;

			case 'f':
				stopFan();
				break;

			case 'L':
				startLamp();
				break;

			case 'F':
				startFan();
				break;

			default:
				break;
		}
	}
}
