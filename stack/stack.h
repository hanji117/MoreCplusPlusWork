/*
Edgar Cruz
CS 211 lab 5, HW3
Stack class - header file
=======================================================================
PURPOSE: The header file declares functions, variables, and a class.
The header file lets the compiler know about the variables and functions 
that are available and how to use them. 
*/
//#ifndef STACK_H checks to see if a compiler variable has already been created.
#ifndef STACK_H //ifndef and def can be used for any part of any file which
#define STACK_H//you do not want to be read twice by the compiler.
//#define STACK_H creates a compiler variable.
#include <string>
using namespace std;//Without using namespace std; you'd have to put std::cout <<;
                    //Needed for #include <string>.
typedef int el_t;//the element type, el_t, is string for now. 
                 //int for postfix.C
const int MAX = 5;//the MAX number of elements for the stack

class Stack //A class is like a template for all objects belonging to it.
            //  class syn: category
{
 private://Accessible only from within other members of the same class.
  el_t el[MAX];//el is an array of el_t's
  int top;//top is index to the top of the stack

  //This is NOT available to the clients. Only public members
  //are available to the clients.
  //Displays the given error message string and exits the program
  void stackError(string);//utility function for error handling
 public://public data members of objects of a class can be accessed using the 
  //direct member access operator(.).
  Stack(); // Default Constructor

  //HOW TO CALL: Create a Stack object (such as Stack myStack)
  //             and place the isEmpty function after.
  //             i.e. myStack.isEmpty()
  //PURPOSE: Returns true if stack is empty else false.
  bool isEmpty();
  
  //HOW TO CALL: Create a Stack object (such as Stack myStack)
  //             and place the isFull() function after.
  //             i.e. myStack.isFull()
  //PURPOSE: Returns true is stack is full else false.
  bool isFull();

  //HOW TO CALL: Pass an element to be pushed.
  //PURPOSE: If not full, enters an element at the top.
  //         otherwise, calls an emergency exit routine.
  void push(el_t);
                  
  //HOW TO CALL: Make a Stack object (such as Stack myStack)
  //             and place the pop function after. 
  //             i.e. myStack.pop()
  //PURPOSE: If empty calls an emergency exit routine.
  //         If not empty, removes an element from the top.
  el_t pop();
             
  //HOW TO CALL: Make a Stack object (such as Stack myStack)
  //             and place the topElem function after.
  //             i.e. myStack.topElem()
  //PURPOSE: Returns the top element in the stack.
  //         If empty calls stackError.
  el_t topElem();

  //  void stackError(string);
  
  //HOW TO CALL: Make a Stack object (such as Stack myStack)
  //             and place the clearAll() function after.
  //             i.e. myStack.clearAll()
  //PURPOSE: Clears the stack.
  //
  void clearAll();

  //HOW TO CALL: Make a Stack object (such as Stack myStack)
  //             and place the printAll() function after.
  //             i.e. myStack.printAll()
  //PURPOSE: Prints the elements in the stack.
  //
  void printAll();
};

#endif//End of the part checked by STACK_H. Kind of like a ;
//otherwise, an error message is generated.
