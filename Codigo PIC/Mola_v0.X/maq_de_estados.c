#include "elab.h"

void maq_de_estados(void) {
    //Variables for external button
    double cur_pos, step, p1, p2, p3, p4;


    //STOPPING transition
    if (strcmp(state, "STOPPING") == 0) {
        stopping();
        sprintf(state, "STOPED");
    }

    //STOPED state
    if (strcmp(state, "STOPED") == 0) {
        printf("STPOK\r");
        while ((strcmp(state, "CONFIGURING") != 0) &&
                (strcmp(state, "STARTING") != 0) &&
                (strcmp(state, "RESETING") != 0)) {
            sprintf(state, "STOPED");
            rec_generic_driver();
            ClrWdt();

        }
    }


//CONFIGURING transition
if (strcmp(state, "CONFIGURING") == 0) {
    //	if(protocolo == 0) protocolo_0_configuring();

    sprintf(state, "CONFIGURED");
}

//CONFIGURED state
if (strcmp(state, "CONFIGURED") == 0) {
    printf("CFGOK\r");
    while ((strcmp(state, "STARTING") != 0) &&
            (strcmp(state, "RESETING") != 0) &&
            (strcmp(state, "STOPPING") != 0) &&
            (strcmp(state, "RESETING") != 0) &&
            (strcmp(state, "CONFIGURING") != 0)) {
        sprintf(state, "CONFIGURED");
        rec_generic_driver();
        ClrWdt();
    }
}


//STARTING transition
if (strcmp(state, "STARTING") == 0) {
    if (protocolo == 1) protocolo_1_starting();


    sprintf(state, "STARTED");
}


//STARTED state
if (strcmp(state, "STARTED") == 0) {
    printf("STROK\r");
    if (protocolo == 1) protocolo_1_started();


    while ((strcmp(state, "STOPPING") != 0) &&
            (strcmp(state, "RESETING") != 0)) {
        sprintf(state, "STARTED");
        rec_generic_driver();
        ClrWdt();
    }
}


//RESETING transition
if (strcmp(state, "RESETING") == 0) {
    sprintf(state, "RESETED");
}


//RESETED state
if (strcmp(state, "RESETED") == 0) {
    printf("RSTOK\r");
    while ((strcmp(state, "CONFIGURING") != 0) &&
            (strcmp(state, "STOPPING") != 0)) {
        sprintf(state, "RESETED");
        rec_generic_driver();
        ClrWdt();
    }
}
}
