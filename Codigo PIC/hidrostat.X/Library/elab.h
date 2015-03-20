#include <p30f4013.h>
#include <stdio.h>			//biblioteca standart IO do C
#include <libpic30.h>		//definicoes extra para as bibliotecas do C30
#include <uart.h>			//biblioteca com as funcoes para usar a UART (porta serie)
#include <string.h>
#include "user_defines.h"

#define INPUT  1
#define OUTPUT 0

//
// hidrostat.c
//
double adcTokPa(int p_val, int adc_offset);
int mmToSteps(double deepness);

//
// timer.c
//
void open_timer1(void);
void open_timer1_for_communication(void);

//
// delays.c
//
void delay_ms(unsigned int delay);
void delay_100ys(unsigned int delay);
void delay_10ys(unsigned int delay);
void delay_1ys(unsigned int delay);

//
// uart.c
//
typedef struct{
	char rbuf[80];
	char *receiveddata;
} Communication;

extern Communication Serial;

void configure_uart2(void);
int command_received(void);
extern int cmd_received;
void clear_rbuf(void);
void __attribute__((__interrupt__,auto_psv)) _U2RXInterrupt(void);

//
//adc.c
//
void configure_adc();
void configure_adc_channel(int);
int read_adc(int);

//
//step_motor2.c
//
#define MOTOR2_BITS_LOW (~(0xF<<MOTOR2_FIRST_BIT))
extern const unsigned char step [2][8];
extern unsigned int motor2_actual_position;
void open_motor2();
void walk_motor2(unsigned int way, unsigned int steps, unsigned int delay);
void walk_motor2_to(unsigned int to, unsigned int delay);
void calibrate_motor2();

//
//servo2.c
//
//void open_servo2();
//void move_servo2(unsigned int delay);


//
//captures.c
//
//extern unsigned int Capture_counter;
//void open_inputcapture1();

//
//(main_file).c
//
int main();
//void __attribute__((__interrupt__,auto_psv)) _ADCInterrupt();
//void __attribute__((__interrupt__,auto_psv)) _T3Interrupt(void);
//void __attribute__((__interrupt__,auto_psv)) _IC1Interrupt(void);

//
// rec_generic_driver.c
//
extern char state[20];
extern int stop;
void rec_generic_driver(void);


//
// maq_de_estados.c
//
extern int protocolo;
extern int param_1;
extern int param_2;
extern int param_3;
void maq_de_estados(void);


//
// protocolos.c
//
void protocolo_0_configuring(void);
void protocolo_1_configuring(void);
void protocolo_2_configuring(void);
void protocolo_3_configuring(void);
void protocolo_4_configuring(void);
void protocolo_1_starting(void);
void protocolo_2_starting(void);
void protocolo_3_starting(void);
void protocolo_4_starting(void);
void protocolo_1_started();
void protocolo_2_started();
void protocolo_3_started();
void protocolo_4_started();
void protocolo_5_started();
void protocolo_6_started();
void stopping();

//
// spi.c
//
void configure_spi(void);
void sendSPI(int data);

//
// tm1640.c
//
void configure_tm1640(void);
void sendC1(unsigned int set_data);
void sendC2(unsigned int set_add);
void sendDATA(unsigned int data);
void sendC3(unsigned int disp_ctl);
void writeAllDisplay(unsigned int grids[16],unsigned int dispLightInt);
void DisplayOFF(void);
unsigned int int2seg(int digit, int dot, int minus);
void floatTo4grids(unsigned int grids[4], float number, int noGridsON);
void floatsTo4x4grids(unsigned int grids[16], float num1, float num2, float num3, float num4, int noGridsON);
