#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library
#include <string.h>
#include <math.h>

#include "uart2.h"
//#include "io.h"
#include "timer2.h"
#include "oc.h"



void init_OC2(void) {

    OC2CONbits.OCSIDL = 0;
    OC2CONbits.OCFLT = 0;
    OC2CONbits.OCTSEL = 0; //Timer2 is the clock source for compare 2
    OC2CONbits.OCM = 0x6;
    OC2RS = 332+358*duty/90; //Duty Time

}

void init_OC4(void) {

    OC4CONbits.OCSIDL = 0;
    OC4CONbits.OCFLT = 0;
    OC4CONbits.OCTSEL = 0; //Timer2 is the clock source for compare 4
    OC4CONbits.OCM = 0x5;
    OC4R = PR2 / 2;
    OC4RS = PR2; //Duty Time
}

