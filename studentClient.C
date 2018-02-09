#include <iostream>
#include <fstream>
#include <iomanip>
#include <?????????>  //include vector.h
using namespace std;
#include "??????"
#include "inputCheck.h"

void showMenu();
void addStudentsFromFile(??????);
void addOneStudent(???????);
void printAllStudents(?????);
void addCourseToStudent(????);
void dropCourseFromStudent(????);

int main()
{
  cout << "\n *** TEST: the number of students at the beginning is " << Student::getNumStu() << endl;
 
  ?????? //declare a vector of students  
  int choice;

  do
  {
    showMenu();
    cout << "Enter your choice ----> ";
    choice = getNumberInRange(1, 6, "Invalid choice. Enter 1 through 6: ");

    switch(????)
      {
      case 1:
	  addStudentsFromFile(???);
	  break;
      case 2:
          addOneStudent(???);
	  break;
      case 3:
	  printAllStudents(???);
	   cout << "\n *** TEST: the number of students is " << Student::getNumStu() << endl;
	break;
      case 4:
	addCourseToStudent(???);
	break;
      case 5:
	dropCourseFromStudent(???);
	break;
      case 6:
	cout << "Ending the program ..............." << endl;
      }
  }while(??????);


  cout << "\n *** TEST: the number of students at the end is " << Student::getNumStu() << endl;

  return 0;
}

 void showMenu()
 {
   cout << "\n*****************************************************************" << endl;
   cout << "1: Add students from a file" << endl;
   cout << "2: Add one student" << endl;
   cout << "3: Print all students" << endl;
   cout << "4: Add a course to a student" << endl;
   cout << "5: drop a course from a student" << endl;
   cout << "6: End the program" << endl;
 }

//This function adds students from an input file
//e.g. for input file (for each student, first last gen)
//  Mike Smith M
//  Kathy Ross F
void addStudentsFromFile(???????)
{
  ??????? fileName;

  cout << "Enter the file name: ";
  cin >> fileName;

  ifstream fin;
  fin.open(????????); //open the file

  if(!fin)
    {
      cout << fileName << " doesn't exist " << endl;
    }
  else//The file exists
    {
      ???? fn, ln;
      ??? gn;
   
      fin >> ????????;//read the first student
      while(fin)//if reading was successful, enter the while
	{
	  ??????????;//create a new student with the data from input
	  ??????????; //add it to the vector
	  fin >> ???????; //read the next student
	}
    }
}

//This function adds one student to the vector.
void addOneStudent(??????)
{
      ???? fn, ln;
      ??? gn;

      cout << "Enter the student's first name: ";
      cin >>???;
      cout << "Enter the student's last name: ";
      cin >>???;
      cout << "Enter the student's gender: ";
      ???? = getGender("Invalid input. Enter M or F: ");

      ??????? //create a new student with the data from the user's input
      ??????? //add the new student to the vector
}
 
//Print the information about all the students
void printAllStudents(????????)
{
  //Show the labels
  cout << left << setw(10) << "Id" <<  setw(10) << "First" << setw(10) << "Last" << right << setw(10) << "Fee" << left << setw(10) << "  Courses" << endl; 

  //Go through each student in the vector
  for(int n = 0; n < ??????; n++)
    {
      cout <<  setw(10) << ?????? << setw(10) << ????? << setw(10) << ?????? << right << setw(7) << ??????? << ".";

      //If the cent is less than 10, show a 0 first.
      //e.g. cent = 3, 03 will be shown.
      if(??????? < 10)
	cout << "0";
      cout << ??????;
      
      //show all courses the student is enrolled in
      cout << left << "  ";
      ?????? co = ??????; //get the vector of courses for this student
      for(int c = 0; c < ?????; c++)
        cout << setw(6) << ?????;

      cout << endl;
    }
}

//Add a new course to a student.
//Charge $50.10 per course
void addCourseToStudent(??????)
{


  cout << "Enter the student id: ";
  int id = getNumberInRange(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: ";
  int crn = getNumberInRange(1, 99999, "Invalid CRN. Enter the CRN: ");

  ???????????? //Big section

}

//drop a course from a student
//reduct $50.10 from the student's balance
void dropCourseFromStudent(???????)
{
 
  cout << "Enter the student id: ";
  int id = getNumberInRange(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: ";
  int crn = getNumberInRange(1, 99999, "Invalid CRN. Enter the CRN: ");

  ???????????? //Big section
}
