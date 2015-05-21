#ifndef IO_H
#define	IO_H

#define INPUT   1
#define OUTPUT  0

#define ON      1
#define OFF     0

#define LED1_TRIS   TRISCbits.TRISC14
#define LED2_TRIS   TRISCbits.TRISC13
#define PWM2_TRIS   TRISDbits.TRISD1
#define BOTAO_TRIS  TRISEbits.TRISE8
#define AN0_TRIS    TRISBbits.TRISB0
#define AN1_TRIS    TRISBbits.TRISB1
#define LIGHT_TRIS  TRISFbits.TRISF0

#define LED1    LATCbits.LATC14
#define LED2    LATCbits.LATC13
#define PWM2    LATDbits.LATD1
#define BOTAO   !PORTEbits.RE8
#define LIGHT   LATFbits.LATF0


#define HALFLENGTH 20 //mm

#define FCY ((long) 29491)  //instruction frequency in 10^2 Hz

extern void init_io(void);

#endif	/* IO_H */

