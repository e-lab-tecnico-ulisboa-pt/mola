/* 
 * File:   tm1640.c
 * Author: Rafael Henriques (IPFN)
 *
 * Created on January 2014
 * 
 * Uses two pins to comunicate with tm1640 IC
 * This program uses the delay_1ys() function present in delays.c
 * See pin selection in user_defines.h
 *
 */

#include "elab.h"

// 7 (+1 - dot) segment display:
//         1
//      -------
//     |       |
//  32 |       | 2
//     |  64   |
//      -------
//     |       |
//  16 |       | 4
//     |   8   |
//      -------  o 128
unsigned int int2segs[10] = {127-64, 2+4, 1+2+64+16+8, 1+2+64+4+8, 32+64+2+4, 1+32+64+4+8, 127-1-2, 1+2+4, 127, 127-16-8};

//Configure ports to comunicate with tm1640
void configure_tm1640(void){
	TRIS_CLK = 0;
	TRIS_DOUT = 0;
	CLK = 1;
	DOUT = 1;
}

void sendC1(unsigned int set_data){
	int mask = 0b00000001;
	int n;
	DOUT = 0;
	delay_1ys(TWAIT);
	for(n=0;n<8;n++){
		CLK = 0;
		delay_1ys(TWAIT);
		DOUT = (set_data & mask)/mask;
		mask = mask << 1;
		delay_1ys(TLOW);
		CLK = 1;
		delay_1ys(THIGH);
	}
	CLK = 0;
	delay_1ys(TWAIT);
	DOUT = 0;
	delay_1ys(TLOW);
	CLK = 1;
	delay_1ys(TWAIT);
	DOUT = 1;
	delay_1ys(TWAIT);
}

void sendC2(unsigned int set_add){
	int mask = 0b00000001;
	int n;
	DOUT = 0;
	delay_1ys(TWAIT);
	for(n=0;n<8;n++){
		CLK = 0;
		delay_1ys(TWAIT);
		DOUT = (set_add & mask)/mask;
		mask = mask << 1;
		delay_1ys(TLOW);
		CLK = 1;
		delay_1ys(THIGH);
	}
}

void sendDATA(unsigned int data){
	int mask = 0b00000001;
	int n;
	for(n=0;n<8;n++){
		CLK = 0;
		delay_1ys(TWAIT);
		DOUT = (data & mask)/mask;
		mask = mask << 1;
		delay_1ys(TLOW);
		CLK = 1;
		delay_1ys(THIGH);
	}
}

void sendC3(unsigned int disp_ctl){
	int mask = 0b00000001;
	int n;
	CLK = 0;
	delay_1ys(TWAIT);
	DOUT = 0;
	delay_1ys(TLOW);
	CLK = 1;
	delay_1ys(TWAIT);
	DOUT = 1;
	delay_1ys(THIGH);
	DOUT = 0;
	delay_1ys(TWAIT);
	for(n=0;n<8;n++){
		CLK = 0;
		delay_1ys(TWAIT);
		DOUT = (disp_ctl & mask)/mask;
		mask = mask << 1;
		delay_1ys(TLOW);
		CLK = 1;
		delay_1ys(THIGH);
	}
	CLK = 0;
	delay_1ys(TWAIT);
	DOUT = 0;
	delay_1ys(TLOW);
	CLK = 1;
	delay_1ys(TWAIT);
	DOUT = 1;
	delay_1ys(TWAIT);
}

void writeAllDisplay(unsigned int grids[16], unsigned int dispLightInt){
	//dispLightInt: [136-143]
	int n;
	sendC1(0b01000000); //Normal mode, Address auto-add 1
	sendC2(0b11000000); //Display Address 00H
	for(n=0;n<16;n++){
		sendDATA(grids[n]);
	}
	sendC3(dispLightInt);
}

void DisplayOFF(void){
	int n;
	sendC1(0b01000000); //Normal mode, Address auto-add 1
	sendC2(0b11000000); //Display Address 00H
	for(n=0;n<16;n++){
		sendDATA(0);
	}
	sendC3(0b10000000);
}

//Converts a int digit to 7 segment display digit
unsigned int int2seg(int digit, int dot, int minus){
	unsigned int seg=0;
	if((digit < 0) || (digit > 9)) return(0); //return all segments 'OFF'
	if(minus == 1) return((unsigned int) 64);
	seg = int2segs[digit];
	if(dot == 1) seg += 128; //128 corresponds to dot
	return(seg);
}

//Converts a float (-999 to 9999) up to noGridsON (max. 4) girds, starting from
//right to left
void floatTo4grids(unsigned int grids[4], float number, int noGridsON){
	int n=0, i=0, dot;
	int digits[10];
	float div=1000.;

	for(;n<4-noGridsON;n++) grids[n] = int2seg(-1,0,0); //grid OFF
	if((number<0) && (n<4)){ //n<4 to avoid segmentation fault when noGridsON is 0
		grids[n++] =  int2seg(0,0,1); //insert a minus signal in the first ON grid
		number = number * -1; //put the signal positive
	}

	//converting a float to a vector of integers
	while(i<10){
		digits[i] = (int) (number/div);
		number -= digits[i]*div;
		if(div==1) dot = i;
		div /= 10.;
		i++;
	}

	i = 0;
	while((i<10) && (n<4)){
		while((digits[i]==0) && (i<dot)) i++;
		if(i==dot)
			grids[n++] = int2seg((unsigned int) digits[i],1,0);
		else
			grids[n++] = int2seg((unsigned int) digits[i],0,0);
		i++;
	}
}

void floatsTo4x4grids(unsigned int grids[16], float num1, float num2, float num3, float num4, int noGridsON){
	unsigned int grid[4];
	int n;
	floatTo4grids(grid, num1, noGridsON);
	for(n=0;n<4;n++) grids[n]= grid[n];
	floatTo4grids(grid, num2, noGridsON);
	for(n=4;n<8;n++) grids[n]= grid[n%4];
	floatTo4grids(grid, num3, noGridsON);
	for(n=8;n<12;n++) grids[n]= grid[n%4];
	floatTo4grids(grid, num4, noGridsON);
	for(n=12;n<16;n++) grids[n]= grid[n%4];
}
