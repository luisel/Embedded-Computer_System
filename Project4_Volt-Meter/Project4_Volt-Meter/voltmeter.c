/*
 * voltmeter.c
 *
 * Created: 5/21/2016 7:47:07 PM
 *  Author: Tej Vuligonda
 */ 

#include "avr.h"
#include "voltmeter.h"
#include <stdio.h>




void init_registers() {
	// SET_BIT(ADMUX,1);
	// SET_BIT(ADMUX,6);
	
	// ADMUX = (1 << 6) | (1 << 1) | (1 << 0);
	ADMUX = (1 << REFS0);
	// ADMUX = (1 << REFS0) | (1 << MUX1) | (1 << MUX0);
	
	
	ADCSRA = (1 << ADEN) | (1 << ADSC);
	/*
	ADCSRA |= _BV (ADEN);
	Bit 7 – ADEN: Set this to binary 1 to enable the microcontroller ADC circuits, whilst binary 0 will switch it OFF.

	ADCSRA |= _BV (ADSC);
	Bit 6 – ADSC: Setting ADSC bit to binary 1 starts the conversion process. This bit clears automatically when the conversion process completes. Therefore, this bit provides an indication that the conversion has completed.
	*/
}

struct voltages calc_adc(unsigned int average, unsigned int total, unsigned int count, unsigned int max, unsigned int min)
{
	ADCSRA = (1 << ADEN) | (1 << ADSC);
	unsigned int inst_voltage = 5*((ADC)/10.23);	
	total += inst_voltage;
	count++;
	if (inst_voltage > max) {
		max = inst_voltage;
	}
	if (inst_voltage < min) {
		min = inst_voltage;
	}
	average = total/count;
	struct voltages values = {
		inst_voltage,
		average,
		total,
		count,
		max,
		min,
		};
	
	return values;
	//return inst_voltage;
}

/*
struct voltages {
	unsigned int inst_voltage;
	unsigned int average;
	unsigned int total;
	unsigned int count;
	unsigned int max;
	unsigned int min;
};
*/