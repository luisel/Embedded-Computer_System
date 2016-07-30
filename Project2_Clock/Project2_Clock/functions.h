/*
 * functions.h
 *
 * Created: 4/25/2016 6:06:12 PM
 *  Author: Tej
 */ 


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

void run_clock();
unsigned char is_key_13(unsigned char key);

unsigned char get_key();
unsigned char pressed(int r, int c);
unsigned char write_to_lcd();


void update_date();
int is31day(int month);
int is30day(int month);
int is_leap(int year);
int increment_sec(int secs);
int increment_min(int min);
int increment_hr(int hrs);
void increment_month();
void decrement_month();
void increment_day();
void decrement_day();
void increment_year();
void decrement_year();
void void_increment_hrs();
void decrement_hrs();
void void_increment_mins();
void decrement_mins();
void void_increment_secs();
void decrement_secs();

void print_date();
void print_time();



void set_clock();






#endif /* FUNCTIONS_H_ */