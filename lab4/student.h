#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;
#include "price.h"

class Student
{
 private:
  static int id;//from tutorialspoint.com, When we delclare a 
  //member of a class as static it means no matter how many 
  //objects of the class are created, there is only one copy of
  //the static member.
  //from IBM.com, Only 1 copy of the static member is shared by 
  //all objects of a class in a program. A typical use of static
  //members is for recording data common to all objects of a 
  //class.
  static int numStu;
  int stId;
  string fName;
  string lName;
  char gender;
  Price balance;
  vector<int> coVec;

 public:
  Student();
  Student(string f, string l, char g);
  bool addCourse(int crn);
  bool dropCourse(int crn);
  string getFirstName() const;
  string getLastName() const;
  char getGender() const;
  int getId() const;
  static int getNumStu(); //This function returns the static data member 
  int getDollar() const;
  int getCent() const;
  vector <int>  getCourses() const;
  void chargeFee(int d, int c);
  void reduceFee(int d, int c);
};

#endif
