#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library
#include <string.h>
#include <math.h>

#include "uart2.h"
#include "io.h"
#include "timer2.h"
#include "timer3.h"
#include "timer4.h"
#include "oc.h"
#include "ic.h"
#include "delays.h"
#include "todo.h"
#include "adc.h"
#include "spi.h"



char inst,n[10];
int a,b, ninst=0;


int main() {

    init_UART2();
    init_io();

    init_TMR2();
    init_OC2();

    init_TMR4();
    //Comunicação

    init_ADC();

    //  pull_UART2();


    srv = 90;
    OC2RS = 332 + 358 * srv / 90;
    printf("teste\n");

    while (1) {

        pull_UART2();
        Read_ADC();
        /*
        delay_ms(100);
        printf("A: srv= %i, pos= %i, posw= %i\n", srv, pos, posw);

       srv += (pos-posw)/10;
       if (srv > 120)
           srv = 120;
       if (srv <60)
           srv = 60;
       printf("B: srv= %i, pos= %i, posw= %i\n", srv, pos, posw);

              

         */
        push_UART2();
        OC2RS = 332 + 358 * srv / 90;

    }
}