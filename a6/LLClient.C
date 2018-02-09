//Edgar Cruz
//CS 211 Lab 10-1, HW6
//LL class - Client file
//=================================================================
#include "LL.h"
#include <iostream>
int main()
{
  LL myLL; //making an object called myLL that belongs to the LL category.
  myLL.addFront(1);// adds a new node to the front of the LL.
  myLL.addFront(2);
  myLL.addFront(3);
  myLL.addRear(4);// adds a new node to the rear of the Linked List.
  myLL.addRear(5);
  myLL.displayAll();//displays all the elements in the LL.
  cout << endl;
  cout << myLL.deleteFront() << " has been deleted" << endl; //Deletes the front
                                                             //node.
  cout << myLL.deleteRear() << " has been deleted" << endl;//Deletes the rear
                                                           //node.
  myLL.displayAll();
  cout << endl;
  cout <<  myLL.deleteFront() << " has been deleted" << endl;
  cout << myLL.deleteRear() << " has been deleted" << endl;
  myLL.displayAll();
  cout << endl;
  cout <<  myLL.deleteFront() << " has been deleted" << endl;
  myLL.displayAll();
  cout << endl;
  myLL.addRear(10);
  myLL.addFront(11);
  myLL.displayAll();
  cout << endl;  
  cout << myLL.deleteRear() << " has been deleted" << endl;
  cout << myLL.deleteRear() << " has been deleted" << endl;
  myLL.displayAll();
  cout << endl;  

  return 0;
}
