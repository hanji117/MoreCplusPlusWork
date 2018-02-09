//Edgar Cruz
//CS 211 Lab5, HW3
//Stack class - implementation file
//========================================================

#include <iostream>
#include "stack.h"

//PURPOSE: default constructor that initializes top
Stack::Stack()
{
  top = -1;
}

//PURPOSE: Checks to see if the stack is empty.
//ALGORITHM: If top equals -1 then the stack is empty and returns true
//           else false is returned.
bool Stack::isEmpty()
{
  if (top == -1)//Stack is empty.
    return true;
  else//Stack is not emtpy.
    return false;
}

//PURPOSE: Checks to see if the stack is full.
//ALGORITHM: If top equals MAX-1 then the stack is full and returns true
//           else false is returned.
bool Stack::isFull()
{
  if (top == MAX-1)//Stack is full
    return true;
  else //Stack is not full.
    return false;
}

//PURPOSE:To push a passed element to the stack.
//PARAMS: New element elem of type el_t.
//ALGORITHM:If not full, increment top and place elem there,
//          else stackError is called.
void Stack::push(el_t elem)
{
  if(isFull())//Stack is full.
    stackError("stack overflow");
  else//Stack is not full
    {
	el[++top] = elem;
    }
}

//PURPOSE: To pop the top element in the stack.
//ALGORITHM:If not empty, return the top element and then decrement,
//          else if it's empty stackError is called.
el_t Stack::pop()
{
  if(isEmpty())//Stack is empty.
    stackError("stack underflow");
  else //Stack is not empty.
    return el[top--];
    //x++ increments the value of variable x after processing the current statement.
    //++x increments the value of variable x before processing the current statement.
}

//PURPOSE: To return the top element in the stack.
//ALGORITHM:If not empty, return the top element in the stack.
//          else if it's empty stackError is called.
el_t Stack::topElem()
{
  if (isEmpty())//Stack is empty
    stackError("stack is empty");
  else //Stack is not empty.
    return el[top];//like an array. el is the stack. top is the index.
}

//PURPOSE:(private) to handle unexpected errors encountered by other methods.
//PARAMS: A string message to be displayed.
//ALGORITHM: Simply cout the message and exit from the program.
void Stack::stackError(string msg)
{
  cout << msg << endl;
  exit(1);//ends the program. 1 is returned to the operating system.
  //0 = end with no errors, 1 = end with errors
}

//PURPOSE: To clear all the elements in the stack.
//ALGORITHM: While not empty continue to pop. Once it's empty it stops popping. 
void Stack::clearAll()
{
  while (!isEmpty())//Stack is not empty.
    pop();
}

//PURPOSE: To print all the elements in the stack.
//ALGORITHM: First prints the top element in the stack and then it prints
//           the element below it and so on until there are no more elements 
//           to print.
void Stack::printAll()
{
  for (int i=top; i >= 0; i--)
    cout << el[i] << endl;
}
