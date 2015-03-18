#ifndef IO_H
#define	IO_H

#define INPUT   1
#define OUTPUT  0

#define LED1_TRIS   TRISCbits.TRISC14
#define LED2_TRIS   TRISCbits.TRISC13
#define PWM1_TRIS   TRISDbits.TRISD0
#define PWM2_TRIS   TRISDbits.TRISD1
#define PWM3_TRIS   TRISDbits.TRISD2
#define PWM4_TRIS   TRISDbits.TRISD3
#define BOTAO_TRIS  TRISEbits.TRISE8
#define SEL_TRIS    TRISBbits.TRISB0
#define ENTRA_TRIS  TRISDbits.TRISD2

#define LED1    LATCbits.LATC14
#define LED2    LATCbits.LATC13
#define PWM1    LATDbits.LATD0
#define PWM2    LATDbits.LATD1
#define PWM3    LATDbits.LATD2
#define PWM4    LATDbits.LATD3
#define BOTAO   !PORTEbits.RE8
#define ENTRA   PORTDbits.RD2
#define SEL     LATBbits.LATB0

#define FCY ((long) 73728*4) 		//instruction frequency in kHz
extern void init_io(void);

#endif	/* IO_H */

