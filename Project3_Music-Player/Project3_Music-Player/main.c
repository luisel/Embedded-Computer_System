/*
 * Project3_Music-Player.c
 *
 * Created: 4/27/2016 5:20:06 PM
 * Author : Tej Vuligonda
 */ 

#include <avr/io.h>
#include "avr.h"
#include "lcd.h"
#include "keypad.h"
#include "music.h"
#include <math.h>

// static double const tenToNegativeSix = pow(10.0,-6.0);


int main(void)
{
   /* Replace with your application code */
   
   DDRB = 0x01 << 3;
   
   ini_lcd();
   pos_lcd(0,0);
   puts_lcd2("1:Hot Cross Buns");
   pos_lcd(1,0);
   puts_lcd2("2:ABC's");
   //LCD HAS 16 CHARACTERS MAX
   
	while (1) {
		for (;;) {
			unsigned char key = get_key();
			if (key == 1) {
				playHotCrossBuns(1,0.5);
			}
			if (key == 2) {
				playABC(1,0.5);
			}
			if (key == 5) { // keypad: 4
				playHotCrossBuns(1,0.99); // lower volume
			}
			if (key == 6) { // keypad: 5
				playABC(1,0.99); // lower volume
			}
			if (key == 9) { // keypad: 7
				playHotCrossBuns(2,0.5); // twice as fast
			}
			if (key == 10) { // keypad: 8
				playABC(2,0.5); // twice as fast
			}
		}
  
	}

   return 0;

}

