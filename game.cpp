#include <iostream>
#include <cstring>

#include "game.h"

using namespace std;

Game::Game(char* newTitle, int newYear, char* newPublisher, float newRating) : Media(newTitle, newYear){//constructor for this class
  //title = newTitle; //these are used by all types of medias
  //year = newYear;
  
  rating = newRating;
  publisher = newPublisher;
}


char* Game::getPublisher(){//getter returns for this class's information
  return publisher;
}

float Game::getRating(){
  return rating;
}


Game::~Game(){//the destructor for this class
  delete []publisher;
}

void Game::displayInfo(){//print function for this class
  cout << "Title: " << getTitle() << endl;
  cout << "Year: " << getYear() << endl;
  cout << "Rating: " << getRating() << endl;
  cout << "Publisher: " << getPublisher() << endl;
}


int Game::getType(){//game class designated to type 0
  return 0;
}

