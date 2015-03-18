#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library
#include <string.h>
#include <math.h>

#include "uart2.h"
#include "io.h"
#include "timer2.h"
#include "timer3.h"
#include "timer4.h"
#include "oc.h"
#include "ic.h"
#include "delays.h"
#include "todo.h"
#include "adc.h"
#include "spi.h"



char inst,n[10];
int a,b, ninst=0;


int main() {

    init_UART2();
    init_io();

    init_TMR2();
    init_OC2();

    init_TMR4();
    //Comunicação
   
    init_ADC();

   pull_UART2();


    srv = 170;

    printf("teste\n");
    
    while (1) {


        inst=RXbuffer[str_pos -2];
        
        
        OC2RS = 332+358*srv/90;




          

          if(inst=='p'){

              pull_UART2();
              push_UART2();
             /*
              a=0;
             
                  strcpy(n, RXbuffer);
                  strcpy(srv,n );
                  a = sscanf(n, " %u \r", &srv);
                  //printf("%u", srv);
                  if(a==1) break;//push_UART2();}
                 // printf("t1\n");

              
               //a=RXbuffer[str_pos -2];
                  
              //poliglota();
             // push_UART2();//Envia as variaveis pos, srv, fr
              */
            OC2RS = 332+358*srv/90;
               //inst=RXbuffer[str_pos -2];
          }
         

           
            if(inst=='a') Read_ADC();
           



        if (inst=='t') break;

        //OC2RS = 332+358*srv/90; //Duty Time
    




    }
}