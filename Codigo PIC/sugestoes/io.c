#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library

#include "io.h"

//Configuration bits
_FOSC(CSW_FSCM_OFF & XT_PLL16); //oscilator at 16x PLL
_FWDT(WDT_OFF); //watchdog timer is off

void init_io(void) {

    ENTRA_TRIS = INPUT;
    BOTAO_TRIS = INPUT;
    SEL_TRIS = OUTPUT;
    LED1_TRIS = OUTPUT;
    LED2_TRIS = OUTPUT;
    PWM2_TRIS = OUTPUT;
    PWM4_TRIS = OUTPUT;
}