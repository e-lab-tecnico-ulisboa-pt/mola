#ifndef TIMER3_H
#define	TIMER3_H

#define PR3MAX  922
#define NBITS 9

extern void init_TMR3(void);
extern void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void);


#endif	/* TIMER3_H */

