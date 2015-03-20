/* 
 * File:   newmain.c
 * Author: tpereira
 *
 * Created on 1 de Novembro de 2012, 12:53
 * 
 * Uses SPI port to communicate with DAC MCP4921
 *
 * Pin assignments on PIC
 *   CHIP SELECT -> RB4 (AN4, 4)
 *   SDO         -> RF3 (PGD, 25)
 *   SCK         -> RF6 (24)
 *   SDI is not used
 */

#include <p30F4011.h>		//defines dspic register locations and structures definitions
#include <math.h>			//defines dspic register locations and structures definitions

#define LED1 LATDbits.LATD3				//macro for led1
#define TOGGLE_LED1 asm("btg LATD, #3")	//macro for toggling led1
#define LED1_ON asm("bclr LATD, #3")	//macro for led1 on
#define LED1_OFF asm("bset LATD, #3")	//macro for led1 off

#define LED2 LATDbits.LATD2				//macro for led2
#define TOGGLE_LED2 asm("btg LATD, #2")	//macro for toggling led2
#define LED2_ON asm("bclr LATD, #2")	//macro for led2 on
#define LED2_OFF asm("bset LATD, #2")	//macro for led2 off

#define CS LATBbits.LATB4

//Configuration bits
_FOSC(CSW_FSCM_OFF & XT_PLL16);		//oscilator at 16x cristal frequency
_FWDT(WDT_OFF);  					//watchdog timer off

//Function prototypes
void configure_spi(void);
void delay_ms(unsigned int);

//Sends the word data to the SPI port
void sendSPI(int data) {
	CS = 0;								//Set chip select to zero so that dac will listen
	while(SPI1STATbits.SPITBF == 1);	//Wait until transmit buffer is empty
	SPI1BUF = data;						//Copy data to SPI buffer and start transmission
	while(SPI1STATbits.SPIRBF == 0);	//Wait until transmission (and reception) finishes
	data = SPI1BUF;						//Read and discard received word, to avoid overflow condition 
	CS = 1;								//Deselect chip
}

//Implements MCP4921 serial protocol
void setDAC(int val) {
	val &= 0x0FFF;		//Format data according to MCP4921 serial interface protocol
	val |= 0x3000;		//Idem
	sendSPI(val);
}


//This interruption is generated after sending the entire 16 bits word.
void __attribute__((__interrupt__, __no_auto_psv__)) _SPI1Interrupt(void) {
	IFS0bits.SPI1IF = 0;
	TOGGLE_LED2;
	SPI1STATbits.SPIROV = 0;		//Just in case, to avoid overflow and freeze of spi module
}


int main() {	
	//Set the led pins to outputs
	TRISDbits.TRISD2 = 0;
	TRISDbits.TRISD3 = 0;

	//1 = chip not selected
	CS = 1;
	
	//Configuration of the CS pin. CS pin is changed in sendSPI()
	TRISBbits.TRISB4 = 0;
	ADPCFGbits.PCFG4 = 1; //1 = Digital

	//Configure and open the SPI module
	configure_spi();

	while(1) {
		TOGGLE_LED1;
		setDAC(0);
		delay_ms(10);
		
		TOGGLE_LED1;
		setDAC(2048);
		delay_ms(10);
		
		TOGGLE_LED1;
		setDAC(4095);
		delay_ms(10);
		
		TOGGLE_LED1;
		setDAC(2048);
		delay_ms(10);
	}
}
