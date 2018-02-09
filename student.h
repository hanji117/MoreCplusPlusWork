#????? STUDENT_H
#????? STUDENT_H

#include <string>
#include <????????>
using namespace std;
#include "?????"

class Student
{
 private:
  static int id;
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
  ????? int getNumStu(); //This function returns the static data member 
  int getDollar() const;
  int getCent() const;
  ????? getCourses() const;
  void chargeFee(int d, int c);
  void reduceFee(int d, int c);
};

#????
