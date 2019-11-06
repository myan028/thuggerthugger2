#include <iostream>
#include <cstring>

#include "media.h"

using namespace std;

Media::Media(char* newTitle, int newYear) {//constructor for media
  title = newTitle;//these are used for all medias
  year = newYear;
  
}



char* Media::getTitle(){//returns pointer for the class's information
  return title;
}

int Media::getYear(){
  return year;
}


Media::~Media() {//destructor for all medias
  delete []title;
}

void Media::displayInfo(){//print function for this class (all media)
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
}


int Media::getType(){//default type
  return 0;
}