/*
 * keypad.c
 *
 * Created: 5/9/2016 4:06:24 PM
 *  Author: Tej Vuligonda
 */ 

#include "keypad.h"
#include "avr.h"

unsigned char pressed(int r, int c) {
	// PUT ALL ROW AND COL PINS TO NO-CONNECT (DDR = 0, PORT = 0)
	// PUT THE r-th ROW TO '0'
	// PUT THE c-th COL to 'Z'
	// GET THE c-th COL (return 0 or 1, depending of PIN's status)
	DDRC = 0;
	PORTC = 0;

	SET_BIT(PORTC,r);
	SET_BIT(DDRC,c+4);
	CLR_BIT(PORTC,c+4);

	if(!GET_BIT(PINC,r))
	return 1;

	return 0;
}

unsigned char get_key() {
	unsigned char r,c;
	for (r = 0; r < 4; ++r) {
		for (c = 0; c < 4; ++c) {
			if (pressed(r,c)) {
				return (r*4) + c + 1;
			}
		}
	}
	return 0;
}
