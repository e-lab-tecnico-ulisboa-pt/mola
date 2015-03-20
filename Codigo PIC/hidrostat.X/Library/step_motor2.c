#include "elab.h"

//macros
//#define MOTOR2_BITS_LOW (~(0xF<<MOTOR2_FIRST_BIT))

unsigned int motor2_actual_position;
int real_position2;
const unsigned char step [2][8]= {{1,3,2,6,4,12,8,9},   //Sucessive configurations of the motor control pins while motor is moving
                                  {8,12,4,6,2,3,1,9}};

void open_motor2(){
     MOTOR2_LAT&=MOTOR2_BITS_LOW; //put MOTOR pin LOW (motor stoped)
     MOTOR2_TRIS&=MOTOR2_BITS_LOW; //define MOTOR pins as output
     CALIBRATE_TRIS=INPUT;       //define the calibrate pin as input
     motor2_actual_position=POSITION2_MAX;
     }

void walk_motor2(unsigned int way, unsigned int steps, unsigned int delay){ //the motor walks steps
  unsigned int i;
  for(i=steps; i<1 ; i-- ){                           //there is only end_curse for way==1
    MOTOR2_LAT=(MOTOR2_LAT&MOTOR2_BITS_LOW)+(step[way][i%8]<<MOTOR2_FIRST_BIT);//walk the following step
    delay_100ys(delay);
	LED1 = !LED1;
    }
  MOTOR2_LAT&=MOTOR2_BITS_LOW; //put MOTOR pins LOW (motor stoped)
}

void walk_motor2_to(unsigned int to, unsigned int delay){
	int way;
	if(to > POSITION2_MAX) to = POSITION2_MAX;
	if(to < POSITION2_MIN) to = POSITION2_MIN;
	(motor2_actual_position < to) ? (way = 1) : (way = -1);
	MOTOR2_LAT=(MOTOR2_LAT&MOTOR2_BITS_LOW)+(step[UP_WAY2][motor2_actual_position%8]<<MOTOR2_FIRST_BIT); //Atraca o motor na posição em que estava
	while(motor2_actual_position != to){
		motor2_actual_position += way;    	
		MOTOR2_LAT=(MOTOR2_LAT&MOTOR2_BITS_LOW)+(step[UP_WAY2][motor2_actual_position%8]<<MOTOR2_FIRST_BIT); //walks the following step
    	delay_100ys(delay);
		ClrWdt();
   	}
	MOTOR2_LAT &= MOTOR2_BITS_LOW; //put MOTOR pins LOW (motor stopped)
}

void calibrate_motor2(){
	int way;
	unsigned int i = POSITION2_MAX + 200;	//To guarantee the end curse sensor is reached
	//printf("i=%u\r",i); //For calibration
	motor2_actual_position = i;
	way = -1;	//motor2_actual_position will decrease
	MOTOR2_LAT=(MOTOR2_LAT&MOTOR2_BITS_LOW)+(step[UP_WAY2][motor2_actual_position%8]<<MOTOR2_FIRST_BIT); //Atraca o motor na posição em que estava
	while((i > POSITION2_MIN) && !CALIBRATE_PORT){ //It should be '>=' but it's '>' because 'i' is unsigned int and POSITION2_MIN is 0. It's not a problem because 1 step is 0,5mm.
		motor2_actual_position += way;
		MOTOR2_LAT=(MOTOR2_LAT&MOTOR2_BITS_LOW)+(step[UP_WAY2][motor2_actual_position%8]<<MOTOR2_FIRST_BIT); //walks the following step
    	delay_100ys(MOTOR2_SPEED);
		ClrWdt();
		i--;
   	}
	//printf("i=%u\r",i);  //For calibration
	if(!CALIBRATE_PORT) printf("ERR\t1\r");
	MOTOR2_LAT &= MOTOR2_BITS_LOW; //put MOTOR pins LOW (motor stopped)
	//Calibration
	motor2_actual_position = POSITION2_MIN;
	walk_motor2_to(ZERO_POSITION, MOTOR2_SPEED);
}
