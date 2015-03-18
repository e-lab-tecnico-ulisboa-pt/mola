#ifndef ADC_H
#define	ADC_H

#define N_RESULTS 512

typedef struct {
    int status;
    int data[N_RESULTS];

} adcvector;

typedef struct {
    int edge;
    unsigned int level;
    unsigned int delta;
    unsigned int armed;
} trigger;

enum edge {
    RISING,
    FALLING,
    EVERY
};

enum status {
    EMPTY,
    RUN,
    FULL
};

extern adcvector resultados;
extern int x;
extern void init_ADC(void);
extern trigger trig1;

#endif	/* ADC_H */

