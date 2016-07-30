#include "functions.h"
#include "avr.h"
#include "lcd.h"
#include <stdio.h>



char buf[17];
int secs = 55;
int mins = 59;
int hrs = 23;
	
int month = 4;
int day = 26;
int year = 2016;

void run_clock()
{
	unsigned char key = get_key();
	//sprintf(buf, "0%d/%2d/%4d", month, day, year);
	//puts_lcd2(buf);
	print_date();
	//puts_lcd2(buf);
	//pos_lcd(1,0);
	
	
	
	
	if((secs = increment_sec(secs)) == 60)
	{
		secs = 0;
		if((mins = increment_min(mins)) == 60)
		{
			mins = 0;
			if((hrs = increment_hr(hrs)) == 24) {
				hrs = 0;
				update_date();
			}
			
		}
			
	}
		
	print_time(hrs,mins,secs);
	if (key == 13) {
		return;
	}
	wait_avr(1000);
	pos_lcd(1,0);
		
	/*
	unsigned char key = get_key();
		
	// 3*4 + 0 + 1 = 12+1 = 13
	if (key != 0) { //counter == 7get_key() == #) {
		set_clock();
		break;
	}
	*/
		
	

}

unsigned char is_key_13(unsigned char key) {
	key = get_key();
	if (key == 13)
		return 1;
	return 0;
}

void print_time() {
	if (hrs<10 && mins < 10 && secs < 10)
	{
		sprintf(buf,"0%d:0%d:0%d",hrs,mins,secs);
	}
	else if (hrs <10 && mins<10 && secs >=10)
	{
		sprintf(buf,"0%d:0%d:%2d",hrs,mins,secs);
	}
	else if(hrs <10 && mins>=10 && secs >=10)
	{
		sprintf(buf,"0%d:%2d:%2d",hrs,mins,secs);
	}
	else if(hrs>=10 && mins<10 && secs >=10)
	{
		sprintf(buf,"%2d:0%d:%2d",hrs,mins,secs);
	}
	else if(hrs>=10 && mins>=10 && secs <10)
	{
		sprintf(buf,"%2d:%2d:0%d",hrs,mins,secs);
	}
	else if(hrs <10 && mins>=10 && secs < 10)
	{
		sprintf(buf,"0%d:%2d:0%d",hrs,mins,secs);
	}
	else if(hrs>=10 && mins<10 && secs <10)
	{
		sprintf(buf,"%2d:0%d:0%d",hrs,mins,secs);
	}
	else {
		sprintf(buf,"%2d:%2d:%2d",hrs,mins,secs);
	}
	
	puts_lcd2(buf);
}

void update_date() {
  
	if (day >= 31 && is31day(month)){
		day = 1;
		if (month == 12){
			month = 1;
			year = year + 1;
		}
	}
	else if (day >= 30 && is30day(month)){
		day = 1;
		month = month + 1;
	}
	else if(month == 2 && is_leap(year) && day >= 29){
  		day = 1;
		month = month + 1;
	}
	else if(month == 2 && !is_leap(year) && day >= 28){
   		day = 1;
		month = month + 1;
	}
	else {
		day = day + 1;
	}
	
	print_date(month,day,year);
  
  
}
void print_date() {
  
  	if (month<10 && day < 10)
	{
		sprintf(buf,"0%d/0%d/%4d",month,day,year);
	}
	else if (month <10 && day>=10)
	{
		sprintf(buf,"0%d/%2d/%4d",month,day,year);
	}
	else if(month >=10 && day<10)
	{
		sprintf(buf,"%2d/0%d/%4d",month,day,year);
	}
	else if(month>=10 && day>=10)
	{
		sprintf(buf,"%2d/%2d/%4d",month,day,year);
	}
	
  	pos_lcd(0,0);
	puts_lcd2(buf);
	pos_lcd(1,0);
	
}

int is31day(int month) {
	return (month == 1 || month == 3 || month == 5 ||month == 7 || month == 8 || month == 10 || month == 12);
}

int is30day(int month) {
	return (month == 4 || month == 6 || month == 9 ||month == 11);
}

int is_leap(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}



int increment_sec(int secs){
	return secs + 1;
}

int increment_min(int mins){
	return mins + 1;
}

int increment_hr(int hrs){
	return hrs +  1;
}

void increment_month() {
	if (month == 12) {
		month = 1;
	}
	else {
		month = month + 1;
	}
}

void decrement_month() {
	if (month == 1) {
		month = 12;
	}
	else {
		month = month - 1;
	}
}

void increment_day() {
	if (day >= 31 && is31day(month)){
		day = 1;
	}
	else if (day >= 30 && is30day(month)){
		day = 1;
	}
	else if(month == 2 && is_leap(year) && day >= 29){
		day = 1;
	}
	else if(month == 2 && !is_leap(year) && day >= 28){
		day = 1;
	}
	else {
		day = day + 1;
	}
}

void decrement_day() {
	if (day == 1 && is31day(month)){
		day = 31;
	}
	else if (day == 1 && is30day(month)){
		day = 30;
	}
	else if(month == 2 && is_leap(year) && day == 1){
		day = 29;
	}
	else if(month == 2 && !is_leap(year) && day == 1){
		day = 28;
	}
	else {
		day = day - 1;
	}
}

void increment_year() {
	year = year + 1;
}

void decrement_year() {
	year = year - 1;
}

void void_increment_hrs() {
	if (hrs == 23) {
		hrs = 0;
	}
	else {
		hrs = hrs + 1;
	}
}
void decrement_hrs() {
	if (hrs == 0) {
		hrs = 23;
	}
	else {
		hrs = hrs - 1;
	}	
}

void void_increment_mins() {
	if (mins == 59) {
		mins = 0;
	}
	else {
		mins = mins + 1;
	}
}

void decrement_mins() {
	if (mins == 0) {
		mins = 59;
	}
	else {
		mins = mins - 1;
	}
	
}

void void_increment_secs() {
	if (secs == 59) {
		secs = 0;
	}
	else {
		secs = secs + 1;
	}
}

void decrement_secs() {
	if (secs == 0) {
		secs = 59;
	}
	else {
		secs = secs - 1;
	}
}



void check_key(unsigned char key) {
	if (key == 1) {
		increment_month();
	}
	else if (key == 2) {
		decrement_month();
	}
	else if (key == 3) {
		increment_day();
	}
	else if (key == 4) { // keypad: A
		decrement_day();
	}
	
	else if (key == 5) { // keypad: 4
		increment_year();
	}
	else if (key == 6) { // keypad: 5
		decrement_year();
	}
	else if (key == 7) { // keypad: 6
		void_increment_hrs();
	}
	else if (key == 8) { // keypad: B
		decrement_hrs();
	}
	else if (key == 9) { // keypad: 7
		void_increment_mins();
	}
	else if (key == 10) { // keypad: 8
		decrement_mins();
	}
	else if (key == 11) { // keypad: 9
		void_increment_secs();
	}
	else if (key == 12) { // keypad: C
		decrement_secs();
	}
	
}

void blink_lcd() {
	unsigned char key = get_key();
	while (1) { // loop until key is pressed
		// blinks the date
		key = get_key();
		print_date();
		key = get_key();
		print_time();
		key = get_key();
		wait_avr(500);
		key = get_key();
		clr_lcd();
		key = get_key();
		wait_avr(500);
		key = get_key();
		if (key != 0) {
			check_key(key);
			break;
		}
	}
}

void set_clock() {
	// blink_lcd();
	unsigned char key = get_key();
	while(1) {
		key = get_key();
		print_date(); // pause at current date
		print_time(); // pause at current time
		wait_avr(150);
		if (key == 15) {
			break;
		}
		check_key(key);
	}
		
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



/*
write_to_lcd() {
*/
	// #include <stdio.h>*/
/*	
	char buf[17];
	sprintf(buf,"%2d/%2d/%4d",(int)date.month,(int)date.day,(int)date.year);
	puts_lcd2(buf);
}

int main() {
	CLR_BIT(DDRB,1);
	SET_BIT(PORTB,1);
	for (;;) {
		if (!GET_BIT(PIN,1)) {
			
		}
		else {
			
		}
	}
}
*/