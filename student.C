#include "???????"

?????? //initialize id to 100
?????? //initialize numStu to 0

Student::Student()
{
  ?????? //one more student. increment numStu
  ?????? //set stId of the new student to the value of the static member "id"
  fName = "unknown";
  lName = "unknown";
  gender = 'X';
  ????? //increment id for stId of the next student
}

Student::Student(string f, string l, char g)
{
  ?????? //one more student. increment numStu
  ?????? //set stId of the new student to the value of the static member "id"
  ???? = f;//initialize the data members
  ???? = l;
  ???? = g;
  ????? //increment id for stId of the next student
}

//returns true if crn is added to the vector
//returns false if crn already exists. Do not add the same crn into the vector
bool Student::addCourse(int crn)
{
  //If crn already exists in the vector, don't add it
  for(int i = 0; i < ????; i++)
    if(??????? == ???)
      return false;

  //If the vector doesn't have the same crn, add it to the vector
  ????.push_back(????);
  return true;
}

//return true if the crn is dropped from vector
//return false if the crn is not found in vector
bool Student::dropCourse(int crn)
{
  for(int i = 0; i < ????;i++)
  {
    if(????? == ???)
      {
	????.erase(?????????);
	return true;
      }
  }

  return false;
}

string Student::getFirstName() const
{
  return fName;
}

string Student::getLastName() const
{
  return lName;
}

char Student::getGender() const
{
  return gender;
}

int Student::getId() const
{
  return stId;
}

int Student::getNumStu()
{
  return numStu;
}

int Student::getDollar() const
{
  return balance.getDollar();
}

int Student::getCent() const
{
  return balance.getCent();
}

//Returns the vector of course the student is enrolled in
???????? Student::getCourses() const
{
  return coVec;
}

//$d.c is added to the student's fee
void Student::chargeFee(int d, int c)
{
  ??????

  ????? = balance + ?????;
}

//The student's fee is reduced by $d.c
void Student::reduceFee(int d, int c)
{
  ?????;

  ?????? = balance - ?????;

}

