#include <p30F4011.h>		//defines dspic registers
#include <libpic30.h>		//C30 compiler definitions
#include<adc10.h>//POR ISTO NA ADC.H


#include "adc.h"
#include "io.h"
#include "uart2.h"

void init_ADC(void) {



    /*
    ADPCFG = 0b1111111111111111; //set AN0 and AN1 as analog inputs 

    ADCON1bits.FORM = 0b00; //Data Output Format bits (integer)
    ADCON1bits.SSRC = 0b111; //Conversion Trigger Source Select bits (Internal counter ends sampling and starts conversion (auto convert))
    ADCON1bits.SIMSAM = 1; //Simultaneous Sample Select bit NÃO ACHO QUE SEJA NECESSÁRIO
    ADCON1bits.ASAM = 1; //Sampling begins immediately after last conversion completes. SAMP bit is auto set
    ADCON1bits.SAMP = 0; //A/D Sample Enable bit

    ADCON2bits.VCFG = 0b000; //Voltage Reference Configuration bits (AVDD e AVSS)
    ADCON2bits.CSCNA = 0; //Scan Input Selections for CH0+ S/H Input for MUX A (NÃO SEI SCAN )
    ADCON2bits.CHPS = 0b00; //Selects Channels Utilized bits (ONLY CHANNEL 0)
    ADCON2bits.SMPI = 0; //Sample/Convert Sequences Per Interrupt Selection (Interrupts at the completion of conversion for each sample/convert sequence)
    ADCON2bits.BUFM = 0; //buffer is a 16-word
    ADCON2bits.ALTS = 1; //Uses MUX A input multiplexer settings for first sample, then alternate between MUX B and MUX A input multiplexer settings for all subsequent samples

    ADCON3bits.SAMC = 0b0010; //Auto-Sample Time bits (1 TAD) ALTEREI VALOR
    ADCON3bits.ADRC = 1; //A/D Conversion Clock Source bit (Clock derived from system clock)
    ADCON3bits.ADCS = 0b1000; //conversion clock (TCY/2*(ADCS+1)) (16 TCY) ALTEREI VALOR


    //Leituras feitas pelo channel 0
    //ADCHSbits.CH0NA = 0; //Channel 0 negative input is VREF- for MUX A Secalhar não é preciso por negativos
    ADCHSbits.CH0SA = 0; //Channel 0 positive input is AN0  for MUX A
    //ADCHSbits.CH0NB = 0; //Channel 0 negative input is VREF- for MUX B 
    ADCHSbits.CH0SB = 1; //Channel 0 positive input is AN1   for MUX B

    //ADCSSL = 0b0000000000000001; //

    ADCON1bits.ADON = 1; //A/D converter module is operating
    IFS0bits.ADIF = 0; //clear adc interrupt flag
    IEC0bits.ADIE = 1; //enable adc end of sampling 

    unsigned int ADCvar1, ADCvar2, ADCvar3, PINCONFIG, SCANCONFIG;

    //2a Configuração
     ADCvar1 =
            ADC_MODULE_ON //ADC on
            & ADC_IDLE_CONTINUE
            & ADC_FORMAT_INTG //formato do resultdo
            & ADC_CLK_AUTO // clock automatico interior termina sampling
            & ADC_AUTO_SAMPLING_ON//repeticao automatica
            & ADC_SAMPLE_INDIVIDUAL
            & ADC_SAMP_ON; //inicia automaticamente a amostragem
    ADCvar2 =
            ADC_VREF_AVDD_AVSS // Intervalo tensao 5V-0V
            & ADC_SCAN_OFF
            & ADC_CONVERT_CH0 // Apenas usa Canal 0
            & ADC_SAMPLES_PER_INT_1
            & ADC_ALT_INPUT_ON
            & ADC_ALT_BUF_ON;
    ADCvar3 =
            ADC_SAMPLE_TIME_12 // Tempo de amostragem TAD
            & ADC_CONV_CLK_SYSTEM //Clock interno
            & ADC_CONV_CLK_8Tcy; //TAD=8TCY

    PINCONFIG = ENABLE_AN0_ANA & ENABLE_AN1_ANA;

    SCANCONFIG = SCAN_NONE;

    SetChanADC10(ADC_CH0_POS_SAMPLEA_AN0 & ADC_CH0_NEG_SAMPLEA_NVREF
            & ADC_CH0_POS_SAMPLEB_AN1 & ADC_CH0_NEG_SAMPLEB_NVREF );
    OpenADC10(ADCvar1, ADCvar2, ADCvar3, PINCONFIG, SCANCONFIG);
*/
    //ConfigIntADC10(ADC_INT_PRI_3 & ADC_INT_DISABLE);

 ADPCFG = 0b1111111111111100;

    ADCON1bits.FORM = 0b00; //Data Output Format bits
    ADCON1bits.SSRC = 0b111; //Conversion Trigger Source Select bits
    ADCON1bits.SIMSAM = 1; //Simultaneous Sample Select bit
    ADCON1bits.ASAM = 1; //A/D Sample Auto-Start bit
    ADCON1bits.SAMP = 0; //A/D Sample Enable bit

    ADCON2bits.VCFG = 0b000; //Voltage Reference Configuration bits
    ADCON2bits.CSCNA = 0; //Scan Input Selections for CH0+ S/H Input for MUX A
    ADCON2bits.CHPS = 0b01; //Selects Channels Utilized bits
    ADCON2bits.SMPI = 0b1111; //Sample/Convert Sequences Per Interrupt Selection
    ADCON2bits.BUFM = 0; //buffer is a 16-word
    ADCON2bits.ALTS = 0; //Always use MUX A Input multiplexer settings

    ADCON3bits.SAMC = 0b1010; //Auto-Sample Time bits
    ADCON3bits.ADRC = 0; //A/D Conversion Clock Source bit
    ADCON3bits.ADCS = 0b111111; //conversion clock (TCY/2*(ADCS+1))

    ADCHSbits.CH123NA = 0b00; //CH1, CH2, CH3 negative input is VREF-
    ADCHSbits.CH123SA = 0; //CH1 positive input is AN3, CH2 positive input is AN4, CH3 positive input is AN5
    ADCHSbits.CH0NA = 0; //Channel 0 negative input is VREF-
    ADCHSbits.CH0SA = 1; //Channel 0 positive input is AN0

    ADCSSL = 0b0000000000000011; //Select AN2, AN3 for input scan

    ADCON1bits.ADON = 0; //enable ad converter
    IFS0bits.ADIF = 0; //clear adc interrupt flag
    IEC0bits.ADIE = 1; //enable adc end of sampling

}



void __attribute__((interrupt, no_auto_psv)) _ADCInterrupt(void) {
    IFS0bits.ADIF = 0;
     //LED1 = !LED1;
      ADCON1bits.ADON = 0;
}

void Read_ADC(void) {

    int adcpot, adcsensor, adc, i;

    //LEITURA DE ADC

    //leitura dos dois primeiros buffers
    //ADCON1bits.SAMP = 1;
   // while (ADCON1bits.DONE == 0);




    pos = ADCBUFD;
    fr = ADCBUFE;

    //printf("%i \n", adcpot);
    //printf("%i \n", adcsensor);
/*

        //leitura de todos os buffers
    
        i=0;
            while(i<16)
            {
                adc = ReadADC10(i);
                printf("%d \n", adc);
                i++;
            }
*/

}