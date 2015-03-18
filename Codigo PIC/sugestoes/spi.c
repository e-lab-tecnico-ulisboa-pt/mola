#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library
#include <string.h>
#include <math.h>

#include "io.h"
#include "spi.h"

void init_SPI1() {
    SPI1CONbits.MODE16 = 1;
    SPI1CONbits.MSTEN = 1;
    SPI1CONbits.CKE = 1;
    SPI1CONbits.SPRE = 0b000;
    SPI1CONbits.PPRE = 0b11;

    IFS0bits.SPI1IF = 0;
    IEC0bits.SPI1IE = 1;

    SPI1STATbits.SPIROV = 0;
    SPI1STATbits.SPIEN = 1;
}

void __attribute__((interrupt, no_auto_psv)) _SPI1Interrupt(void) {
    IFS0bits.SPI1IF = 0;
    SPI1STATbits.SPIROV = 0;
    SEL = 1;
}

void write_SPI1(int digital_level) {
    //digital level should be a 12bit integer
    SEL = 0;
    digital_level = 0x0FFF & digital_level;
    SPI1BUF = 0x1000 | digital_level;

}