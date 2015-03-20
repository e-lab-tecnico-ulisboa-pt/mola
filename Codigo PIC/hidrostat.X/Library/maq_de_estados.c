#include "elab.h"

void maq_de_estados(void)
{
//Variables for external button
	double cur_pos, step, p1, p2, p3, p4;
	int n, p1_offset, p2_offset, p3_offset, p4_offset;
	unsigned int grids[16]; //For display

//STOPPING transition
	if(strcmp(state,"STOPPING") == 0)
	{
		stopping();
		sprintf(state,"STOPED");
	}

//STOPED state
	if(strcmp(state,"STOPED") == 0)
	{
		printf("STPOK\r");
		while((strcmp(state,"CONFIGURING") != 0) &&
			  (strcmp(state,"STARTING") != 0) &&
			  (strcmp(state,"RESETING") != 0))
		{
			sprintf(state,"STOPED");
			rec_generic_driver();
			ClrWdt();
			//External button (for java the dspic state remains in STOPED)
			TRIS_DOUT = INPUT;
			if(DOUT == 1){
				LIGHT = ON;
				configure_tm1640(); //Initialize display of leds
				step = 100.;
				cur_pos = 0.;
				p1_offset = read_adc(T1); //Para ler o valor correctamente
				p1_offset = read_adc(T1);
				p2_offset = read_adc(T2);
				p3_offset = read_adc(T3);
				p4_offset = read_adc(T4);
				walk_motor2_to(mmToSteps(cur_pos), MOTOR2_SPEED);
				n = 0;
				while((n<11) && (stop==0)){
					walk_motor2_to(mmToSteps(cur_pos), MOTOR2_SPEED);
					printf("IDS\t"ID_DO_HARDWARE"\t%s\r", "STOPED");
					delay_ms(2000);
					printf("IDS\t"ID_DO_HARDWARE"\t%s\r", "STOPED");
					p1 = adcTokPa(read_adc(T1),p1_offset);
					p2 = adcTokPa(read_adc(T2),p2_offset);
					p3 = adcTokPa(read_adc(T3),p3_offset);
					p4 = adcTokPa(read_adc(T4),p4_offset);
					floatsTo4x4grids(grids,p1,p2,p3,p4,3);
					writeAllDisplay(grids,143);
					cur_pos += step;
					ClrWdt();
					n++;
				}
				cur_pos -= 2.*step;
				while(cur_pos > step){
					printf("IDS\t"ID_DO_HARDWARE"\t%s\r", "STOPED");
					walk_motor2_to(mmToSteps(cur_pos), MOTOR2_SPEED);
					cur_pos -= step;
				}
				calibrate_motor2();
				DisplayOFF();
				DOUT = 0; //Otherwise it reenters the while(DOUT == 1)
				LIGHT = OFF;
			}
		}
	}
	
//CONFIGURING transition
	if(strcmp(state,"CONFIGURING") == 0)
	{
		if(protocolo == 0) protocolo_0_configuring();
		if(protocolo == 1) protocolo_1_configuring();
		if(protocolo == 2) protocolo_2_configuring();
		if(protocolo == 3) protocolo_3_configuring();
		if(protocolo == 4) protocolo_4_configuring();

		sprintf(state,"CONFIGURED");
	}

//CONFIGURED state
	if(strcmp(state,"CONFIGURED") == 0)
	{
		printf("CFGOK\r");
		while((strcmp(state,"STARTING") != 0) &&
			  (strcmp(state,"RESETING") != 0) &&
			  (strcmp(state,"STOPPING") != 0) &&
			  (strcmp(state,"RESETING") != 0) &&
			  (strcmp(state,"CONFIGURING") != 0))
		{
			sprintf(state,"CONFIGURED");
			rec_generic_driver();
			ClrWdt();
		}
	}


//STARTING transition
	if(strcmp(state,"STARTING") == 0)
	{
		if(protocolo == 1) protocolo_1_starting();
		if(protocolo == 2) protocolo_2_starting();
		if(protocolo == 3) protocolo_3_starting();
		if(protocolo == 4) protocolo_4_starting();

		sprintf(state,"STARTED");
	}


//STARTED state
	if(strcmp(state,"STARTED") == 0)
	{
		printf("STROK\r");
		if(protocolo == 1) protocolo_1_started();
		if(protocolo == 2) protocolo_2_started();
		if(protocolo == 3) protocolo_3_started();
		if(protocolo == 4) protocolo_4_started();
		if(protocolo == 5) protocolo_5_started();
		if(protocolo == 6) protocolo_6_started();

		while((strcmp(state,"STOPPING") != 0) &&
			  (strcmp(state,"RESETING") != 0))
		{
			sprintf(state,"STARTED");
			rec_generic_driver();
			ClrWdt();
		}
	}


//RESETING transition
	if(strcmp(state,"RESETING") == 0)
	{
		sprintf(state,"RESETED");
	}


//RESETED state
	if(strcmp(state,"RESETED") == 0)
	{
		printf("RSTOK\r");
		while((strcmp(state,"CONFIGURING") != 0) &&
			  (strcmp(state,"STOPPING") != 0))
		{
			sprintf(state,"RESETED");
			rec_generic_driver();
			ClrWdt();
		}
	}
}
