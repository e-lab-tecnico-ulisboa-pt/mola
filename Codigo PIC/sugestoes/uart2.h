#ifndef UART2_H
#define	UART2_H

#define INPUTFMAX 3                     //number of functions compared
#define INPUTVMAX 2                     //number of variables compared

typedef struct //Text to function(void)
{
    char *text;
    int (*job)();
} bibf;

typedef struct //Text to variables
{
    char *text;
    int *var;
} bibv;

extern unsigned int UMODEvalue, U2STAvalue, str_pos; //auxiliary UART config variables
extern char RXbuffer[80];
extern int delta, time;
extern unsigned int duty;

extern void init_UART2();
extern void init_bib();
extern int poliglota();
extern void pull_UART2();
extern void __attribute__((__interrupt__,auto_psv)) _U2RXInterrupt(void);

#endif	/* UART2_H */

