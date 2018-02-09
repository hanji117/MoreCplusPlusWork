#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>  //include vector.h
using namespace std;
#include "student.h"
#include "inputCheck.h"

void showMenu();
//void addStudentsFromFile(??????);
void addStudentsFromFile(vector<Student>&stu);
//void addOneStudent(???????);
void addOneStudent(vector<Student>&stu);
//void printAllStudents(?????);
void printAllStudents( vector<Student> & stu);
//void addCourseToStudent(????);
void addCourseToStudent(vector <Student> & stu);
//void dropCourseFromStudent(????);
void dropCourseFromStudent(vector<Student> & stu);

int main()
{
  //Price p; //making an object by calling the default constructor.
  cout << "\n *** TEST: the number of students at the beginning is " << Student::getNumStu() << endl;
 
  //  ?????? //declare a vector of students  
  vector<Student>stu;

int choice;

  do
  {
    showMenu();
    cout << "Enter your choice ----> ";
    choice = getNumberInRange(1, 6, "Invalid choice. Enter 1 through 6: ");

    //    switch(????)
    switch(choice)
      {
      case 1:
	//addStudentsFromFile(???);
	addStudentsFromFile(stu);
	  break;
      case 2:
	//addOneStudent(???);
	addOneStudent(stu);
	  break;
      case 3:
	//printAllStudents(???);
	printAllStudents(stu);
	   cout << "\n *** TEST: the number of students is " << Student::getNumStu() << endl;
	break;
      case 4:
	//	addCourseToStudent(???);
	addCourseToStudent(stu);
	break;
      case 5:
	//	dropCourseFromStudent(???);
	dropCourseFromStudent(stu);
	break;
      case 6:
	cout << "Ending the program ..............." << endl;
      }
}while(choice != 6);
    //}while(??????);

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
//void addStudentsFromFile(???????)
void addStudentsFromFile(vector<Student>&stu)//lec notes wk 4-2
{
  //  ??????? fileName;
  string fileName;
  cout << "Enter the file name: ";
  cin >> fileName;

  ifstream fin;
  //fin.open(????????); //open the file
  fin.open(fileName.c_str()); //open the file.
  //C++ string is converted to C string. See lab4 - student Class pdf notes

  if(!fin)
    {
      cout << fileName << " doesn't exist " << endl;
    }
  else//The file exists
    {
      //???? fn, ln;
      string fn, ln;
      //??? gn;
      char gn;
      // fin >> ????????;//read the first student
      fin >> fn >> ln >> gn;//read the first student
      while(fin)//if reading was successful, enter the while
	{
	  // ??????????;//create a new student with the data from input
	  Student s(fn, ln, gn); //new student object
	  // ??????????; //add it to the vector
	  stu.push_back(s);// add the new student to the end of the vector.  
	  //fin >> ???????; //read the next student
	  fin >> fn >> ln >> gn;
	}
    }
}

//This function adds one student to the vector.
//void addOneStudent(??????)
void addOneStudent(vector<Student>&stu)

{
  // ???? fn, ln;
  string fn, ln;    
  //  ??? gn;
  char gn;
      cout << "Enter the student's first name: ";
      //cin >>???;
      cin >> fn;
      cout << "Enter the student's last name: ";
      //cin >>???;
      cin >> ln;
      cout << "Enter the student's gender: ";
      //      ???? = getGender("Invalid input. Enter M or F: ");
      //???? = getGender("Invalid input. Enter M or F: ");
gn = getGender("Invalid input. Enter M or F: ");
      //??????? //create a new student with the data from the user's input
      Student st(fn ,ln , gn);	
 //??????? //add the new student to the vector
	 stu.push_back(st);
}
 
//Print the information about all the students
//void printAllStudents(????????)
void printAllStudents( vector<Student> & stu)
{
  //Show the labels
  cout << left << setw(10) << "Id" <<  setw(10) << "First" << setw(10) << "Last" << right << setw(10) << "Fee" << left << setw(10) << "  Courses" << endl; 

  //Go through each student in the vector
  //  for(int n = 0; n < ??????; n++)
  for(int n = 0; n < stu.size(); n++)
  {
      //cout <<  setw(10) << ?????? << setw(10) << ????? << setw(10) << ?????? << right << setw(7) << ??????? << ".";
      cout <<  setw(10) << stu[n].getId() << setw(10) << stu[n].getFirstName() << setw(10) << stu[n].getLastName() << right << setw(7) << stu[n].getDollar() << "." ;
      //If the cent is less than 10, show a 0 first.
      //e.g. cent = 3, 03 will be shown.
//      if(??????? < 10)
 if(stu[n].getCent() < 10)
	cout << "0";
 //cout << ??????;
 cout << stu[n].getCent();
      //show all courses the student is enrolled in
      cout << left << "  ";
      //?????? co = ??????; //get the vector of courses for this student
      vector <int> co = stu[n].getCourses(); //get the vector of courses for this student
      //      for(int c = 0; c < ?????; c++)
      for(int c = 0; c < co.size(); c++)
        //cout << setw(6) << ?????;
cout << setw(6) << co[c];

      cout << endl;
    }
}

//Add a new course to a student.
//Charge $50.10 per course
//void addCourseToStudent(??????)
void addCourseToStudent(vector <Student> & stu)
{
  bool found = false; 
  bool added = false;
  int a; 
  int i;
 
  cout << "Enter the student id: ";
  int id = getNumberInRange(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: ";
  int crn = getNumberInRange(1, 99999, "Invalid CRN. Enter the CRN: ");

  //  ???????????? //Big section
    //she said about 10 lines down below

    //for (i = 0, ,)//go through each student.
  for (i = 0; !found && i < stu.size(); i++)//go through each student.
    {
      if (stu[i].getId() == id)//found the student with id.
	{
	  found = true;
	  added = stu[i].addCourse(crn);// student object.
	  cout << "***** added = " << added << endl; 
	  //stu[i].addCourse(crn);// student object.
	 a = i;
        }    
    } 
  if (found != true)
    {

	cout << "ERROR: The student wasn't found" << endl;
    }
  else if (added == false)
  {
  cout << "found is " << found << endl;
  cout << "added is" << added << endl;
  cout << "ERROR: The student is already enrolled in " << crn;
  }
  else if(found == true && added == true)
  {
      cout << crn << " has been added to " << stu[a].getFirstName();  
      stu[a].chargeFee(50,10);
      //stu[a].getCourse(crn);
  }

}

//drop a course from a student
//reduct $50.10 from the student's balance
//void dropCourseFromStudent(??????)

void dropCourseFromStudent(vector<Student> & stu)
{
  cout << "Enter the student id: ";
  int id = getNumberInRange(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: ";
  int crn = getNumberInRange(1, 99999, "Invalid CRN. Enter the CRN: ");
  //  ???????????? //Big section
//she said about 10 lines down below

  int a; 
  int i;
bool found = false;
 bool added = false;
//for (i = 0, ,)//go through each student.
for ( i = 0; i < stu.size(); i++)//go through each student.
  {
    if (stu[i].getId() == id)//found the student with id.
      {
	found = true;
         added = stu[i].dropCourse(crn);//v[i] student object.
	 a = i;
      }
  }
if (!found)
  cout << "ERROR: The student doesn't exist" << endl;


 else  if (!added)
   cout << "ERROR: The student is not enrolled in" << crn;
  

 else if (found)
	  {
	    cout << crn << " has been dropped from " << stu[a].getFirstName();
	    stu[a].reduceFee(50,10);//reduce $50.10 per course

	  }
    
}

