#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library
#include <string.h>

#include "uart2.h"
#include "todo.h"

/*
  bibf and bibv struct store strings to compare with inputs.
  For every string, there is a pointer to the corresponding function or variable
 */

bibf inputf[INPUTFMAX];
bibv inputv[INPUTVMAX];

unsigned int UMODEvalue, U2STAvalue, str_pos = 0; //auxiliary UART config variables
char RXbuffer[80];

int delta, time;
unsigned int duty;

void init_UART2()
{
    init_bib();

    /* Serial port config */
    UMODEvalue = UART_EN & UART_IDLE_CON & UART_NO_PAR_8BIT; //activates the uart in continuos mode (no sleep) and 8bit no parity mode
    U2STAvalue = UART_INT_TX & UART_TX_ENABLE & UART_INT_RX_CHAR & UART_RX_TX; //activates interrupt of pin Tx + enables Tx + enable Rx interrupt for every char
    OpenUART2(UMODEvalue, U2STAvalue, 15); //configures and activates UART2 at 115000 bps
    //BRG = 15 (value changed to several values)
    U2STAbits.URXISEL = 1;
    _U2RXIE = 1; //0-Interruption off, 1-Interruption on

    U2MODEbits.LPBACK = 0; //disables hardware loopback on UART2. Enable only for tests

    __C30_UART = 2; //define UART2 as predefined for use with stdio library, printf etc

    printf("\n\rSerial port ONLINE \n"); //to check if the serial port is working
}

void init_bib()
{
        inputf[0].text = "t";  inputf[0].job = &triangular;
        inputf[1].text = "d";   inputf[1].job = &denteserra;
        inputf[2].text = "s";   inputf[2].job = &seno;

        inputv[0].text = "duty";    inputv[0].var = &duty;
        inputv[1].text = "delta";   inputv[1].var = &delta;
}


int poliglota()   //compares input string with text
                  //executes desired function or assigns a value to a variable
{
  int w, t, k;       //variable declaration
  char in_arg[60];

  w = sscanf(RXbuffer, "%s %u", in_arg, &t);    //reads buffer to a string and an int

  if (w > 0)                            //function type command (only one word)
    {
      for (k = 0; k < INPUTFMAX; ++k)
	if(strcmp(in_arg, inputf[k].text) == 0)
	  {
	    //toggle();
	    printf("Running %s...\n", in_arg);    //prints and runs the  desired function
	    //inputf[k].job();
            funcao = inputf[k].job;
	    //printf("done %s\n", in_arg);
	    return 1;
	  }
    }
  if (w > 1)                            //variable assignement type (word and number)
    {
      for (k = 0; k < INPUTVMAX; ++k)
	if(strcmp(in_arg, inputv[k].text) == 0)
	  {
	    * (inputv[k].var) = t;            //assigns the value to the variable
	    printf("%s = %u\n", in_arg,* (inputv[k].var)); //prints the operation

	    return 2;
	  }
    }

  printf("ERROR: that was not recognized!...\n");      //string not recognized
                                                //strings are stored at structs

  return 3;
}


void pull_UART2(){
    int i = 0;
        if (RXbuffer[str_pos ? str_pos - 1 : 0] == '\r') //If a complete line was sent, runs poliglota,
            //prepares to new line
        {
            //printf("ola!!\n");
            //printf("\nEnter pressed\n");
            printf("%s\n", RXbuffer); //prints input received
            poliglota();
            str_pos = 0; //returns the pointer to position zero in the circular buffer
            for (i = 0; i < 80; i++) {
                RXbuffer[i] = '\0';
            } //erases the buffer
            //printf("\rEnter your command:\n");
        }
}

/****************************************************
 ************     Interruptions   *******************
 ****************************************************/

/* This is UART2 receive ISR */
// UART Interruption handler
void __attribute__((__interrupt__,auto_psv)) _U2RXInterrupt(void)
{
  IFS1bits.U2RXIF = 0;  //resets and reenables the Rx2 interrupt flag

  // Read the receive buffer until at least one or more character can be read
  while(U2STAbits.URXDA)
    {
      RXbuffer[str_pos] = U2RXREG;  //stores the last received char in the buffer
      printf("%c", RXbuffer[str_pos]);  //prints the last received char
      str_pos++;                        //increments the position in the buffer to store the next char
      if(str_pos >= 80){str_pos = 0;}    //if the last position is reached then return to initial position
    }
}