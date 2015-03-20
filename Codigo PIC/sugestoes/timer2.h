#ifndef TIMER2_H
#define	TIMER2_H

extern void init_TMR2(void);
extern void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void);

#endif	/* TIMER2_H */

