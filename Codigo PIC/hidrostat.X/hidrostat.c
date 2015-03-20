#include "Library/elab.h"

//Configuration bits
_FOSC(CSW_FSCM_OFF & XT_PLL16);  //oscilator
_FWDT(WDT_ON & WDTPSA_512 & WDTPSB_16);  //watchdog timer (interval of ~ 16s)
//_FWDT(WDT_OFF);


int main(){
	
	configure_uart2();
	open_motor2();
	configure_adc();
	configure_adc_channel(T1);
	configure_adc_channel(T2);
	configure_adc_channel(T3);
	configure_adc_channel(T4);

	LIGHT_TRIS = OUTPUT;
	ADPCFGbits.PCFG8 = 1;
	LIGHT = OFF;

	//LED activation to inform dsPic is running
//    LED2_TRIS = OUTPUT;
//	ADPCFGbits.PCFG5 = 1;
	LED1_TRIS = OUTPUT;
	ADPCFGbits.PCFG4 = 1;

	//Calibracao do motor
	ClrWdt();
	calibrate_motor2();
	ClrWdt();

	//In order to allow initialization correctly before starting RS232 communication.
	delay_ms(1000);
	clear_rbuf();

	//inicia no estado STOPED
	sprintf(state,"STOPED");
	//No caso de ter havido um reset
	rec_generic_driver();
	//Importante iniciar somente depois do rec_generic_driver
	//Para que não haja msg de IDS antes de ter corrido pelo
	//menos uma vez o rec_generic_driver.
	open_timer1_for_communication();

	while(1){

		maq_de_estados();
		ClrWdt();

	}// END OF WHILE(1)
}// END OF MAIN


///////////////
// FUNCTIONS //
///////////////
double adcTokPa(int p_val, int adc_offset){
	p_val -= adc_offset; //in order to remove the initial offset
	//MPX2300DT1 sensitivity: 5 uV/V/mmHg
	//Power supply: 6 V
	//Sensitivity (with power supply): 30 uV/mmHg
	//Amplifier gain: 100K/143 = 699.3007
	//Total sensitivity: 20.979 mV/mmHg
	//                   157.3556 mV/kPa
	//                   0.1573556 V/kPa
	//ADC to Volt: 5/4096 = 0.0012207 V/level(or channel)
	//ADC to kPa: 0.0012207/0.1573556 = 0.0077576084 kPa/level(or channel)
	return (double)p_val*0.0077576084;
}

int mmToSteps(double deepness){
	//Calibration:
	//    distance: 2007 mm
	//    no. of steps: 39106 steps
	//    ratio: 19.4848 steps/mm
	return (int) (deepness*19.4848) + CALIB_OFFSET;
}
