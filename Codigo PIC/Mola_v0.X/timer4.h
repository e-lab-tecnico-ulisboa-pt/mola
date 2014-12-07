#ifndef TIMER1_H
#define	TIMER1_H

extern void init_TMR4(void);
extern void __attribute__((interrupt, no_auto_psv)) _T4Interrupt(void);


#endif	/* TIMER1_H */

