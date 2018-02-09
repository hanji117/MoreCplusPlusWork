//Edgar Cruz
//CS 211 Lab11-1, HW7
//LL class - Client file 
//==============================================================

#include "LL.h"
#include <iostream>
int main()
{
  
  LL myLL;
  cout << endl;
  cout << "Delete node" << endl; 
  myLL.addFront(2);
  myLL.addFront(9);
  myLL.addFront(3);
  myLL.addRear(1);
  myLL.addRear(9);
  myLL.addRear(11);

  myLL.deleteNode(9);
  myLL.displayAll();
  cout << endl;

  myLL.deleteNode(9);
  myLL.displayAll();
  cout << endl;

  myLL.deleteNode(5);
  myLL.displayAll();
  cout << endl;

  myLL.deleteNode(3);
  myLL.displayAll();
    cout << endl;

  myLL.deleteNode(11);
  myLL.displayAll();
  cout << endl;

  myLL.deleteNode(1);
  myLL.displayAll();
  cout << endl;

  myLL.deleteNode(2);
  myLL.displayAll();
  cout << endl;

  myLL.deleteNode(5);
  //=================
  cout << "Add In Order" << endl;
  myLL.addInOrderAscend(5);
  myLL.displayAll();
  cout << endl;

  myLL.addInOrderAscend(1); 
  myLL.displayAll();
  cout << endl;

  myLL.addInOrderAscend(3);
  myLL.displayAll();
  cout<< endl;

  myLL.addInOrderAscend(0);
  myLL.displayAll();
  cout << endl;

  myLL.addInOrderAscend(7);
  myLL.displayAll();
  cout << endl;

  myLL.addInOrderAscend(7);
  myLL.displayAll();
  cout << endl;

  myLL.addInOrderAscend(5);
  myLL.displayAll();
  cout << endl;

  myLL.addInOrderAscend(0);
  myLL.displayAll();
  cout << endl;

  myLL.deleteNode(5);
  myLL.deleteNode(1);
  myLL.deleteNode(3);
  myLL.deleteNode(0);  
  myLL.deleteNode(7);
  myLL.deleteNode(7);
  myLL.deleteNode(5);
  myLL.deleteNode(0);
  //========================== 
  cout << endl;
  cout << "search" << endl;
  myLL.addFront(2);
  myLL.addFront(9);
  myLL.addFront(3);
  myLL.addRear(1);
  myLL.addRear(9);
  myLL.addRear(11);

  cout <<  myLL.search(3) << endl;
  cout <<  myLL.search(11) << endl;
  cout <<  myLL.search(2) << endl;
  cout <<  myLL.search(9) << endl;
  cout <<  myLL.search(100) << endl;

  myLL.deleteNode(2);
  myLL.deleteNode(9);
  myLL.deleteNode(3);
  myLL.deleteNode(1);
  myLL.deleteNode(9);
  myLL.deleteNode(11);
  
  //=============================
  
  cout << endl;
  cout << "delete nodes" << endl;
  myLL.addFront(9);
  myLL.addFront(9);
  myLL.addFront(9);
  myLL.addFront(3);
  myLL.addRear(9);
  myLL.addRear(9);
  myLL.addRear(9);
  myLL.deleteNodes(9);
  myLL.displayAll();
  cout << endl;
 return 0;
}
