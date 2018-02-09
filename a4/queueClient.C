//Edgar Cruz
//CS 211 Lab7, HW4
//Queue class - Client file
//===========================================================================
#include <iostream>
#include "queue.h"
#include "inputCheck.h"
using namespace std;
void showMenu();//prototype
//PURPOSE: To make sure all our member functions work correctly.
int main()
{
Queue myLine; // myLine is a new queue object
char  elToadd;
  

 int choice;//the user will enter a number between 1-7.
do 
{
  showMenu();
cout << "Enter your choice ----> ";
choice = getNumberInRange(1, 7, "Invalid choice. Enter 1 through 7: ");

switch(choice)
{
 case 1:
   {
     cout << "Give an element to add: ";
     cin >> elToadd;
     myLine.add(elToadd);
   }
   break;
 case 2:
   cout << myLine.remove();
   break;
 case 3: 
   cout << myLine.getFront();
   break;
 case 4:
 {
   if (!myLine.isEmpty())
      myLine.goToBack();
   else //the queue is empty
     cout << "The queue is empty.";
 }
   break;
 case 5:
   cout << "The line has " << myLine.getSize() << " elements." << endl;
   break;
 case 6:
    myLine.displayAll();
   break;
 case 7:
   cout << "Ending the program ................" << endl;
 }
}while(choice!=7);

 return 0;
}
//PURPOSE: Displays a menu to the user.
//ALGORITHM: couts the menu.
void showMenu()
{
  cout << "\n**************************************************" << endl;
  cout << "1: Add a new element" << endl
       << "2: remove an element" << endl
       << "3: check the front element" << endl
       << "4: go back to the rear" << endl
       << "5: get the number of elements in the queue" << endl
       << "6: display all the elements in the queue" << endl
       << "7: quit the program" << endl;
}  
