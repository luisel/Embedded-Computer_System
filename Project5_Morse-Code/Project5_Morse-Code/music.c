/*
 * CFile1.c
 *
 * Created: 5/3/2016 7:32:12 PM
 *  Author: Tej Vuligonda
 */ 
#include "music.h"
#include "avr.h"


void wait_avr_music(unsigned short msec)
{
  TCCR0 = 2;
  while (msec--) {
    TCNT0 = (unsigned char)(256 - (XTAL_FRQ / 8) * 0.00001);
    SET_BIT(TIFR, TOV0);
    WDR();
    while (!GET_BIT(TIFR, TOV0));
  }
  TCCR0 = 0;
}

void play_note(int freq, int dur)
{
	for(int i = 0; i < (dur); i++)
	{
		SET_BIT(PORTB,3);
		wait_avr_music(freq);
		CLR_BIT(PORTB,3);
		wait_avr_music(freq);
	}
	
}

void play_note_volume(int freq, int dur, double ratio, int tempo) {
	int duration = (dur)/tempo;
	for(int i = 0; i < duration; i++)
	{
		SET_BIT(PORTB,3);
		wait_avr_music(freq*(1-ratio));
		CLR_BIT(PORTB,3);
		wait_avr_music(freq*ratio);
	}
	
}

void play_music(struct note *song,int numNotes)
{
	for (int i = 0;  i < numNotes; i++)
	{
		if ((i > 0) && (song[i].freq == song[i-1].freq)) {
			// int delay = song[i].duration * 0.01;
			wait_avr_music(5);
		}
		play_note(song[i].freq, song[i].duration);
		
		
	}
}

void play_music_volume(struct note *song,int numNotes, double ratio, int tempo)
{
	for (int i = 0;  i < numNotes; i++)
	{
		if ((i > 0) && (song[i].freq == song[i-1].freq)) {
			// int delay = song[i].duration * 0.01;
			wait_avr_music(5);
		}
		play_note_volume(song[i].freq*2, (song[i].duration), ratio, tempo);
		
		
	}
}

void playHotCrossBuns(int tempo, double volumeRatio) {
	//hot cross buns: bb aa gggg bb aa gggg g g g g a a a a gg bb aa
	int numNotesCross = 17;

	struct note hot_cross_buns[] = {
		{101.2391674,493.88}, // b
		{113.6363636,440}, // a
		{127.5510204,(392*2)}, // g for 2 seconds
		{101.2391674,493.88},
		{113.6363636,440},
		{127.5510204,(392*2)},
		{127.5510204,(392/2)},
		{127.5510204,(392/2)},
		{127.5510204,(392/2)},
		{127.5510204,(392/2)},
		{113.6363636,(440/2)},
		{113.6363636,(440/2)},
		{113.6363636,(440/2)},
		{113.6363636,(440/2)},
		{101.2391674,493.88},
		{113.6363636,440},
		{127.5510204,(392*2)}
	};
	   
	play_music_volume(hot_cross_buns, numNotesCross, volumeRatio, tempo);
}

void playABC(int tempo, double volumeRatio) {
	// twinkle twinkle little star (Same as ABC's)
	// c c g g a a gg f f e e d d cc g g f f e e dd c c g g a a gg f f e e d d cc
	
	int numNotesABC = 35;
	   
	struct note twinkle[] = {
		{191.1095822,261.63}, //c
		{191.1095822,261.63},
		{127.5510204,392}, //g
		{127.5510204,392},
		{113.6363636,440}, //a
		{113.6363636,440},
		{127.5510204,(392*2)},
		{143.1721215,349.23}, //f
		{143.1721215,349.23},
		{151.6852228,329.63}, //e
		{151.6852228,329.63},
		{170.2649322,293.66}, //d
		{170.2649322,293.66},
		{191.1095822,(261.63*2)},
		{127.5510204,392}, //g
		{127.5510204,392},
		{143.1721215,349.23}, //f
		{143.1721215,349.23},
		{151.6852228,329.63}, //e
		{151.6852228,329.63},
		{170.2649322,(293.66*2)},
		{191.1095822,261.63}, //c
		{191.1095822,261.63},
		{127.5510204,392}, //g
		{127.5510204,392},
		{113.6363636,440}, //a
		{113.6363636,440},
		{127.5510204,392*2},
		{143.1721215,349.23}, //f
		{143.1721215,349.23},
		{151.6852228,329.63}, //e
		{151.6852228,329.63},
		{170.2649322,293.66}, //d
		{170.2649322,293.66},
		{191.1095822,(261.63*2)},
				 
   };
   
   
   play_music_volume(twinkle, numNotesABC, volumeRatio, tempo);
}
