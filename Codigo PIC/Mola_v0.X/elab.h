
#include <stdio.h>			//biblioteca standart IO do C
#include <libpic30.h>		//definicoes extra para as bibliotecas do C30
#include <uart.h>			//biblioteca com as funcoes para usar a UART (porta serie)
#include <string.h>
#include "user_defines.h"

#define INPUT  1
#define OUTPUT 0

//
// timer.c
//
void open_timer1(void);
void open_timer1_for_communication(void);


//
// uart.c
//
typedef struct{
	char rbuf[80];
	char *receiveddata;
} Communication;

extern Communication Serial;

void config_uart2(void);
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

void protocolo_1_configuring(void);

void protocolo_1_starting(void);

void protocolo_1_started();

void stopping();


