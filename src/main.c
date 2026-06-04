/*
 * Copyright 2022 NXP
 * NXP confidential.
 * This software is owned or controlled by NXP and may only be used strictly
 * in accordance with the applicable license terms.  By expressly accepting
 * such t erms or by downloading, installing, activating and/or otherwise using
 * the software, you are agreeing that you have read, and that you agree to
 * comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install,
 * activate or otherwise use the software.
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#include "core/core.h"
#endif

#include <cr_section_macros.h>
#include "plataform/plataform.h"

//TODO: ¿Es factible usar switch-case?

int main(void) {

	configAdc();
	configTimer();
	configUart();

    while(1) {
    	if(getDmaTermino() == 1) {
    		//Calculamos promedio y enviamos por el dac
    		promedioDac();
    		//TODO: decidir donde calculamos el promedio



    	}
    }
    return 0 ;
}
