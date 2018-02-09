/*
Edgar Cruz
CS 211 lab 12-1, HW 9
DLL class - header file
===========================================================================
//PURPOSE: The header file declares functions, variables, and a class.
//The header file lets the compiler know about the variables and functions 
//that are available and how to use them.
*/

#ifndef DLL_H//There may be cases where a header file gets included more 
                //than once when compiling a .C file. 
                //e.g. myProg.C includes stack.h and queue.h
                //stack.h also includes queue.h
                //(although we don't do this in cs211)
                //This causes the compiler to complain about seeing duplicate 
                //declarations(class Queue is declared twice).
                //#ifndef DLL_H checks to see if a compiler variable 
                //has already been created.

#define DLL_H//creates a compiler variable.
#include <string>
using namespace std;//needed for string
typedef int el_t;//the element type, el_t is int for now.
// char for palindrome.C , string for dictionary.C
struct node//A struct is a user-defined data type that contains
//a collection of different data types.
{
  el_t element;//Each field is called a "member" and has a name.
  node* next;
  node* prev;

};

class DLL //class syn. category. I made a category called DLL.
{
 private://Accessible only from within other members of the 
         //same class(category).
  //Data members below
  node* front;//Where the front node of the Double linked list is.
              //Will point to the front node.
  node* rear;//Where the rear node of the Double linked list is.
             //Will point to the rear node.
  int count;//How many elements do we have right now?
  //Private utility function for error cases below.
  void listError(string); 
public:
  DLL();//default constructor
  ~DLL();//destructor 

  //HOW TO CALL: Create a DLL object (such as DLL myDLL)
  //             and place the isEmpty function after.
  //             i.e. myDLL.isEmpty()
  //PURPOSE: Returns true if DLL is empty else false.
 bool isEmpty();

  //HOW TO CALL: Pass an element to be added.
  //PURPOSE: Enters a node at the rear of the Double Linked list.
 void addRear(el_t);

  //HOW TO CALL: Create a DLL object (such as DLL myDLL)
  //             and place the deleteFront function after.
  //             i.e. myDLL.deleteFront()
  //PURPOSE: If empty calls an emergency exit routine.
  //         If not empty, removes a node from the front.
 el_t deleteFront();

  //HOW TO CALL: Create a DLL object (such as DLL myDLL)
  //             and place the displayAll function after.
  //             i.e. myDLL.displayAll()
  //PURPOSE: If it's empty [ empty ] will be displayed. Else displays 
  //         all the nodes in the DLL. 
 void displayAll();

 //HOW TO CALL: Create a DLL object (such as DLL myDLL)
 //             and place the printAllReverse function after.
 //             i.e. myDLL.printAllReverse()
 //PURPOSE: Will display the DLL in reverse order.
 void printAllReverse();

 //HOW TO CALL: Pass a pointer to the parameter.
 //PURPOSE: If the pointer is equal to NULL return. 
 //         Else calls printAllReverse(p-> next) and couts p-> element.
 void printAllReverse(node* p);

 //HOW TO CALL: Pass an element to be added. 
 //PURPOSE: Enters a node at the front of the Double linked list.
 void addFront(el_t el);
 
 //HOW TO CALL: Create a DLL object (such as DLL myDLL)
 //             and place the deleteRear function after.
 //             i.e. myDLL.deleteRear()
 //PURPOSE: If empty calls an emergency exit routine.
 //         If not empty, removes a node from the rear.
 el_t deleteRear();

 //HOW TO CALL: Pass an element.
 //PURPOSE: To delete the node that contains the passed element.
 void deleteNode(el_t);

 //HOW TO CALL: Pass an element.
 //PURPOSE: To delete the nodes that contain the passed element.
void deleteNodes(el_t e);//extra credit
 
 //HOW TO CALL: Pass an element.
 //PURPOSE: To add a new node in ascending order (from least to greatest).
 void addInOrderAscend(el_t);

 //HOW TO CALL: Pass an element.
 //PURPOSE: To add a new node in descending order (from greatest to least).
 void addInOrderDescend(el_t); //for extra credit
 
 //HOW TO CALL: Pass an element.
 //PURPOSE: Returns true if the passed element is found in the Double linked list 
 //         else returns false. If the Double linked list is empty, returns false.
 bool search(el_t);
 
 //HOW TO CALL: Create a DLL object (such as DLL myDLL)
 //             and place the printAllReverseDLL function after.
 //             i.e. myDLL.printAllReverseDLL()
 //PURPOSE: Prints the DLL in reverse order.
 void printAllReverseDLL();
};

#endif //End of the part checked by DLL_H. Kind of like a ;
//otherwise, an error message is generated.
