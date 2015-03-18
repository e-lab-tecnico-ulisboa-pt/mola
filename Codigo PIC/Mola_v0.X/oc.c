#include <p30F4011.h>		//defines dspic registers
#include <libpic30.h>		//C30 compiler definitions
#include <timer.h>		//timer library

#include "uart2.h"
//#include "timer2.h"
#include "oc.h"



void init_OC2(void) {

    OC2CONbits.OCSIDL = 0;//continue to opetrate in idle mode
    OC2CONbits.OCFLT = 0;// acho que não é preciso
    OC2CONbits.OCTSEL = 0; //Timer2 is the clock source for compare 2
    OC2CONbits.OCM = 0x6;// acho que não é preciso
    OC2RS = 332+358*srv/90; //Duty Time

}

void init_OC4(void) {

    OC4CONbits.OCSIDL = 0;
    OC4CONbits.OCFLT = 0;
    OC4CONbits.OCTSEL = 0; //Timer2 is the clock source for compare 4
    OC4CONbits.OCM = 0x5;
    OC4R = PR2 / 2;
    OC4RS = PR2; //Duty Time
}

