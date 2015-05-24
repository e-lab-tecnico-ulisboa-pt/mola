#include "elab.h"
#include "io.h"
#include "delays.h"
#include <stdlib.h>
/////////////////
// Configuring //
/////////////////

void protocolo_1_configuring(void) {
    servo_para_mm(0);

}


//////////////
// Starting //
//////////////

void protocolo_1_starting(void) {
    LIGHT = ON;
}

/////////////
// Started //
/////////////

void protocolo_1_started(void) {
    signed long delta;
    int p;
    signed long l1, l2;

    l1=1000*param_1;
    l2=1000*param_2;

    delta = (abs(l1) + 2 * abs(l2 - l1)) / param_3;
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
}

void mede_em(int pw) {
    int pos, fr;
    servo_para_um(pw);
    delay_ms(param_4);
    pos = ADCBUFD; //Calibracao!!!
    fr = (ADCBUFE-512)*20;

    printf("%i\t%i\r", pos, fr);
}

void servo_para_mm(int pw) {
    OC2RS = 332 + (287 * (pw + HALFLENGTH)) / (HALFLENGTH);
}

void servo_para_um(int pw) {
    OC2RS = 332 + (pw + 20000)/ 70;
}