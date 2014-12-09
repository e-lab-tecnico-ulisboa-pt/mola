#ifndef UART2_H
#define	UART2_H

#define INPUTFMAX 3                     //number of functions compared
#define INPUTVMAX 2                     //number of variables compared

extern unsigned int UMODEvalue, U2STAvalue, str_pos; //auxiliary UART config variables
extern char RXbuffer[80];

extern unsigned int srv, pos, fr;

extern void init_UART2();
extern int poliglota();
extern void pull_UART2();
extern void push_UART2();
extern void __attribute__((__interrupt__,auto_psv)) _U2RXInterrupt(void);

#endif	/* UART2_H */

