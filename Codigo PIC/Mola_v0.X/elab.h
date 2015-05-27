#ifndef ELAB_H
#define	ELAB_H


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
extern void open_timer1(void);
extern void open_timer1_for_communication(void);


//
// uart.c
//
typedef struct{
	char rbuf[80];
	char *receiveddata;
} Communication;

extern Communication Serial;

extern void configure_uart2(void);
extern int command_received(void);
extern int cmd_received;
extern void clear_rbuf(void);
extern void __attribute__((__interrupt__,auto_psv)) _U2RXInterrupt(void);

//
//adc.c
//
extern void configure_adc();
extern void configure_adc_channel(int);
extern int read_adc(int);



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
extern void rec_generic_driver(void);


//
// maq_de_estados.c
//
extern int protocolo;
extern int param_1;
extern int param_2;
extern int param_3;
extern int param_4;
extern void maq_de_estados(void);


//
// protocolos.c
//

extern void protocolo_1_configuring(void);

extern void protocolo_1_starting(void);

extern void protocolo_1_started();

extern void stopping();

extern void servo_para_mm(int pw);
extern void servo_para_um(long pw);
extern void mede_em(int pw);

extern void configure_uart1(void);

#endif