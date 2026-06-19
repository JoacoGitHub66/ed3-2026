/*
 * uart_lpc1769.c
 *
 *  Created on: 27 may 2026
 *      Author: joaquin
 */

#include "plataform.h"
#include "lpc17xx_uart.h"
#include "lpc17xx_gpio.h"

#include "lpc17xx_pinsel.h"

#include "../actuators/lamp.h"
#include "../actuators/fan.h"

void configUart(void) {

    // configurar P0.2 (TXD0) y P0.3 (RXD0)
    PINSEL_CFG_T pinCfg;

    pinCfg.port   = PORT_0;
    pinCfg.pin    = PIN_2;
    pinCfg.func   = PINSEL_FUNC_01;   // funcion UART0 TXD
    pinCfg.mode   = PINSEL_TRISTATE;
    pinCfg.openDrain = DISABLE;
    PINSEL_ConfigPin(&pinCfg);

    pinCfg.pin    = PIN_3;
    pinCfg.func   = PINSEL_FUNC_01;   // funcion UART0 RXD
    pinCfg.mode      = PINSEL_PULLUP;
    PINSEL_ConfigPin(&pinCfg);

    GPIO_SetDir(PORT_0, (1<<3), GPIO_INPUT);
    GPIO_SetDir(PORT_0, (1<<2), GPIO_OUTPUT);

    UART_CFG_T uartCfg;
    uartCfg.baudRate = 9600;
    uartCfg.parity   = UART_PARITY_NONE;
    uartCfg.dataBits  = UART_DBITS_8;
    uartCfg.stopBits  = UART_STOPBIT_1;
    UART_Init(UART0, &uartCfg);

    UART_FIFO_CFG_T fifoCfg;
    fifoCfg.resetRxBuf = ENABLE;
    fifoCfg.resetTxBuf = ENABLE;
    fifoCfg.dmaMode    = DISABLE;
    fifoCfg.level      = UART_FIFO_TRGLEV0;
    UART_FIFOConfig(UART0, &fifoCfg);

    UART_IntConfig(UART0, UART_INT_RBR, ENABLE);
    NVIC_EnableIRQ(UART0_IRQn);

    UART_TxEnable(UART0);
}


void UART0_IRQHandler(void) {

	uint32_t intId = UART_GetIntId(UART0);

	if ((intId & UART_IIR_INTID_MASK) == UART_IIR_INTID_RDA) {

		char dato = UART_ReceiveByte(UART0);

		switch(dato) {
			case 'l':
				stopLamp();
				UART_Send(UART0, (uint8_t*) "1", 1, BLOCKING);
				break;

			case 'f':
				stopFan();
				UART_Send(UART0, (uint8_t*) "2", 1, BLOCKING);
				break;

			case 'L':
				startLamp();
				UART_Send(UART0, (uint8_t*) "3", 1, BLOCKING);
				break;

			case 'F':
				startFan();
				UART_Send(UART0, (uint8_t*) "4", 1, BLOCKING);
				break;

			default:
				break;
		}
	}
}
