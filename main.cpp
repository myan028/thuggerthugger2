#include <iostream> //imports
#include <cstring>
#include <iterator>
#include <vector>

#include "media.h"
#include "media.cpp"
#include "game.h"
#include "game.cpp"
#include "movie.h"
#include "movie.cpp"
#include "music.h"
#include "music.cpp"

using namespace std;


/*
Code by Michael Yan 11/5/19
This code is a class-based library which the user can store media (games, movies, and music) in.
*/

//makes use of goto

int main(){ //main method
  vector<Media*> medias; //vector stores all the medias used by classes
  while(true){
	theStart:
	cout << "\nType 'add', 'search', 'delete', or 'quit' for actions: ";
    char input[10];
    cin.getline(input, 10);
	cin.clear();
	//cin.ignore(1000, '\n');
    if(strcmp(input, "add") == 0){ //if user wants to add media
		char mediaType[10]; //initializing variables for storing user input
		char *title = new char[100];
		int year;
		//goToHere:
		cout << "\nWhat type of media would you like to add? Type 'game', 'movie', or 'music': "; //user prompt
		cin.getline(mediaType, 10);
		cin.clear();
		//cin.ignore(1000, '\n');
		goto goOverHere;	//ensure correct order of prompt and userinput
		goToHere: //yes
		cout << "Enter the title: ";
		cin.getline(title, 100);
		cin.clear();
		//cin.ignore(1000, '\n');
		cout << "Enter the year: ";
		cin >> year;
		/*if(cin.fail()){
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "The year must be an integer." << endl;
			goto goToHere;
		}*/
		
		cin.get();
		
		if(strcmp(mediaType, "game") == 0){//used in conjunction with all the goto's to make sure order of prompt and printing is correct
			goto goHere1; //after prompting used by all media types, go to individual media type prompts
		}
		else if(strcmp(mediaType, "movie") == 0){
			goto goHere2;
		}
		else if(strcmp(mediaType, "music") == 0){
			goto goHere3;
		}
		
		
		
		
		goOverHere: //come to if's first

		if (strcmp(mediaType, "game") == 0){ //prompt if user wants to store game
			goto goToHere;
			goHere1:
			char *publisher = new char[100];
			float rating;
			cout << "Enter the publisher's name: ";
			cin.getline (publisher, 100);
			cin.clear();
			//cin.ignore(1000, '\n');
			cout << "Enter the game's rating (1 to 5 stars): ";
			cin >> rating;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "The rating must be an integer." << endl;
				goto goToHere;
			}
			cin.get();
			Game* temp = new Game(title, year, publisher, rating);
			medias.push_back(temp);//adds to the end of the vector
		} 
		else if (strcmp(mediaType, "movie") == 0){ //prompt if user wants to store movie
			goto goToHere;
			goHere2:
			char *director = new char[100];
			int duration;
			float rating;
			cout << "Enter the director's name: ";
			cin.getline(director, 100);
			cin.clear();
			//cin.ignore(1000, '\n');
			cout << "Enter the movie's duration (in minutes): ";
			cin >> duration;
			cin.clear();
			
			/*do{
			cin >> duration;
				if(cin.fail()){
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "You must input an integer." << endl;
				}
			}
			while(!(cin >> duration));*/
			
			cin.get();
			cout << "Enter the movie's rating (1 to 5 stars): ";
			cin >> rating;
			if(cin.fail()){
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "The rating must be an integer." << endl;
				goto goToHere;
			}
			cin.get();
			Movie* temp = new Movie(title, year, director, duration, rating);
			medias.push_back(temp); //add to end of vector
		}
		else if (strcmp(mediaType, "music") == 0){ //prompt if user wants to store music
			goto goToHere;
			goHere3:
			char *artist = new char[100];
			int duration;
			char *publisher = new char[100];
			cout << "Enter the artist's name: ";
			cin.getline(artist, 100);
			cin.clear();
			//cin.ignore(1000, '\n');
			cout << "Enter the song's duration (in seconds): ";
			cin >> duration;
			cin.get();
			cout << "Enter the publisher's name: ";
			cin.getline(publisher, 100);
			cin.clear();
			//cin.ignore(1000, '\n');
			Music* temp = new Music(title, year, artist, publisher, duration);
			medias.push_back(temp); //add to end of vector
		}
		else{ // if (strcmp(mediaType, "yeet") == 0){
			cout << "That media type is not recognized." << endl; //if they don't type one of the three media types supported
			//continue;
			//break;
			//goto goToHere; //please work! //wait i know what to do
			continue;
		}
    }
	
	else if(strcmp(input, "search") == 0){ //if user wants to search
		cout << "How would you like to search for media? Type 'title' or 'year': ";
		char *searchField = new char[10];
		cin.getline(searchField, 10);
		cin.clear();
		vector<Media*>::iterator it; //initializing the iterator for searching
		//int count = 0;
		if (strcmp(searchField, "title") == 0) { //prompt if the user wants to search by the title
			char *searchTitle = new char[100];
			cout << "\nEnter the title of the media you would like to search for: ";
			cin.getline(searchTitle, 100);
			cin.clear();
			for(it = medias.begin(); it != medias.end(); it++) { //iterate through the vector
				if (strcmp((*it)->getTitle(), searchTitle ) == 0) { //if userinput matches media in database
					switch((*it)->getType()) {
						case 1: //movie
							cout << " " << endl;
							((Movie*)(*it))->displayInfo();
							break;
						case 2: //music
							cout << " " << endl;
							((Music*)(*it))->displayInfo();
							break;
						default: //game
							cout << " " << endl;
							((Game*)(*it))->displayInfo();
					}
					//count++;
				}
			}
		}
		else if (strcmp(searchField, "year") == 0){ //prompt if the user wants to search by year
			int searchYear;
			cout << "\nEnter the year of the media you would like to search for: ";
			cin >> searchYear;
			//cin.ignore(1000, '\n');
			cin.get();
			for(it = medias.begin(); it != medias.end(); it++) {
				if ((*it)->getYear() == (searchYear)) {
					switch((*it)->getType()) {
						case 1: //movie
							cout << " " << endl;
							((Movie*)(*it))->displayInfo();
							break;
						case 2: //music
							cout << " " << endl;
							((Music*)(*it))->displayInfo();
							break;
						default: //game
							cout << " " << endl;
							((Game*)(*it))->displayInfo();
					}
					//count++;
				}
			}
		}
		else{ //if user doesn't enter a supported search method
			cout << "\nThat search method is not recognized." << endl;
			continue;
		}
    }
	
	else if(strcmp(input, "delete") == 0){ //if user wants to delete something
		char *deleteField = new char[10];
		char *yesNo = new char[4];
		cout << "How would you like to delete media? Type 'title' or 'year': "; //choice
		cin.getline(deleteField, 10);
		cin.clear();
		vector<Media*>::iterator it; //initializing the iterator for delete searching
		if(strcmp(deleteField, "title") == 0) { //prompt if the user wants to delete by title
			cout << "\nEnter the title of the media you would like to delete: ";
			char *deleteTitle = new char[100]; //userinput for searching by title
			cin.getline(deleteTitle, 100);
			cin.clear();
			//cin.ignore(1000, '\n');
			for(it = medias.begin(); it != medias.end();){
				if(strcmp((*it)->getTitle(),deleteTitle) == 0) { //if an item in the database matches user input
					switch((*it)->getType()) {
						case 1: //movie
							cout << " " << endl;
							((Movie*)(*it))->displayInfo();
							break;
						case 2: //music
							cout << " " << endl;
							((Music*)(*it))->displayInfo();
							break;
						default: //game
							cout << " " << endl;
							((Game*)(*it))->displayInfo();
					}
					cout << "\nPlease confirm you would like to delete this media (Type 'yes' or 'no'): ";
					cin.getline(yesNo, 4);
					cin.clear();
					//cin.ignore(1000, '\n');
					if(strcmp(yesNo, "yes") == 0){//if user confirms yes, delete the media
					  delete * it;
					  it = medias.erase(it);
					  //goto theStart;
					  break;
					}
					else if(strcmp(yesNo, "no") == 0){ //move on if user doesn't want to delete
					  ++it;
					}
					else{ //user has to type yes or no
					  cout << "\nThat is not a valid confirmation option. You must type 'yes' or 'no'." << endl;
					  ++it;
					  break;
					}
				}
				else{
				cout << "\nThe media entry you have entered was not found." << endl; //if there is no media in the database matching userinput
				++it;
				}
			}
		}
		else if (strcmp(deleteField, "year") == 0){ //prompt if the user wants to delete by year
			cout << "\nEnter the year of the media you would like to delete: ";
			int deleteYear; //userinput for searching year
			cin >> deleteYear;
			cin.clear();
			cin.get();
			int index = 0;
			for(it = medias.begin(); it != medias.end();){
				if ((*it)->getYear() == (deleteYear)){ //if an item in the database matches user input
					switch((*it)->getType()) {
						case 1: //movie
							cout << " " << endl;
							((Movie*)(*it))->displayInfo();
							break;
						case 2: //music
							cout << " " << endl;
							((Music*)(*it))->displayInfo();
							break;
						default: //game
							cout << " " << endl;
							((Game*)(*it))->displayInfo();
					}
					cout << "\nPlease confirm you would like to delete this media (Type 'yes' or 'no'): ";
					cin.getline(yesNo, 4);
					cin.clear();
					//cin.ignore(1000, '\n');
					if(strcmp(yesNo, "yes") == 0){ //if user confirms yes, delete the media
					  delete * it;
					  it = medias.erase(it);
					  //goto theStart;
					  break;
					}
					else if(strcmp(yesNo, "no") == 0){ //move on if user doesn't want to delete
					  ++it;
					}
					else{
					  cout << "\nThat is not a valid confirmation option. You must type 'yes' or 'no'." << endl;
					  ++it;
					  break;
					}
				}
				else{
				++it;
				}
			}
		}
		
		else{ //if user doesn't enter a supported delete method
		cout << "\nThat delete method is not recognized." << endl;
		continue;
		}
    }
	
	else if(strcmp(input, "quit") == 0){
      break;//quit program
    } 
	
	else{ //if user doesn't enter a supported action
      cout << "\nThat action is not recognized.";
      continue;
    }
  }
}
