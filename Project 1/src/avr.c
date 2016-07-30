/*
 * avr.c
 *
 * Created: 4/5/2016 5:28:23 PM
 * Author : Luis
 */ 

#include <avr/io.h>
#include "avr.h"

void
ini_avr(void)
{
}

void
wait_avr(unsigned short msec)
{
	TCCR0 = 3;
	while (msec--) {
		TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 64) * 0.001);
		SET_BIT(TIFR, TOV0);
		while (!GET_BIT(TIFR, TOV0));
	}
	TCCR0 = 0;
}
void wait(unsigned long n)
{
	volatile int i;
	volatile int j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			//do nothing
		}
	}

}


int main(void)
{
    /* Replace with your application code */
	DDRB = 0x01;
    while (1) 
    {
		if(!GET_BIT(PINB, 1))
		{
			SET_BIT(PORTB, 0);
			//wait(150);
			wait_avr(500);
			CLR_BIT(PORTB, 0);
			//wait(150);
			wait_avr(500);
		}
    }
}

