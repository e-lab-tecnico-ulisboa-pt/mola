#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library
#include <string.h>
#include <math.h>

#include "todo.h"
#include "timer2.h"
#include "io.h"

void init_TMR2(void) {

    T2CON = 0; // Clear the Timer 2 configuration
    TMR2 = 0x0000; // Sets timer value to zero
    PR2 = 9226; // Timer Period

    IEC0bits.T2IE = 1; //Enable interrupt
    T2CONbits.TCKPS = 2; // internal Tcy divider
    T2CONbits.TON = 1; // turn on timer 2
    IFS0bits.T2IF = 0;

}
//Timer 2 Interrupt handler

void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void) {
    IFS0bits.T2IF = 0; //Clears interrupt flag
      ADCON1bits.ADON = 1;
     //LED2 = !LED2;
   


}
