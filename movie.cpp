#include <iostream>
#include <cstring>

#include "movie.h"

using namespace std;

Movie::Movie(char* newTitle, int newYear, char* newDirector, int newDuration, float newRating) : Media(newTitle, newYear){//constructor for this class
  /*title = newTitle; //these are used by all types of medias
  year = newYear;*/
  
  director = newDirector;
  rating = newRating;
  
  duration = newDuration;
  
}


char* Movie::getDirector(){//getter returns for this class's information
  return director;
}

int Movie::getDuration(){
	return duration;
}

float Movie::getRating(){
  return rating;
}


Movie::~Movie(){//the destructor for this class
  delete[] director;
  }
void Movie::displayInfo(){//print function for this class
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Director: " << getDirector() << endl;
  cout << "Rating: " << getRating() << endl;
  cout << "Duration: " << getDuration() << endl;
}

int Movie::getType(){//movie class designated to type 1
  return 1;
}