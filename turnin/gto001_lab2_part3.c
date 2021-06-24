/*	Author:Giang To  lab 2
 *
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
 
	unsigned char tmpA = 0x00;
	unsigned char cntavail =0x00;
while(1) {
		
	tmpA = PINA & 0x0F;

	if(tmpA == 0x00){
		cntavail =0x04;
	}	
	else if (tmpA == 0x01 || tmpA==0x02 || tmpA==0x04 || tmpA == 0x08) { 
		cntavail = 0x03; 
	} else if(tmpA ==0x03 || tmpA == 0x05 || tmpA == 0x09 || tmpA == 0x06||tmpA==0x0C ||tmpA ==0x0A){
		cntavail = 0x02; 
	}
	else if(tmpA == 0x07||tmpA == 0x0D||tmpA == 0x0E){
	        cntavail =0x01;
	}	
	else{
	       cntavail =0x00;
	}

	if(cntavail==0x00){
	PORTC = 0x80;
	}
	else{
	PORTC = cntavail;
	}
}
	return 0;
}


