//Edgar Cruz
//CS 211 Lab7: queue.C, HW4
//Queue class - implementation file
//================================================================

#include <iostream>
#include "queue.h"

//PURPOSE: default constructor initializes front, rear, and count.
Queue::Queue()
{
  count = 0;
  front = 0;
  rear = -1;
}

//PURPOSE: Checks to see if the queue is empty.
//ALGORITHM: If count equals 0 then the queue is empty and returns true
//           else false is returned.
bool Queue::isEmpty()
{
  if (count == 0)//Queue is empty.
    return true;
  else//Queue is not emtpy.
    return false;
}

//PURPOSE: Checks to see if the queue is full.
//ALGORITHM: If count equals QUEUE_SIZE then the queue is full and returns true
//           else false is returned.
bool Queue::isFull()
{
  if (count == QUEUE_SIZE)//Queue is full
    return true;
  
  else //Queue is not full.
    return false;
}

//PURPOSE:To add a passed element to the Queue.
//PARAMS: New element elem of type el_t.
//ALGORITHM:If not full, rear equals rear+1 mod QUEUE_SIZE,increment count and 
//          place elem in the array(el) index slot provided by rear.
//          Else if queue is full queueError is called.
void Queue::add(el_t elem)
{
  if(isFull())//Queue is full.
    queueError("Cannot add because the queue is full");
  else//Queue is not full
    {
    rear = (rear+1)% QUEUE_SIZE;//add 1st element rear is at -1 +1 = 0 % 5 r 0
                                //add 2nd element rear is at 0 + 1 = 1 % 5 r 1
                                //add 3rd element rear is at 1 + 1 = 2 % 5 r 2
                                //add 4th element rear is at 2 + 1 = 3 % 5 r 3
                                //add 5th element rear is at 3 + 1 = 4 % 5 r 4
    //The infamous wrap around  //add 6th element rear is at 4 + 1 = 5 % 5 r 0
                                //add 7th element rear is at 5 + 1 = 6 % 5 r 1
    count++;//1st element count = 1,
            //2nd element count = 2,
            //3rd element count = 3,
            //4th element count = 4,
            //5th element count = 5,
    el[rear] = elem;//1st element is stored in el[0]
                    //2nd element is stored in el[1]
                    //3rd element is stored in el[2]
                    //4th element is stored in el[3]
                    //5th element is stored in el[4]
  }
}

//PURPOSE: To remove the front element in the Queue.
//ALGORITHM:If not empty, decrement count, store the front element into e and
//          add one to front then mod QUEUE_SIZE and store the result into front.
//          Else if it's empty queueError is called.
el_t Queue::remove()
{
  if(isEmpty())//Queue is empty.
    queueError("Cannot remove because the queue is empty");
  else //Queue is not empty.
  {
    count--;
    el_t e = el[front];      //front = 0 store el[0] into e
                             //front = 1 store el[1] into e 
                             //front = 2 store el[2] into e 
                             //front = 3 store el[3] into e 
                             //front = 4 store el[4] into e 
    front = (front +1)%QUEUE_SIZE;//front is at 0 + 1 = 1 % 5 r 1
                                  //front is at 1 + 1 = 2 % 5 r 2
                                  //front is at 2 + 1 = 3 % 5 r 3
                                  //front is at 3 + 1 = 4 % 5 r 4
                                  //front is at 4 + 1 = 5 % 5 r 0
                                  //front is at 5 + 1 = 6 % 5 r 1
    return e;
  }
}

//PURPOSE: To return the front element in the queue.
//ALGORITHM:If not empty, return the front element in the queue.
//          else if it's empty queueError is called.

el_t Queue::getFront()
{
  if (!isEmpty()) //queue is not empty
   return el[front];
 else//empty
   queueError("The queue is empty");//copy and pasting caused a ?, h, H to appear.Fixed 
}

//PURPOSE:(private) to handle unexpected errors encountered by other methods.
//PARAMS: A string message to be displayed.
//ALGORITHM: Simply cout the message.
void Queue::queueError(string msg)
{
  cout << msg << endl;  
}

 //PURPOSE: Gets the front element and puts it in the back of the queue. 
 //ALGORITHM: If count equals 1 then nothing happens
 //           else remove() first and then add() in order to get the front element to go to the back
 //           of the queue. 
void Queue::goToBack()
{
  if(count == 1)
    ;//Do nothing
  else
    add(remove());//remove() returns e.
}

//PURPOSE: Returns how many elements are in the queue.
//ALGORITHM: Returns count.
int Queue::getSize()
{
  return count; //Returns how many elements are in the queue.
}

//PURPOSE: To print all the elements in the queue.
//ALGORITHM: First prints the front element in the queue and then it prints
//           the element after that and so on until there are no more elements
//           to print.

/*
void Queue::displayAll()//COMMENT OUT LATER FOR GAME.C
{
  int x = front;
  for (int i = 0; i < count; i++)
  {
    cout << el[x] << " ";
    x = (x+1)%QUEUE_SIZE;
  }
}

*/
