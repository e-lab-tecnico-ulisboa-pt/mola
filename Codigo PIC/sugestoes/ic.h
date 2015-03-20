#ifndef IC_H
#define	IC_H

extern long ic1count, lastic1count;
void init_ic1(void);
void __attribute__((interrupt,no_auto_psv)) _IC1Interrupt(void);

#endif	/* IC_H */

