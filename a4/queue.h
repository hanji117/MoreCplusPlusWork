//Edgar Cruz
//CS211 Lab7: queue.h, HW4
//Queue class - header file
//===========================================================================
//#ifndef QUEUE_H checks to see if a compiler variable has already been created.
#ifndef QUEUE_H//ifndef and def can be used for any part of any file which
#define QUEUE_H//you do not want to be read twice by the compiler.
//#define QUEUE_H creates a compiler variable.
#include<string>
using namespace std;//Without using namespace std; you'd have to put std::cout <<;
                    //Needed for #include <string>.



//create an enumuration type                                                   
enum op {ADD, SUB, MULT, DIVI};

//create a struct that will have an operand, a operator, another operand       
struct expr//A struct is a user-defined data type                              
{
  int oprd1;
  op oprt;
  int oprd2;
};



typedef expr el_t; // el_t is an alias for char//char for queueClient.C
//expr for game.C
const int QUEUE_SIZE = 10; // this is the max number of elements the queue can have//5 for queueClient //10 for game.C
class Queue//A class is like a template for all objects belonging to it.
           // class sys: category
{
 private://Accessible only from within other members of the same class.

  // Data members are:
  el_t el[QUEUE_SIZE]; //el is an el_t array. For queueClient it's a character array called el.
  //For game.C it's an expr array called el.   
  int count; // how many elements do we have right now?
  int front; // where the front element of the queue is. 
             // You can remove an element from the front of the Queue.
  int rear; // where the rear element of the queue is.
            //You can add an element to the rear of the Queue.

  // A private utility function for fatal error cases
  // This displays an error messages passed to it. 
  void queueError(string);

 public:
  // default constructor
  Queue();
  //HOW TO CALL: Create a Queue object(such as Queue q)
  //             and place the isEmpty() function after.
  //             i.e. q.isEmpty()
  //PURPOSE: Returns true if queue is empty, otherwise false
  bool isEmpty();
  
  //HOW TO CALL: Create a Queue object(such as Queue q)
  //             and place the isFull() function after.
  //             i.e. q.isFull()
  //PURPOSE: Returns true if queue is full, otherwise false
  bool isFull();
 
  //HOW TO CALL: Pass an element to be added.
  //PURPOSE: if full, calls an emergency exit routine
  //         if not full, changes rear to the next slot and enters an element at rear
  void add(el_t);

  //HOW TO CALL: Create a Queue object (such as Queue q)
  //             and place the remove() function after.
  //             i.e. q.remove()
  //PURPOSE: if empty, calls an emergency exit routine
  //         if not empty, remove(return) the front element and change front to the next slot
  el_t remove();
  
  //HOW TO CALL: Create a Queue object (such as Queue q)
  //             and place the getFront() function after.
  //             i.e. q.getFront();
  //PURPOSE: if empty, calls an emergency exit routine
  // if not empty, return the front element (but does not remove it)
  el_t getFront();

  //HOW TO CALL: Create a Queue object (such as Queue q)
  //             and place the goToBack() function after.
  //             i.e. q.goToBack()
  //PURPOSE:
  //if empty, calls an emergency exit routine
  //if queue has just 1 element, does nothing
  //if queue has more than 1 element, moves the front one to the rear
  void goToBack();//moves the front element to the rear.
 
  //HOW TO CALL: Create a Queue object(such as Queue q)
  //             and place the getSize() function after.
  //             i.e. q.getSize()
  //PURPOSE: Returns the current size
  int getSize();

  //HOW TO CALL: Create a Queue object(such as Queue q)
  //             and place the displayAll() function after.
  //             i.e q.displayAll()
  //PURPOSE:
  //display everything in the queue from front to rear enclosed in []. E.g. [a][b][c]
  //Do not call the emergency exit routine when the queue is empty.
  //void displayAll();//comment out for game.C
};

#endif//End of the part checked by QUEUE_H. Kind of like a ;
//otherwise, an error message is generated.

