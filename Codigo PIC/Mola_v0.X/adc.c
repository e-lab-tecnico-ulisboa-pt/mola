#include <p30F4011.h>		//defines dspic registers
#include <libpic30.h>		//C30 compiler definitions

#include "adc.h"
#include "io.h"

void init_ADC(void) {
    ADPCFG = 0b1111111111111110;

    ADCON1bits.FORM = 0b00; //Data Output Format bits
    ADCON1bits.SSRC = 0b111; //Conversion Trigger Source Select bits
    ADCON1bits.SIMSAM = 1; //Simultaneous Sample Select bit
    ADCON1bits.ASAM = 0; //A/D Sample Auto-Start bit
    ADCON1bits.SAMP = 0; //A/D Sample Enable bit

    ADCON2bits.VCFG = 0b000; //Voltage Reference Configuration bits
    ADCON2bits.CSCNA = 0; //Scan Input Selections for CH0+ S/H Input for MUX A
    ADCON2bits.CHPS = 0b00; //Selects Channels Utilized bits
    ADCON2bits.SMPI = 0; //Sample/Convert Sequences Per Interrupt Selection
    ADCON2bits.BUFM = 0; //buffer is a 16-word
    ADCON2bits.ALTS = 0; //Always use MUX A Input multiplexer settings

    ADCON3bits.SAMC = 0b0001; //Auto-Sample Time bits
    ADCON3bits.ADRC = 0; //A/D Conversion Clock Source bit
    ADCON3bits.ADCS = 0b10000; //conversion clock (TCY/2*(ADCS+1))

    ADCHSbits.CH123NA = 0b00; //CH1, CH2, CH3 negative input is VREF-
    ADCHSbits.CH123SA = 1; //CH1 positive input is AN3, CH2 positive input is AN4, CH3 positive input is AN5
    ADCHSbits.CH0NA = 0; //Channel 0 negative input is VREF-
    ADCHSbits.CH0SA = 0; //Channel 0 positive input is AN0

    ADCSSL = 0b0000000000000001; //Select AN2, AN3 for input scan

    ADCON1bits.ADON = 1; //enable ad converter
    IFS0bits.ADIF = 0; //clear adc interrupt flag
    IEC0bits.ADIE = 1; //enable adc end of sampling
}


void __attribute__((interrupt, no_auto_psv)) _ADCInterrupt(void) {
    IFS0bits.ADIF = 0;

}