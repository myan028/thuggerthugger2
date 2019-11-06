#ifndef MUSIC_H //header
#define MUSIC_H

#include "media.h"

#include <iostream>
#include <cstring>

class Music:public Media{
	public: //initialize getters, getType, printer, constructor, destructor
		Music(char* newTitle, int newYear, char* newArtist, char* newPublisher, int newDuration); //variables used by main
		~Music();
		char* getArtist();
		char* getPublisher();
		int getDuration();
		void displayInfo();
		int getType();
	private: //variables only accesible by music class
		char* artist;
		char* publisher;
		int duration;
};

#endif