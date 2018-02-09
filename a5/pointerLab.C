//Edgar Cruz
//CS 211 lab 7-2:pointer, HW 5

#include <iostream>
 using namespace std;
int main()
{
/*
  int n = 1; 
int* pi;
 double* pf1;
 double* pf2;
 string* ps;
  pi = &n;
  pf1 = new double; 
pf2 = new double; 
ps = new string;
  *pi = 2;
  *pf1 = 10.55;
 *pf2 = 11.55;
 *ps = "Hello";
  cout << "0 " << pi << endl;
  cout << "1 " << pf1 << " " << pf2 << " " << ps << endl; cout << "2 " << *pf1 << " " << *pf2 << " " << *ps << endl;
  delete ps;
  ps = new string;
 *ps = "World";
  cout << "3 " << ps << endl; cout << "4 " << *ps << endl;
  pf2 = pf1;
  cout << "5 " << pf1 << " " << pf2 << endl; cout<<"6"<<*pf1<<""<<*pf2<< endl;
  delete pf1; pf1 = NULL;
 
  cout << "7 " << pf1 << " " << pf2 << endl; cout << "8 " << *pf2 << endl;
  cout << "9 " << *pf1 << endl;
*/
  int* ptr1;
  int* ptr2;
  ptr1 = new int;
  *ptr1 = 1;
  cout << *ptr1 << endl;
  ptr2 = new int;
  *ptr2 =  2;
  cout << *ptr2 << endl;

  delete ptr2;
  ptr2 = ptr1;
  cout << *ptr2 << endl;
  delete ptr2;//or ptr1
  ptr1 = NULL;

  ptr2 = new int;
  *ptr2 = 3;
  cout << *ptr2 << endl;

 
 return 0; 
}
