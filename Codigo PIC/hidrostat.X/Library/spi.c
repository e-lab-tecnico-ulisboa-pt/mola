#include "elab.h"

/*
 * Set all bits necessary to use the SPI port
 * We will use non framed operation, 16 bit words
 */
void configure_spi(void) {
	SPI1CONbits.MSTEN = 1;	//**Master Mode Enable bit**//
							//1 = Master mode
							//0 = Slave mode

	SPI1STATbits.SPISIDL = 0;	//**Stop in Idle Mode bit**//
								//1 = Discontinue module operation when device enters Idle mode
								//0 = Continue module operation in Idle mode

//	SPI1STATbits.SPITBF = 0;	//**SPI Transmit Buffer Full Status bit**//
								//1 = Transmit not yet started, SPIxTXB is full
								//0 = Transmit started, SPIxTXB is empty
								//Automatically set in hardware when CPU writes SPIxBUF location, loading SPIxTXB.
								//Automatically cleared in hardware when SPIx module transfers data from SPIxTXB to SPIxSR.

//	SPI1STATbits.SPIRBF = 0	//**SPI Receive Buffer Full Status bit**//
							//1 = Receive complete, SPIxRXB is full
							//0 = Receive is not complete, SPIxRXB is empty
							//Automatically set in hardware when SPIx transfers data from SPIxSR to SPIxRXB.
							//Automatically cleared in hardware when core reads SPIxBUF location, reading SPIxRXB.

	SPI1CONbits.FRMEN = 0;	//**Framed SPI Support bit**//
							//1 = Framed SPI support enabled
							//0 = Framed SPI support disabled

	SPI1CONbits.SPIFSD = 0;	//**Frame Sync Pulse Direction Control on SSx pin bit**//
							//1 = Frame sync pulse input (slave)
							//0 = Frame sync pulse output (master)

	SPI1CONbits.DISSDO = 0;	//**Disable SDOx pin bit**//
							//1 = SDOx pin is not used by module. Pin is controlled by associated port register.
							//0 = SDOx pin is controlled by the module

	SPI1CONbits.MODE16 = 0;	//**Word/Byte Communication Select bit**//
							//1 = Communication is word-wide (16 bits)
							//0 = Communication is byte-wide (8 bits)

	SPI1CONbits.SMP = 1;	//**SPI Data Input Sample Phase bit**//
							//Master mode:
							//1 = Input data sampled at end of data output time
							//0 = Input data sampled at middle of data output time
							//Slave mode:
							//SMP must be cleared when SPI is used in Slave mode.

	SPI1CONbits.CKE = 0;	//**SPI Clock Edge Select bit**//
							//1 = Serial output data changes on transition from active clock state to Idle clock state (see bit 6)
							//0 = Serial output data changes on transition from Idle clock state to active clock state (see bit 6)
							//Note: The CKE bit is not used in the Framed SPI modes. The user should program this bit to ‘0’ for the
							//Framed SPI modes (FRMEN = 1).

	SPI1CONbits.SSEN = 0;	//**Slave Select Enable (Slave mode) bit**//
							//1 = SS pin used for Slave mode
							//0 = SS pin not used by module. Pin controlled by port function.

	SPI1CONbits.CKP = 1;	//**Clock Polarity Select bit**//
							//1 = Idle state for clock is a high level; active state is a low level
							//0 = Idle state for clock is a low level; active state is a high level

	SPI1CONbits.SPRE = 0;	//**Secondary Prescale (Master Mode) bits**//
							//(Supported settings: 1:1, 2:1 through 8:1, all inclusive)
							//111 = Secondary prescale 1:1
							//110 = Secondary prescale 2:1
							//...
							//000 = Secondary prescale 8:1
							
	SPI1CONbits.PPRE = 0;	//**Primary Prescale (Master Mode) bits**//
							//11 = Primary prescale 1:1
							//10 = Primary prescale 4:1
							//01 = Primary prescale 16:1
							//00 = Primary prescale 64:1

	IFS0bits.SPI1IF = 0;	//**SPI1 Interrupt Flag Status bit**//
							//1 = Interrupt request has occurred
							//0 = Interrupt request has not occurred

	IEC0bits.SPI1IE = 1;	//**SPI1 Interrupt Enable bit**//
							//1 = Interrupt request enabled
							//0 = Interrupt request not enabled

	IPC2bits.SPI1IP = 3;	//**SPI1 Interrupt Priority bits**//
							//111 = Interrupt is priority 7 (highest priority interrupt)
							//...
							//001 = Interrupt is priority 1
							//000 = Interrupt source is disabled

	SPI1STATbits.SPIROV = 0;	//**Receive Overflow Flag bit**//
								//1 = A new byte/word is completely received and discarded. The user software has not read the previous data in the SPIxBUF register.
								//0 = No overflow has occurred
							
	SPI1STATbits.SPIEN = 0;	//**SPI Enable bit**//
							//1 = Enables module and configures SCKx, SDOx, SDIx and SSx as serial port pins
							//0 = Disables module

	//For TM1640 communication
	_TRISF3 = 0;			//SDO1 as normal digital output
	PORTFbits.RF3 = 1;		//SDO1 always at level 1
}

//Sends the word data to the SPI port
void sendSPI(int data) {
	//CS = 0;								//Set chip select to zero so that dac will listen
	SPI1STATbits.SPIEN = 0;
	_TRISF3 = 0;
	PORTFbits.RF3 = 1;
	SPI1STATbits.SPIEN = 1;
	//delay_10ys(1);
	while(SPI1STATbits.SPITBF == 1);	//Wait until transmit buffer is empty
	SPI1BUF = data;						//Copy data to SPI buffer and start transmission
	while(SPI1STATbits.SPIRBF == 0);	//Wait until transmission (and reception) finishes
	data = SPI1BUF;						//Read and discard received word, to avoid overflow condition 
	SPI1STATbits.SPIEN = 0;
	_TRISF3 = 0;
	PORTFbits.RF3 = 1;
	//CS = 1;								//Deselect chip
}

////Sends the Command1 to TM1640
//void sendC1(int data) {
//	SPI1STATbits.SPIEN = 1;
//	delay_10ys(1);
//	while(SPI1STATbits.SPITBF == 1);	//Wait until transmit buffer is empty
//	SPI1BUF = data;						//Copy data to SPI buffer and start transmission
//	while(SPI1STATbits.SPIRBF == 0);	//Wait until transmission (and reception) finishes
//	data = SPI1BUF;						//Read and discard received word, to avoid overflow condition 
//	SPI1STATbits.SPIEN = 0;
//	_TRISF3 = 0;
//	PORTFbits.RF3 = 1;
//	//CS = 1;								//Deselect chip
//}

//This interruption is generated after sending the entire 8 bits word.
void __attribute__((__interrupt__, __no_auto_psv__)) _SPI1Interrupt(void) {
	IFS0bits.SPI1IF = 0;
	SPI1STATbits.SPIROV = 0;		//Just in case, to avoid overflow and freeze of spi module
}
