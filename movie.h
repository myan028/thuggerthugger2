#ifndef MOVIE_H //header
#define MOVIE_H

#include "media.h"

#include <iostream>
#include <cstring>

class Movie:public Media{
	public: //initialize getters, getType, printer, constructor, destructor
		Movie(char* newTitle,int newYear,  char* director, int duration, float newRating); //variables used by main
		~Movie();
		int getDuration();
		char* getDirector();
		float getRating();
		void displayInfo();
		int getType();
	private: //only accesible by movies class
		char* director;
		int duration;
		float rating;
};

#endif