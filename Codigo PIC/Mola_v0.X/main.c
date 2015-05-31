#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library
#include <string.h>
#include <math.h>

#include "uart.h"
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
#include "elab.h"


//char inst, n[10];
//int a, b, ninst = 0;

int main() {

    init_io();
    configure_uart1();

    init_TMR2();
    init_OC2();
    servo_para_mm(0);

    init_TMR4();
    //Comunicação

    init_ADC();

    //In order to allow initialization correctly before starting RS232 communication.
    delay_ms(1000);
    clear_rbuf();

    //inicia no estado STOPED
    sprintf(state, "STOPED");
    //No caso de ter havido um reset
    rec_generic_driver();
    //Importante iniciar somente depois do rec_generic_driver
    //Para que não haja msg de IDS antes de ter corrido pelo
    //menos uma vez o rec_generic_driver.
    open_timer1_for_communication();

    while (1) {
        maq_de_estados();
        ClrWdt();
    }


}