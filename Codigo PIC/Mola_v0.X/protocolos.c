#include "elab.h"
#include "io.h"
#include "delays.h"
#include <stdlib.h>

#define ABS(x) (x>0?x:-x)
/////////////////
// Configuring //
/////////////////

void protocolo_1_configuring(void) {

}


//////////////
// Starting //
//////////////

void protocolo_1_starting(void) {
    T2CONbits.TON = 1;
    OC2CONbits.OCM = 0x6;
    servo_para_mm(0);
    LIGHT = ON;
    delay_ms(200);
    //LIGHT = ON;
}

/////////////
// Started //
/////////////

void protocolo_1_started(void) {
    long delta;
    int p;
    long l1, l2;

    l1=1000*((long) param_1);
    l2=1000*((long) param_2);


    delta = (ABS(l1) + 2 * ABS(l2 - l1)) / param_3;
    
    if(delta == 0)
        delta = 10;

    printf("DAT\r");

    //0 -> L1
    if (l1 < 0)
        for (p = 0; p > l1; p -= delta)
            mede_em(p);
    else if (l1 > 0)
        for (p = 0; p < l1; p += delta)
            mede_em(p);
    //L1->L2->L1
    if (l2 < l1) {
        for (p = l1; p > l2; p -= delta)
            mede_em(p);
        for (p = l2; p < l1; p += delta)
            mede_em(p);
    } else if (l2 > l1) {
        for (p = l1; p < l2; p += delta)
            mede_em(p);
        for (p = l2; p > l1; p -= delta)
            mede_em(p);
    }


    printf("END\r");
}


//////////////
// Stopping //
//////////////

void stopping(void) {
    servo_para_mm(0);
    LIGHT = OFF;
    OC2CONbits.OCM = 0;
    T2CONbits.TON = 0;
}

void mede_em(int pw) {
    int pos, fr;
    servo_para_um(pw);
    delay_ms(param_4);
    pos = (ADCBUFD-512)*39;
    fr = (ADCBUFE-512)*20;
    ClrWdt();   //Considerar retirar
    printf("%i\t%i\r", pos, fr);
}

void servo_para_mm(int pw) {
OC2RS = 1200 + (1200 * (pw + HALFLENGTH)) / (HALFLENGTH);
}

void servo_para_um(long pw) {
    OC2RS = 1200 + (pw + 20000)/ 17;
}