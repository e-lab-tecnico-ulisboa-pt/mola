#include <p30F4011.h>		//defines dspic registers
#include <libpic30.h>		//C30 compiler definitions

#include "io.h"

//Configuration bits
_FOSC(CSW_FSCM_OFF & XT_PLL16); //oscilator at 16x PLL
_FWDT(WDT_ON & WDTPSA_512 & WDTPSB_16); //watchdog timer (interval of ~ 16s)
//_FWDT(WDT_OFF);

void init_io(void) {
    BOTAO_TRIS  = INPUT;
    AN0_TRIS    = INPUT;
    AN1_TRIS    = INPUT;

    LED1_TRIS = OUTPUT;
    LED2_TRIS = OUTPUT;
    PWM2_TRIS = OUTPUT;
    LIGHT_TRIS = OUTPUT;
}