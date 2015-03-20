#include "elab.h"

/////////////////
// Configuring //
/////////////////
void protocolo_1_configuring(void){
//	printf("Instructions about %s commands:\r", ID_DO_HARDWARE);

}


//////////////
// Starting //
//////////////
void protocolo_1_starting(void){

}

/////////////
// Started //
/////////////
void protocolo_1_started(void){
	double cur_pos, step, p1, p2, p3, p4;

	printf("DAT\r");
		printf("%f\t%f\t%f\t%f\t%f\r",cur_pos,p1,p2,p3,p4);
	printf("END\r");
}


//////////////
// Stopping //
//////////////
void stopping(void)
{

}
