//Edgar Cruz
//CS 211 Lab 8-1, HW5
//LQueue class - Client file
//==========================================================================
#include "lqueue.h"
#include <iostream>

int main()
{
  LQueue myLQueue; //making an object called myLQueue that belongs to the 
                   //LQueue category.
  el_t elementToAdd;
  if (myLQueue.isEmpty()) //if empty cout message.
    cout << "Linked Queue is empty" << endl;

  myLQueue.displayAll(); //displays all the elements in the Linked Queue.
  cout << "Enter an element to add: ";
  cin >> elementToAdd;
  myLQueue.addRear(elementToAdd);

  myLQueue.displayAll(); //displays all the elements in the Linked Queue.
  cout << endl;
  for(el_t i = 0; i < 3; i++)//user enters 3 numbers.
  { 
    cout << "Enter an element to add: ";
    cin >> elementToAdd;  
    myLQueue.addRear(elementToAdd);//adds a new node to the rear of the Linked
  }                                //Queue.
  myLQueue.displayAll(); //displays all the elements in the Linked Queue.
  cout << "are the elements in the Linked Queue" << endl;
  cout << "deleted " << myLQueue.deleteFront() << endl;//shows the deleted element;
  cout << "deleted " <<  myLQueue.deleteFront() << endl;//deleteFront returns it.
  cout << "deleted " << myLQueue.deleteFront() << endl;
  myLQueue.displayAll(); //displays all the elements in the Linked Queue.
  cout << "is still in the linked Queue. " << endl;
  
  if (myLQueue.isEmpty())//if the Linked Queue is empty cout message else
                         //cout a different message.
    cout << "Linked Queue is empty" << endl;
  else 
    cout << "Linked Queue is not empty." << endl;

  cout << "deleted " <<  myLQueue.deleteFront() << endl;//shows the deleted
                                                        //element.
  if (myLQueue.isEmpty())
    cout << "Linked Queue is empty" << endl;
  else
    cout << "Linked Queue is not empty." << endl;
    myLQueue.displayAll();//displays all the elements in the Linked Queue.
  //  myLQueue.deleteFront();
 
 return 0;
}
