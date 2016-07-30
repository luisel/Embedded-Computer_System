/*
 * Project5.c
 *
 * Created: 5/30/2016 10:30:00 PM
 * Author : Tej Vuligonda & Luis Lopez
 */ 

#include "avr.h"
#include "lcd.h"
#include "keypad.h"
//#include "voltmeter.h"
#include "music.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[5] = "12";
char b[5] = "2111";
char c[5] = "2121";
char d[5] = "211";
char e[5] = "1";
char f[5] = "1121";
char g[5] = "221";
char h[5] = "1111";
char i[5] = "11";
char j[5] = "1222";
char k[5] = "212";
char l[5] = "1211";
char m[5] = "22";
char n[5] = "21";
char o[5] = "222";
char p[5] = "1221";
char q[5] = "2212";
char r[5] = "121";
char s[5] = "111";
char t[5] = "2";
char u[5] = "112";
char v[5] = "1112";
char w[5] = "122";
char x[5] = "2112";
char y[5] = "2122";
char z[5] = "2211";

//Arrays to store phrase to put on LCD
char line1[17] = "";
char line2[17] = "";


// ascii for . is 46
// ascii for - is 45


int get_morse_char(int* gmc)
{
	set_lcd_lines("1 .|2 -|D STOP", "# END CHAR|* END");
	//wait_avr(1000);
	//static int morse_char[5];
	int counter = 0;
	while (1) {
		//wait_avr(150);
		unsigned char key_1 = get_key();
		//wait_avr(100);
		if (counter >= 4)
			return counter;
		if (key_1 == 1) {
			gmc[counter] = 1;
			counter++;
			play_note(90.9090909,550/6); // 550 Hz for 0.25 sec
			key_1 = get_key();
			while(key_1 == 1)
			{
				key_1 = get_key();
				clr_lcd();
				//wait_avr(20);
			}
		}
		else if (key_1 == 2){
			gmc[counter] = 2;
			counter++;
			play_note(90.9090909,550/3); // 550 Hz for 0.5 sec
			key_1 = get_key();
			while(key_1 == 2)
			{
				key_1 = get_key();
				clr_lcd();
				//wait_avr(20);
			}
		}
		else if (key_1 == 13)
			return 0;
		else if (key_1 == 15)
			return counter;
		else if(key_1 == 16)
			return -1;
		
	}
	
	
}

void get_morse_word(char* letter, char* buf, int* gmc, int gmc_size, char* gmw)
{
	if(!gmw || gmc_size < 1)
		return;
	//puts_lcd2(gmw);
	//wait_avr(1000);
	clr_lcd();
	memset(&letter[0], 0, sizeof(letter));
	for(int i = 0; i < gmc_size; i++)
	{
		sprintf(buf, "%d", gmc[i]);
		strcat(letter, buf);
	}
	//puts_lcd2("Letter:");
	//puts_lcd2(letter);
	//wait_avr(1000);
	clr_lcd();
	if (atoi(letter) == atoi(a))
		strcat(gmw, "A");		
	else if(atoi(letter) == atoi(b))
		strcat(gmw, "B");
	else if(atoi(letter) == atoi(c))
		strcat(gmw, "C");
	else if(atoi(letter) == atoi(d))
		strcat(gmw, "D");
	else if(atoi(letter) == atoi(e))
		strcat(gmw, "E");
	else if(atoi(letter) == atoi(f))
		strcat(gmw, "F");
	else if(atoi(letter) == atoi(g))
		strcat(gmw, "G");
	else if(atoi(letter) == atoi(h))
		strcat(gmw, "H");
	else if(atoi(letter) == atoi(i))
		strcat(gmw, "I");
	else if(atoi(letter) == atoi(j))
		strcat(gmw, "J");
	else if(atoi(letter) == atoi(k))
		strcat(gmw, "K");
	else if(atoi(letter) == atoi(l))
		strcat(gmw, "L");
	else if(atoi(letter) == atoi(m))
		strcat(gmw, "M");
	else if(atoi(letter) == atoi(n))
		strcat(gmw, "N");
	else if(atoi(letter) == atoi(o))
		strcat(gmw, "O");
	else if(atoi(letter) == atoi(p))
		strcat(gmw, "P");
	else if(atoi(letter) == atoi(q))
		strcat(gmw, "Q");
	else if(atoi(letter) == atoi(r))
		strcat(gmw, "R");
	else if(atoi(letter) == atoi(s))
		strcat(gmw, "S");
	else if(atoi(letter) == atoi(t))
		strcat(gmw, "T");
	else if(atoi(letter) == atoi(u))
		strcat(gmw, "U");
	else if(atoi(letter) == atoi(v))
		strcat(gmw, "V");
	else if(atoi(letter) == atoi(w))
		strcat(gmw, "W");
	else if(atoi(letter) == atoi(x))
		strcat(gmw, "X");
	else if(atoi(letter) == atoi(y))
		strcat(gmw, "Y");
	else if(atoi(letter) == atoi(z))
		strcat(gmw, "Z");
	//letter = "";
	//free(buf);
	//free(letter);
}

int main(void)
{
	ini_lcd();
	set_lcd_lines("Press A to start", "Press * to quit");
	SET_BIT(DDRB, 3);
	//play_note(101.23,493);
	
	// keypad: 1 (key == 1) -> short press
	// keypad: 2 (key == 2) -> long press?
	// keypad: # (key == 15) -> separate letters
	// keypad: D (key == 16) -> separate words
	// keypad: * (key == 13) -> end session
		
	//stores char
	int gmc[5];
	int gmc_size;
	//stores word
	
	char gmd[17] = "";
	int gmw_amount = 0;
	
	int check = 1;
	
	
	static char buf[1] = "";
	static char letter[5] = "";	


	for (;;){
			
		unsigned char key = get_key();
		wait_avr(150);
			
		if (key == 13){
			clr_lcd();
			break;
		}
		// start sampling
		else if (key == 4)
		{
			clr_lcd();
			while(1)
			{
				gmc_size = get_morse_char(gmc);
				clr_lcd();
				get_morse_word(buf, letter, gmc, gmc_size, gmd);
				
				if (gmc_size == -1)
				{
					gmw_amount++;
					strcat(gmd, " ");
				}
				else if (gmc_size > 0)
				{
					gmw_amount++;
					if (gmw_amount == 32)
					{
						strcat(line2, gmd);
						memset(&gmd[0], 0, sizeof(gmd));
						check = 0;
					}
					else if (gmw_amount == 16)
					{
						strcat(line1, gmd);
						memset(&gmd[0], 0, sizeof(gmd));

					}
				}
				else if (gmc_size == 0)
					break;
					
					
				if (gmw_amount < 16)
				{
					puts_lcd2(gmd);
					wait_avr(2000);
				}
				else if (gmw_amount >= 16 && gmw_amount < 32)
				{
					set_lcd_lines(line1, gmd);
					wait_avr(2000);
				}
				
				clr_lcd();
				
				if (check == 0)
					break;
			}
			set_lcd_lines(line1, line2);
			//wait_avr(5000);
			break;
			//gmw_amount = 0;
			//check = 1;
			//memset(&line1[0], 0, sizeof(line1));
			//memset(&line2[0], 0, sizeof(line2));
		}
	}
	return 0;
}



