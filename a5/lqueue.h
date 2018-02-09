/*
Edgar Cruz
CS 211 lab 8-1, HW 5
LQueue class - header file
===========================================================================
//PURPOSE: The header file declares functions, variables, and a class.
//The header file lets the compiler know about the variables and functions 
//that are available and how to use them.
*/

#ifndef LQUEUE_H//There may be cases where a header file gets included more 
                //than once when compiling a .C file. 
                //e.g. myProg.C includes stack.h and queue.h
                //stack.h also includes queue.h
                //(although we don't do this in cs211)
                //This causes the compiler to complain about seeing duplicate 
                //declarations(class Queue is declared twice).
                //#ifndef LQUEUE_H checks to see if a compiler variable 
                //has already been created.

#define LQUEUE_H//creates a compiler variable.
#include <string>
using namespace std;//needed for string
typedef int el_t;//the element type, el_t is int for now.

struct node//A struct is a user-defined data type that contains
//a collection of different data types.
{
  el_t element;//Each field is called a "member" and has a name.
  node* next;
};

class LQueue //class syn. category. I made a category called LQueue.
{
 private://Accessible only from within other members of the 
         //same class(category).
  //Data members below
  node* front;//Where the front node of the linked queue is.
              //Will point to the front node.
  node* rear;//Where the rear node of the linked queue is.
             //Will point to the rear node.
  int count;//How many elements do we have right now?
  //Private utility function for error cases below.
  void queueError(string); 
public:
  LQueue();//default constructor
  ~LQueue();//destructor 

  //HOW TO CALL: Create an LQueue object (such as LQueue myLQueue)
  //             and place the isEmpty function after.
  //             i.e. myLQueue.isEmpty()
  //PURPOSE: Returns true if LQueue is empty else false.
 bool isEmpty();

  //HOW TO CALL: Pass an element to be added.
  //PURPOSE: Enters a node at the rear of the Queue Linked list.
 void addRear(el_t);

  //HOW TO CALL: Create an LQueue object (such as LQueue myLQueue)
  //             and place the deleteFront function after.
  //             i.e. myLQueue.deleteFront()
  //PURPOSE: If empty calls an emergency exit routine.
  //         If not empty, removes a node from the front.
 el_t deleteFront();

  //HOW TO CALL: Create an LQueue object (such as LQueue myLQueue)
  //             and place the displayAll() function after.
  //             i.e. myLQueue.displayAll()
  //PURPOSE: If it's empty [ empty ] will be displayed. Else displays 
  //         all the nodes in the LQueue. 
 void displayAll();

 //HOW TO CALL: Create an LQueue object (such as LQueue myLQueue)
 //             and place the printAllReverse() function after.
 //             i.e. myLQueue.printAllReverse()
 //PURPOSE: Will display the LQueue in reverse order.
 void printAllReverse();

 //HOW TO CALL: Pass a pointer to the parameter.
 //PURPOSE: If the pointer is equal to NULL return. 
 //         Else calls printAllReverse(p-> next) and couts p-> element.
 void printAllReverse(node* p);
};

#endif //End of the part checked by LQUEUE_H. Kind of like a ;
//otherwise, an error message is generated.
