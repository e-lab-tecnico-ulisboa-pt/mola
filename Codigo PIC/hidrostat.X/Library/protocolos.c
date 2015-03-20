#include "elab.h"

/////////////////
// Configuring //
/////////////////
void protocolo_0_configuring(void){
	printf("Instructions about %s commands:\r", ID_DO_HARDWARE);
	printf("(to see the instuctions correctly add a newline after \\r)\n");
	printf("cfg    p1    p2    p3    p4\n");
	printf("    p1 - protocol (integer 0-6):\n");
	printf("        0 - This instuction message\n");
	printf("        1 - Normal experiment execution:\r");
	printf("            p2 - Initial position (0-%d)\r", DEEP_MAX);
	printf("            p3 - Final position (0-%d)\r", DEEP_MAX);
	printf("            p4 - Number of points (2-200)\n");
	printf("        2 - Calibrate motor\n");
	printf("        3 - Bottom light ON\n");
	printf("        4 - Walk motor to:\r");
	printf("            p2 - Final position (0-%d)\r", DEEP_MAX);
	printf("            p3 - Speed (delay_100ys - typ. value: 37)\n");
	printf("        5 - 7 segments leds - test (print values)\n");
	printf("        6 - 7 segments leds - test (read ADCs)\n");
}
void protocolo_1_configuring(void){
}
void protocolo_2_configuring(void){
}
void protocolo_3_configuring(void){
}
void protocolo_4_configuring(void){
}

//////////////
// Starting //
//////////////
void protocolo_1_starting(void){
	LIGHT = ON;
}
void protocolo_2_starting(void){
}
void protocolo_3_starting(void){
}
void protocolo_4_starting(void){			
}

/////////////
// Started //
/////////////
void protocolo_1_started(void){
	double cur_pos, step, p1, p2, p3, p4;
	int n, p1_offset, p2_offset, p3_offset, p4_offset;
	unsigned int grids[16]; //For display
	//cfg:
	//param_1 -> profundidade inicial (int, mm)
	//param_2 -> profundidade final (int, mm)
	//param_3 -> numero de pontos (int)
	//DAT:
	//param_1 -> profundiade (int, mm)
	//param_2 -> pressao tubo 1 (float, kPa)
	//param_3 -> pressao tubo 2 (float, kPa)
	//param_4 -> pressao tubo 3 (float, kPa)
	//param_5 -> pressao tubo 4 (float, kPa)
	//END
	configure_tm1640(); //Initialize display of leds
	if(param_1 < 0) param_1 = 0;
	if(param_1 > DEEP_MAX) param_1 = DEEP_MAX;
	if(param_2 < 0) param_2 = 0;
	if(param_2 > DEEP_MAX) param_2 = DEEP_MAX;
	if(param_3 < 2) param_3 = 2;
	if(param_3 > 200) param_3 = 200;
	step = (double)(param_2-param_1)/(double)(param_3-1);
	cur_pos = (double) param_1;
	p1_offset = read_adc(T1); //Para ler o valor correctamente
	p1_offset = read_adc(T1);
	p2_offset = read_adc(T2);
	p3_offset = read_adc(T3);
	p4_offset = read_adc(T4);
	walk_motor2_to(mmToSteps(cur_pos), MOTOR2_SPEED);
	printf("DAT\r");
	n = 0;
	while((n<param_3) && (stop==0)){
		walk_motor2_to(mmToSteps(cur_pos), MOTOR2_SPEED);
		delay_ms(2000);
		p1 = adcTokPa(read_adc(T1),p1_offset);
		p2 = adcTokPa(read_adc(T2),p2_offset);
		p3 = adcTokPa(read_adc(T3),p3_offset);
		p4 = adcTokPa(read_adc(T4),p4_offset);
		floatsTo4x4grids(grids,p1,p2,p3,p4,3);
		writeAllDisplay(grids,143);
		printf("%f\t%f\t%f\t%f\t%f\r",cur_pos,p1,p2,p3,p4);
		cur_pos += step;
		ClrWdt();
		n++;
	}
	calibrate_motor2();
	printf("END\r");
}
void protocolo_2_started(void)
{
	printf("DAT:\r");
	printf("0\t0\t0\t0\t0\r");
	calibrate_motor2();
	printf("2\t2\t2\t2\t2\r");
	printf("END\r");
}
void protocolo_3_started(void)
{
	printf("DAT:\r");
	printf("0\t0\t0\t0\t0\r");
	LIGHT = ON;
	printf("1\t1\t1\t1\t1\r");
	printf("END\r");
}
void protocolo_4_started(void)
{
	//param_1 -> motor_position
	printf("DAT:\r");
	printf("0\t0\t0\t0\t0\r");
	walk_motor2_to(mmToSteps(param_1), param_2);
	printf("1\t1\t1\t1\t1\r");
	printf("END\r");
}
void protocolo_5_started(void)
{
	configure_tm1640(); //Initialize display of leds
	printf("DAT:\r");
	printf("5\t0\t0\t0\t0\r");
	unsigned int grids[16];
	floatsTo4x4grids(grids, -1.239, 789., 0.02, -44.499999, 4);
	writeAllDisplay(grids,143);
	printf("5\t%d\t%d\t1\t1\r", param_1,param_2);
	printf("END\r");
}
void protocolo_6_started(void)
{
	configure_tm1640(); //Initialize display of leds
	int p1, p2, p3, p4;
	printf("DAT:\r");
	printf("6\t0\t0\t0\t0\r");
	unsigned int grids[16];
	while(!stop){
		p1 = read_adc(T1);
		p2 = read_adc(T2);
		p3 = read_adc(T3);
		p4 = read_adc(T4);
		printf("p1=%d, p2=%d, p3=%d, p4=%d\r",p1,p2,p3,p4);
		//floatsTo4x4grids(grids, (float) p1, (float) p2, (float) p3, (float) p4, 4);
		floatsTo4x4grids(grids, (float) p1, (float) p2, (float) p3, (float) p4, 3);
		writeAllDisplay(grids,143);
		//calibrate_motor2();
		delay_ms(1000);
		ClrWdt();
	}
	printf("6\t%d\t%d\t1\t1\r", param_1,param_2);
	printf("END\r");
}

//////////////
// Stopping //
//////////////
void stopping(void)
{
	LIGHT = OFF;
	DisplayOFF();
	DOUT = 0; //Otherwise it enters the external button function in maq_de_estados.c
	walk_motor2_to(ZERO_POSITION, MOTOR2_SPEED);
}
