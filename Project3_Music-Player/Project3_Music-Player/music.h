/*
 * music.h
 *
 * Created: 5/9/2016 4:04:50 PM
 *  Author: Tej Vuligonda
 */ 


#ifndef MUSIC_H_
#define MUSIC_H_

struct note {
	unsigned int freq;
	unsigned int duration;
};

void play_note(int freq, int dur);
void play_music(struct note *song,int numNotes);
void playHotCrossBuns(int tempo, double volumeRatio);
void playABC(int tempo, double volumeRatio);
void play_note_volume(int freq, int dur, double ratio, int tempo);
void play_music_volume(struct note *song,int numNotes, double ratio, int tempo);
void playHotCrossBunsVolume(int tempo);




#endif /* MUSIC_H_ */