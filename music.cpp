#include <iostream>
#include <cstring>

#include "music.h"

using namespace std;

Music::Music(char* newTitle, int newYear, char* newArtist, char* newPublisher, int newDuration ) : Media(newTitle, newYear){//constructor for this class
  //title = newTitle; 
  
  artist = newArtist;
  //year = newYear;
  
  publisher = newPublisher;
  duration = newDuration;
}


char* Music::getArtist(){//getter returns for this class's information
  return artist;
}

char* Music::getPublisher(){
  return publisher;
}

int Music::getDuration(){
  return duration;
}


Music::~Music(){//the destructor for this class
  delete[] publisher;
  delete[] artist;
}


void Music::displayInfo(){//print function for this class
  cout << "Title: " << getTitle() << endl;
  cout << "Artist: " << getArtist() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Publisher: " << getPublisher() << endl;
  cout << "Duration: " << getDuration() << endl;
}

int Music::getType(){//music class designated to type 2
  return 2;
}