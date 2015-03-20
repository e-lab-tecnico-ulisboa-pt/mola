#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
//#include <timer.h>		//timer library
#include <string.h>
#include <math.h>

#include "io.h"

/* 1ms delay function */
void delay_ms(unsigned int delay)      //delay in miliseconds
{
  long int cycles;                 // number of cycles
  for(;delay;delay--)
    for(cycles= FCY /4;cycles;cycles--); //~1ms cycle
}