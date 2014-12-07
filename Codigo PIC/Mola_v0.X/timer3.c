
#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library
#include <string.h>
#include <math.h>

#include "todo.h"
#include "timer3.h"
#include "io.h"
#include "spi.h"
#include "adc.h"

void init_TMR3(void) {
    T3CON = 0; // Clear the Timer 3 configuration
    TMR3 = 0x0000; // Sets timer value to zero
    PR3 = 300; // Timer Period

    IEC0bits.T3IE = 1; //Enable interrupt
    T3CONbits.TCKPS = 0; // internal Tcy divider
    IFS0bits.T3IF = 0;
    T3CONbits.TON = 1; // turn on timer 2
    
}

//Timer 2 Interrupt handler

void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void) {
    IFS0bits.T3IF = 0; //Clears interrupt flag
}

