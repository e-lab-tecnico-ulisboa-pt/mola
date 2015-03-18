#ifndef SPI_H
#define	SPI_H

extern void init_SPI1();
extern void __attribute__((interrupt, no_auto_psv)) _SPI1Interrupt(void);
extern void write_SPI1(int digital_level);

#endif	/* SPI_H */

