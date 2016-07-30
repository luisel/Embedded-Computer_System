/*
 * Project2_Clock.c
 *
 * Created: 4/27/2016 5:47:31 PM
 * Author : Tej Vuligonda
 */ 

#include <avr/io.h>
#include "avr.h"
#include "lcd.h"
#include "functions.h"

void
ini_avr(void)
{
	WDTCR = 15;
}

void
wait_avr(unsigned short msec)
{
	TCCR0 = 3;
	while (msec--) {
		TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 64) * 0.001);
		SET_BIT(TIFR, TOV0);
		WDR();
		while (!GET_BIT(TIFR, TOV0));
	}
	TCCR0 = 0;
}


int main(void)
{
    /* Replace with your application code */
	ini_lcd();
	
	unsigned char key = get_key();
	
	while (1) {
		key = get_key();
	
		if (key == 0){
			run_clock();
		}
	
		if(key == 13) {
			set_clock();
		}
	}

}

