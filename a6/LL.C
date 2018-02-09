//Edgar Cruz
//CS 211 Lab10-1, HW6
//LL class - implementation file
//=============================================================================

#include "LL.h"
#include <iostream>

//PURPOSE: Default constructor that initializes front, rear, and count
LL::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//PURPOSE: To delete all the nodes in the Linked List.
//ALGORITHM: While the Linked List is not empty, call deleteFront repeatedly 
//           to delete all nodes. 
LL::~LL()
{
  while(!isEmpty())
  deleteFront();
}

//PURPOSE: To add a node at the rear of the Linked List. 
//PARAMS: New element e of type el_t.
//ALGORITHM: If the Linked List is empty then create a new node and 
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
void LL::addRear(el_t e)
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

//PURPOSE: To delete the front node in the Linked List.
//ALGORITHM: If the Linked List is empty, listError is called. Else a 
//           temporary pointer is created and is given the address front has. 
//           The front pointer points to the next node and the address of 
//           that node is stored in front. Decrement count. Take out the 
//           element from the node that the temporary pointer is pointing to 
//           and store it in an x variable. delete the temporary pointer.
//           If the front pointer is pointing to NULL, rear is also pointing 
//           to NULL because it has to point somewhere once the last node in
//           the Linked List is deleted. return the element from the deleted
//           node.
el_t LL::deleteFront()
{
  if (isEmpty())
    listError("Error: list is empty.");
  else//This deletes a node from the front
  { 

      node* temporary = front; //will point to the second node
      front = front-> next;
      count--;
      el_t x = temporary->element;//I noticed (victor) had el_t and it is. But
      // it still worked with int x. So weird. Decided to change it 5/8/16.
      //In palindrome we have a function that gets rid of punctuations 
      //maybe it worked because of that.
      delete temporary;
      if(front == NULL) //if(0 == 0)
	rear = NULL; //rear gets the address of NULL which is 0.
      return x;      
  }
}

//PURPOSE: Checks to see if the Linked List is empty.
//ALGORITHM: If the front pointer is pointing to NULL and the rear pointer is 
//           pointing to NULL then the Linked List is empty and returns true
//           else false is returned.
bool LL::isEmpty()
{
  //  if(front == NULL || rear == NULL)//(count == 0)
if(front == NULL && rear == NULL)
    return true;
  else 
    return false;
}

//PURPOSE: To print all the nodes elements in the Linked List.
//ALGORITHM: If the Linked List is empty then cout "[ empty ]"
//           else create a temporary pointer and give it the address 
//           that the front pointer contains. While the temporary pointer is 
//           not equal to NULL cout the element of the current node that temp
//           is pointing to and then temp points to the next node.
void LL::displayAll()
{
  if (isEmpty())
    cout << "[ empty ]" << endl;
  else
  {
     node* temp = front;
    while(temp != NULL)
    {
      cout << temp-> element << " ";
      temp = temp -> next;
    }
  }
}

//PURPOSE:(private) to handle unexpected errors encountered by other methods.
//PARAMS: A string message to be displayed. 
//ALGORITHM: cout the message and exit from the program.
void LL::listError(string msg)
{
  cout << msg << endl;
  exit(1);
}

//PURPOSE: To print the elements in the LL in reverse order.
//ALGORITHM: printAllReverse() is called and the front pointer
//           is passed to its parameter.
void LL::printAllReverse()
{
  printAllReverse(front);
}

//PURPOSE: To reverse the order of the elements.
//PARAMS: A pointer p
//ALGORITHM: if the pointer p is pointing to NULL then return. 
//           else printAllReverse() is called and p-> next is passed
//           to its parameter. cout what is in the  p-> element field.
void LL::printAllReverse(node* p)
{
  if(p == NULL)
    return;
  else
  {
    printAllReverse(p-> next);
    cout << p-> element;
  }
}

//PURPOSE: To add a node at the front of the Linked List.
//PARAMS: New element el of type el_t.
//ALGORITHM: If the Linked List is empty then create a new node and front
//           gets the new nodes address. Rear gets the fronts address. 
//           front->element refers to the element field of the node. el is 
//           stored in that field. rear->next refers to the next field of the 
//           node. Set the next pointer equal to NULL. Increment count.
//           Else create a pointer p and assign it a new node. p->element 
//           refers to the element field of the node. el is stored there.
//           p->next points to the node that the front pointer is pointing to.
//           The front pointer gets the address of the node p is pointing to.
//           Increment count.  
void LL::addFront(el_t el)
{
  if (isEmpty())
  {
      front = new node;
      rear = front;
      front -> element = el;
      rear -> next = NULL;
      count++;
  }
  else
  {
  node* p =  new node;
  p-> element = el;
  p->next = front;
  front = p;
  count++;
  }
}

//PURPOSE: To delete the front node in the Linked List.
//ALGORITHM: If the Linked List is empty, listError is called. 
//           Else if there is only one node in the LL, make a pointer p and 
//           give it the address of the node front is pointing to. 
//           num gets the element that is in front->element. front ->next 
//           has NULL since there is only one node. rear gets NULL since front
//           is pointing to NULL. delete the node p is pointing to. decrement
//           count return num.
//           Else if there is more than one node create a pointer p and assign 
//           it the node front is pointing to. while p->next does not equal the
//           node address that rear is pointing to go inside the loop. p gets the 
//           address that p->next is pointing to. Once you're out of the while 
//           loop give x the element that's in the element field from the node 
//           rear is pointing to. delete rear. rear points to the node p is
//           pointing to. Set the next pointer equal to NULL since it's the last 
//           node. Decrement count. return x.
//           
el_t LL::deleteRear()//because it's a single linked list we have this much code.
{
  if (isEmpty())
    listError("Error: list is empty.");
  else if (count == 1)//only one node.
  {
    //deletefront. Make it from scratch for practice.
    node* p = front;
    el_t num =  front->element;
    front = front->next;
    rear = front;
    delete p;
    count--;
    return num;
  }
  else
  {
      node* p = front;
      while (p->next != rear)//the condition will get p to the 2nd to last node.
      {                      //We need to get p to the 2nd to last node. We 
	p = p->next;         //can't just go ahead and delete rear.
      }	
      el_t x = rear->element; 	
      delete rear;
      rear = p;
      rear ->next = NULL;
      count--;
      return x;
  }

}
