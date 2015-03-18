#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library

#include "ic.h"
#include "uart2.h"
#include "todo.h"
#include "io.h"

long ic1count = 0, lastic1count;

void init_ic1(void) {
	IC1CONbits.ICM = 2; //capture edge every falling edge
	IC1CONbits.ICI = 0; //interrupt on every capture
	IC1CONbits.ICTMR = 0; //uses tmr3
	//IC1CONbits.ICSIDL = 0;
        IFS0bits.IC1IF = 0;
        IEC0bits.IC1IE = 1;
}

void __attribute__((interrupt,no_auto_psv)) _IC1Interrupt(void)
{
        IFS0bits.IC1IF = 0;
        T4CONbits.TON = 1;
        IC1CONbits.ICM = 0;
        //LED1=1;
        ic1count = IC1BUF;    

}