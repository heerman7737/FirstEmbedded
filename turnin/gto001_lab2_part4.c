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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00; 
 
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	char diff;
	unsigned int total;
while(1) {
	tmpA = PINA & 0xFF;
	tmpB = PINB & 0xFF;
	tmpC = PINC & 0xFF;

	total = tmpA + tmpB + tmpC;

	if( tmpA+tmpB+tmpC >= 0x8C){
		tmpD = 0x01;
	}
	else if( tmpA-tmpC >= 0x50 || tmpC-tmpA >= 0x50 ){
		tmpD = 0x02;
	}
	else{
		tmpD = total & 0xFC;
	}
	PORTD = tmpD;
}
	return 0;
}


