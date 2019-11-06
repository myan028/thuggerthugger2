#ifndef GAME_H //header
#define GAME_H

#include "media.h"

#include <iostream>
#include <cstring>

class Game:public Media{
	public: //initialize getters, getType, printer, constructor, destructor
		Game(char* newTitle, int newYear, char* newPublisher, float newRating); //variables used by main
		~Game();
		char* getPublisher();
		float getRating();
		void displayInfo();
		int getType();
	private: //variables only accesible by game class
		char* publisher;
		float rating;
};

#endif