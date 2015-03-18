
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
    //sin -> PR3 600
    PR3 = 300; // Timer Period

    IEC0bits.T3IE = 1; //Enable interrupt
    T3CONbits.TCKPS = 0; // internal Tcy divider
    T3CONbits.TON = 1; // turn on timer 2
    IFS0bits.T3IF = 0;

}

//Timer 2 Interrupt handler

void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void) {
    IFS0bits.T3IF = 0; //Clears interrupt flag
    static int j = 2;
    static int dac = DACMAX / 2;


    if (ENTRA != 1)
        dac -= (DACMAX >> j) + (j == NBITS + 1 ? 1 : 0);

    else if (j != NBITS + 1)
        dac += DACMAX >> j;

    if (++j > NBITS + 1) {
        j = 2;
        T3CONbits.TON = 0;
        //printf("SAR result %i\n", dac);

        /*-------------------------------------------*/

        static unsigned long int i = 0;
        static unsigned int last = 0;
        x = dac;
        LED2 = !LED2;
        if (resultados.status == RUN) {
            ++resultados.data[x/8];
        if (++i >= 200000) {
            resultados.status = FULL;
            LED1 = 1;
            //T2CONbits.TON = 0;
            i = 0;
        }
/*

            resultados.data[i] = x;
            if (++i >= N_RESULTS) {
                resultados.status = FULL;
                LED1 = 1;
                //T2CONbits.TON = 0;
                i = 0;
            }
*/
        } else if (resultados.status == EMPTY)
            if (
                    ((last < x) && (trig1.edge == RISING) && (trig1.armed == 1)) ||
                    ((last > x) && (trig1.edge == FALLING) && (trig1.armed == 1)) ||
                    ((last != x) && (trig1.edge == EVERY) && (trig1.armed == 1)) ||
                    BOTAO
                    ) {
                resultados.status = RUN;
                trig1.armed = 0;
                LED1 = 0;
            } else {
                if ((x > trig1.level - trig1.delta) && (x < trig1.level + trig1.delta))
                    trig1.armed = 1;
                else
                    trig1.armed = 0;
            }

        last = x;
        /*-------------------------------------------*/

        dac = DACMAX >> 1;


    }
    write_SPI1(dac == DACMAX ? DACMAX - 1 : dac);
}

