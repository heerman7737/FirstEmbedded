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
 
	unsigned char tmpA ;
	unsigned char tmpB ;
	unsigned char tmpC ;
	unsigned char tmpD ;
	unsigned char total;
while(1) {
	tmpA = PINA ;
	tmpB = PINB ;
	tmpC = PINC ;

	total = tmpA + tmpB + tmpC;

	
	if( tmpA-tmpC >= 0x50 || tmpC-tmpA >= 0x50 ){
		tmpD = total>>2 &0xFE;
	}
	else if( total>= 0x8C){
                tmpD = total>>2 |0x01;
        }

	else{
		tmpD = total;
	}
	PORTD = tmpD;
}
	return 0;
}


