//Edgar Cruz
//CS 211 Lab8-1, HW5
//LQueue class - implementation file
//=============================================================================

#include "lqueue.h"
#include <iostream>

//PURPOSE: Default constructor that initializes front, rear, and count
LQueue::LQueue()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//PURPOSE: To delete all the nodes in the Linked Queue.
//ALGORITHM: While the queue is not empty, call deleteFront repeatedly 
//           to delete all nodes. 
LQueue::~LQueue()
{
  while(!isEmpty())
  deleteFront();
}

//PURPOSE: To add a node at the rear of the Linked Queue. 
//PARAMS: New element e of type el_t.
//ALGORITHM: If the Linked Queue is empty then create a new node and 
//           front gets the new nodes's address. Rear gets the fronts
//           address. rear->next refers to the next field of the node. 
//           rear->next refers to the pointer to the next node. That next 
//           pointer is set to NULL. rear-> element refers to the element 
//           field of the node. e is stored in that field. Increment count.
//           Else the rear nodes's next pointer gets a new nodes address.  
//           The rear pointer gets the new nodes address by doing rear = 
//           rear->next. rear->next = NULL means that the last nodes 
//           next pointer is set to NULL. rear-> element refers to the element
//           field of the node. e is stored in that field. count is incremented. 
void LQueue::addRear(el_t e)
{
  if(isEmpty())
 {
   front = new node; //Front points to a new node
   rear = front; //Rear points to the node front is pointing to.
   rear -> next = NULL; //The last node points to nothing.
   rear-> element = e; // Put data in the rear node.
   count++; 
}
 else//This adds a node to the rear
 {
   rear->next = new node;//Make the rear node point to a new node.
   rear = rear->next;//Rear points to the new node.
   rear->next = NULL; //The last node points to nothing.
   rear-> element = e; //Put e in the new node.
   count++;
 }
}

//PURPOSE: To delete the front node in the Linked Queue.
//ALGORITHM: If the Linked Queue is empty, queueError is called. Else a 
//           temporary pointer is created and is given the address front has. 
//           The front pointer points to the next node and the address of 
//           that node is stored in front. Decrement count. Take out the 
//           element from the node that the temporary pointer is pointing to 
//           and store it in an x variable. delete the temporary pointer.
//           If the front pointer is pointing to NULL, rear is also pointing 
//           to NULL because it has to point somewhere once the last node in
//           the Linked Queue is deleted. return the element from the deleted
//           node.
el_t LQueue::deleteFront()
{
  if (isEmpty())
    queueError("Error: list is empty.");
  else//This deletes a node from the front
  { 

      node* temporary = front; 
      front = front-> next;//front will point to the second node or NULL if    
                           //there are no nodes left.
      count--;
      el_t x = temporary->element;//should be el_t instead of int.
      //changed it to el_t 5/8/16
      delete temporary;
      if(front == NULL) //if(0 == 0)
	rear = NULL; //rear gets the address of NULL which is 0.
      return x;      
  }
}

//PURPOSE: Checks to see if the Linked Queue is empty.
//ALGORITHM: If the front pointer is pointing to NULL and the rear pointer is 
//           pointing to NULL then the Linked Queue is empty and returns true
//           else false is returned.
bool LQueue::isEmpty()
{
  //  if(front == NULL || rear == NULL)//(count == 0)
if(front == NULL && rear == NULL)
    return true;
  else 
    return false;
}

//PURPOSE: To print all the nodes elements in the Linked Queue.
//ALGORITHM: If the Linked Queue is empty then cout "[ empty ]"
//           else create a temporary pointer and give it the address 
//           that the front pointer contains. While the temporary pointer is 
//           not equal to NULL cout the element of the current node that temp
//           is pointing to and then temp points to the next node.
void LQueue::displayAll()
{
  if (isEmpty())
    cout << "[ empty ]" << endl;
  else
  {
     node* temp = front;
    while(temp != NULL)
    {
      cout << temp-> element;
      temp = temp -> next;
    }
  }
}

//PURPOSE:(private) to handle unexpected errors encountered by other methods.
//PARAMS: A string message to be displayed. 
//ALGORITHM: cout the message and exit from the program.
void LQueue::queueError(string msg)
{
  cout << msg << endl;
  exit(1);
}

//PURPOSE: To print the elements in reverse order.
//ALGORITHM: printAllReverse() is called and the front pointer
//           is passed to its parameter.
void LQueue::printAllReverse()
{
  printAllReverse(front);
}

//PURPOSE: To reverse the order of the elements.
//PARAMS: A pointer p
//ALGORITHM: if the pointer p is pointing to NULL then return. 
//           else printAllReverse() is called and p-> next is passed
//           to its parameter. cout what is in the  p-> element field.
void LQueue::printAllReverse(node* p)
{
  if(p == NULL)
    return;
  else
  {
    printAllReverse(p-> next);
    cout << p-> element;
  }
}
