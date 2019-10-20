#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>

using namespace std;

/*
Code by Michael Yan 10/19/2019

This code runs a simple student list editor. You can add and remove students from a list, and print that list out.
The code supports information about a student's first and last name, student id, and GPA.
*/

struct Student{ //struct including student info
  char firstName[10];
  char lastName[10];
  int id;
  float gpa;
};

//Student* ADD();

//void PRINT(vector<Student*> students);
//void DELETE(vector<Student*>* students, int id);

Student* ADD(){ //add function
  Student* newStudent = new Student(); //store the new student in heap
  cout << "\nEnter the student's first name: ";
  cin >> newStudent->firstName;
  cin.clear(); //clear for next input (many)
  cin.ignore(999, '\n');
  cout << "Enter the student's last name: ";
  cin >> newStudent->lastName;
  cin.clear();
  cin.ignore(999, '\n');
  cout << "Enter their student id: ";
  cin >> newStudent->id;
  cin.clear();
  cin.ignore(999, '\n');
  cout << "Enter their gpa: ";
  cin >> newStudent->gpa;
  cin.clear();
  cin.ignore(999, '\n');
  return newStudent; //return student pointer
}

void PRINT(vector<Student*> students){ //print function
	vector<Student*>::iterator cycle; // creates iterator through student pointer vector
	for(cycle = students.begin(); cycle != students.end(); ++cycle){ //iterates through the vector
		cout << "\nStudent name: " << (*cycle)->firstName << " " << (*cycle)->lastName << endl;
		cout << "Student ID: " << (*cycle)->id << endl;
		cout << "Student GPA: " << fixed << setprecision(2) << (*cycle)->gpa << endl; //round to 2 decimal places
		cout << endl;
  }
}

void DELETE(vector<Student*>* students, int id){ //delete function
    int idInput;
	cout << "\nWhich student would you like to delete? Enter their student id: ";
	cin >> idInput;
	cin.clear();
	cin.ignore(999, '\n');
	vector<Student*>::iterator cycle; // creates iterator through vector of students
	for(cycle = students->begin(); cycle != students->end(); ++cycle){
	  //cout << (*cycle)->id << "it works! somethings just being weird" << endl;
	  if((*cycle)->id == idInput){ //make sure input matches existing id
	    cout << "\nDeleted student " << (*cycle)->id << "." << endl;
		students->erase(cycle);//erase that index from student vector
	    delete *cycle;//clear iterator memory in the heap
	    return;
	  }
	  else{
		cout << "Couldn't find a student with the ID " << idInput << " in the directory." << endl; 
	  }
	}
}

void EXIT(){ //exit program
  exit;
}


int main() {
  bool running = true;
  char input[10];// userinput for what action to perform
  vector<Student*> students;
  int idInput;// input for delete
  while(running = true){
    cout << "\nType in 'add', 'print', 'delete', or 'exit' for actions: ";
    cin.get(input, 10);
    cin.clear();
    cin.ignore(999, '\n');
    if(strcmp(input, "add") == 0){
      students.push_back(ADD()); //call add function to add new element to back of vector
    }
    else if(strcmp(input, "print") == 0){
      PRINT(students); //call print function
    }
    else if(strcmp(input, "delete") == 0){
      DELETE(&students, idInput); //delete function
    }
    else if(strcmp(input, "exit") == 0){
	return 0;
    EXIT(); //exit function
    }
    else {
      cout << "\nThat is not an available action." << endl;
    }
  }
  return 0;
}

