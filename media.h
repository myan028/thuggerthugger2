#ifndef MEDIA_H //header
#define MEDIA_H


#include <iostream>
#include <cstring>

class Media{
	public: //initialize getters, getType, printer, constructor, destructor
		Media(char* newTitle, int newYear);
		virtual ~Media();
		char* getTitle();
		int getYear();
		void displayInfo();
		virtual int getType();
	private: //private, variables
		char* title;
		int year;//these are accessible by all 3 medias
};

#endif