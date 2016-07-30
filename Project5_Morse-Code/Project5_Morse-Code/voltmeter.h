/*
 * voltmeter.h
 *
 * Created: 5/21/2016 7:46:55 PM
 *  Author: Tej Vuligonda
 */ 


#ifndef VOLTMETER_H_
#define VOLTMETER_H_

struct voltages {
	unsigned int inst_voltage;
	unsigned int average;
	unsigned int total;
	unsigned int count;
	unsigned int max;
	unsigned int min;
};

void init_registers();
struct voltages calc_adc(unsigned int average, unsigned int total, unsigned int count, unsigned int max, unsigned int min);


#endif /* VOLTMETER_H_ */