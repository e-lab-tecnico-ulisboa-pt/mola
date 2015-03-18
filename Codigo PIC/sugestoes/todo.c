#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library
#include <string.h>
#include <math.h>

#include "delays.h"
#include "todo.h"
#include "io.h"
#include "uart2.h"
#include "ic.h"
#include "timer3.h"

int (*funcao)();

int vectorseno[MEMMAX];

int enable = 1;

void calculaseno() {
    int i;
    //printf("A calcular seno\n");
    for (i = 0; i < MEMMAX; ++i) {
        vectorseno[i] = (DACMAX / 2 + (DACMAX - 1) * sin(2 * i * PI / MEMMAX) / 2);
        //printf("%i\n",vectorseno[i]);
    }
}

int triangular(int tempo) {
    static int y = 0;

    if (tempo < T_DACMAX / 2)
        y += (DACMAX * 2) / T_DACMAX;
    else
        y -= (DACMAX * 2) / T_DACMAX;
    if (y >= DACMAX)
        return DACMAX - 1;
    else
        return y;
}

int denteserra(int tempo) {
    static int y = 0;

    if (tempo <= T_DACMAX)
        y += (DACMAX * 2) / T_DACMAX;
    else
        y = 0;
    return y >> 1;
}

int seno(int tempo) {
    const int div = T_DACMAX / MEMMAX;
    return vectorseno[tempo / div];
}