#include <iostream>
#include <cstring>

using namespace std;

/*
Code by Michael Yan 9/24/19

This code runs a simple palindrome finder. It takes in user input as a character array,
then filters out any punctuation. It then checks if the char array matches itself, but
printed backwards. If it does, it tells the user that a palindrome has been found.

 */

int main() {

  cout << "Type in a palindrome: " << endl;
  
  char str[80]; //initialize char array with a limited length, also taking userinput into the array
  cin.get(str, 80);

  char userInput[80]; //new char array to store filtered version without any punctuation

  int h = 0; //initializing variables for manipulating arrays
  
  for(int i = 0; str[i] != '\0'; i++){ //cycling through array

    if(str[i] >= 'a' && str[i] <= 'z'){ //checks for non punctuation characters
      userInput[h++] = str[i]; //if not punctuation, store in new array
      }
    else if(str[i] >= 'A' && str[i] <= 'Z'){ //checking for capitals
      str[i] = char(tolower(str[i])); //convert to lowercase and back to char
      userInput[h++] = str[i];
      }
    if(str[i+1] == '\0'){ //placing null at end of new array
      userInput[h] = str[i+1];
    }
  }

  
  int l = 0; //initializing variables for manipulating array
  int b = strlen(userInput)-1;
  int x = strlen(userInput)-1;

  userInput[x] == '\0';
  
  
  for(userInput[l]; userInput[l] != '\0'; l++, b--){ //cycles thru char array from the front and the back
    if(userInput[l] == userInput[b]){
    }
    /*    else if(userInput[l] == userInput[b]){ //check if first and last char are the same
      }*/
      else{
	cout << userInput;
	cout << " is not a palindrome." << endl;
	return 0; //if forwards and backwards don't match
      }
  }
  
  cout << userInput;
  cout << " is a palindrome!" <<endl; //tell user a palindrome is found

  return 0;
}
