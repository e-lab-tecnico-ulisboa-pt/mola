#ifndef TODO_H
#define	TODO_H

#define DACMAX 4096
#define T_DACMAX 64    //resolucao do dac * 2
#define MEMMAX 64 //Resolucao do sin
#define PI 3.14159266


extern int (*funcao)();

extern void calculaseno();
extern int triangular(int tempo);
extern int denteserra(int tempo);
extern int seno (int tempo);

extern int enable;

#endif	/* TODO_H */

