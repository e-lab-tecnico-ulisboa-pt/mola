#include "elab.h"
#include "io.h"
#include <stdlib.h>
/////////////////
// Configuring //
/////////////////

void protocolo_1_configuring(void) {
    servo_para(0);

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
    int delta;
    int p;

    delta = (abs(param_1) + 2 * abs(param_2 - param_1)) / param_3;
    if(delta == 0)
        delta = 1;
    printf("DAT\r");

    //0 -> L1
    if (param_1 < 0)
        for (p = 0; p > param_1; p -= delta)
            mede_em(p);
    else if (param_1 > 0)
        for (p = 0; p < param_1; p += delta)
            mede_em(p);
    //L1->L2->L1
    if (param_2 < param_1) {
        for (p = param_1; p > param_2; p -= delta)
            mede_em(p);
        for (p = param_2; p < param_1; p += delta)
            mede_em(p);
    } else if (param_2 > param_1) {
        for (p = param_1; p < param_2; p += delta)
            mede_em(p);
        for (p = param_2; p > param_1; p -= delta)
            mede_em(p);
    }


    printf("END\r");
}


//////////////
// Stopping //
//////////////

void stopping(void) {
    servo_para(0);
    LIGHT = OFF;
}

void mede_em(int pw) {
    int pos, fr;
    servo_para(pw);
    delay_ms(20);
    pos = ADCBUFD;
    fr = ADCBUFE;

    printf("%i\t%i\r", pos, fr);
}

void servo_para(int pw) {
    OC2RS = 332 + (287 * (pw + HALFLENGTH)) / (HALFLENGTH);
}