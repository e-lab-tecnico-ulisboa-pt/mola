#include <p30F4011.h>		//defines dspic registers
#include <libpic30.h>		//C30 compiler definitions

#include "ic.h"
#include "io.h"


void init_ic1(void) {
	IC1CONbits.ICM = 2; //capture edge every falling edge
	IC1CONbits.ICI = 0; //interrupt on every capture
	IC1CONbits.ICTMR = 0; //uses tmr3
	//IC1CONbits.ICSIDL = 0;
        IFS0bits.IC1IF = 0;
        IEC0bits.IC1IE = 1;
}

void __attribute__((interrupt,no_auto_psv)) _IC1Interrupt(void)
{
        IFS0bits.IC1IF = 0;

        //IC1CONbits.ICM = 0;

        //ic1count = IC1BUF;

}