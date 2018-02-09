/*
Edgar Cruz
Feb 8, 2016
CS 211
Assignment 1
*/

#include "inputCheck.h"

//######### DO NOT forget about the prototypes. You should know where to place them.  ############

//Declare a struct called "student" with id, name, gender, major and age

struct student //a struct is a user-defined data type that contains a collection of different
               //data types
{
  int id;
  string name;
  char gender;
  string major;
  int age;
  //each field is called a "member" and has a name.
};
int getStuData(student ar[]); 
int findID(const student ar[],int looking,  int numOfStu);
void displayStu(student s);
void findYoungOld(const student l[], int n, int & y, int & o );
void displayAllStu(const student s[], int n);

//If you want to change the maximum number of students, change the number in one place.
const int MAX = 2;//global 

int main()
{
  //delare an array of students with size MAX.
  student stuList[MAX];
  int num, index, young, old ; //the number of students, student with id found at index.
                              //young and old for function findYoungOld.
  
  //call the getStuData function to fill the array with students' information 
  
  num = getStuData(stuList);
  if (num == 0)
  {  
    cout << "No students were entered" << endl;
    return 0;
  }
  else
  {
    int look; //The id the user is looking for
    cout << "\nEnter the id you are looking for: ";
    cin >> look;

    //Find a student with that id and display the information about that student. If no student has the id, show an appropriate message.
    index = findID(stuList, look, num);
    if(look == stuList[index].id) 
    {
     displayStu(stuList[index]);
     cout << endl;
    }
    else
      cout << "No student with id " << look << " was found" << endl;  
    
    //find the youngest and oldest ages by calling findYoungOld and output those ages
    
    findYoungOld(stuList, num, young, old );//notes 1/27/16 cs211
  cout << "\nThe youngest age is " << young
       << "\nThe oldest age is " << old << endl;
  cout << endl;
  displayAllStu(stuList, num);
return 0;
  }
}

//This function loads students' data into the array and returns the number of students. 
int getStuData(student ar[])//, int max) 
{
  int i = 0;
  char ans;
  string name, major;
  //fill the array with students' information entered from the keyboard - use the while loop
  cout << "\nEnter data for a student? Y or N: ";//prompt, input, automatic endline.
   
   ans = getResponse("Invalid response. Enter Y or N: ");
  while (ans == 'Y')
  {
    cout << "id: ";
    ar[i].id = getNumberInRange(1, 9999, "Invalid id. Enter id: ");

    cin.ignore();
    cout << "name: ";
    getline(cin, ar[i].name);

    cout << "gender: ";
    ar[i].gender = getGender("Invalid gender. Enter M or F: ");
 
    cin.ignore();
    cout << "major: ";
    getline(cin, ar[i].major);

    cout << "age: ";
    ar[i].age = getNumberInRange(0, 150, "Invalid age. Enter age: ");
    i++;

    cout << "\nEnter data for a student? Y or N: ";
    ans = getResponse("Invalid response. Enter Y or N: ");
    if (ans == 'N')
      ans = 'n';
    else if (i == MAX)
    {
       cout << "The array is full" << endl;
       ans = 'n';
    }  
   }  
  //fill the unused slots with the default values  
  student Default = {0, " ", ' ', " ", 999}; //defalut values

  for(int a = i; a < MAX; a++)// cs111 notes 4/20/15 p1  
    
      ar[a] = Default;// in class notes 1/25/16.
                    // Notes cs211 wk1-1

  //return the number of students
return i; 
}


/* This function searches through the array to find the student with the id the user is looking for.
   The user is asked to enter the id she is looking for in the main. 
   Return the index or -1 if not found. */
int findID(const student ar[],int looking,  int numOfStu)//struct.C
{
  for (int i = 0; i < numOfStu; i++)//notes cs211 wk1-1
  {
    if (ar[i].id == looking)
      return i;//slott
  } 
      return -1;
}
/*This function will be passed one student struct and display all the information (name, gender, major and age) about that student.*/
void displayStu(student s)//slott
{
  const int NUM = 20;
  cout << left << setw(NUM)<< s.id << setw(NUM) << s.name << setw(NUM) << s.gender << setw(NUM) << s.major << setw(NUM) << s.age;
}

/*This function will return the youngest and oldest ages */
void findYoungOld(const student l[], int n, int & y, int & o )//notes 1/27/16 cs211
{
  y = 999;
  o =  -999;
  for (int i = 0; i < n ; i++)
  {
    if (l[i].age < y)
      y = l[i].age;
    if (l[i].age > o)
      o = l[i].age;
  }  
}

void displayAllStu(const student s[], int n)//n number of students
{
const int NUM = 20;
 cout << left << setw(NUM)<< "ID" << setw(NUM) << "NAME" << setw(NUM) << "GENDER" << setw(NUM) << "MAJOR" << setw(NUM) << "AGE" << endl;
 cout << "-------------------------------------------------------------------------------------" << endl;
 for (int i = 0; i < n ; i++)
 {
 displayStu(s[i]);
 cout << endl;
 } 
}





