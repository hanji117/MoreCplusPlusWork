//Edgar Cruz
//CS 211 Lab11-1, HW7
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
//ALGORITHM: While the List is not empty, call deleteFront repeatedly 
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
      el_t x = temporary->element;//changed it from int to el_t.
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

//PURPOSE: To print the elements in reverse order.
//ALGORITHM: printAllReverse() is called and the front pointer
//           is passed to its parameter.
void LL::printAllReverse()
{
  printAllReverse(front);
}

//PURPOSE: To reverse the order of the elements.
//PARAMS: A pointer p
//ALGORITHM: If the pointer p is pointing to NULL then return. 
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

//PURPOSE: To add a node at the front of the linked list.
//PARAMS: New element el of type el_t.
//ALGORITHM: If the linked list is empty then create a new node and front
//           gets the new nodes address. Rear gets the fronts address.
//           front -> element refers to the element field of the node. el is
//           stored in that field. rear ->next refers to the next field of the
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

//PURPOSE: To delete the rear node in the linked list. 
//ALGORITHM: If the linked list is empty, listError is called.
//           Else if there is only one node in the LL, make a pointer p and 
//           give it the address of the node front is pointing to.
//           num gets the element that is in front->element. front->next
//           has NULL since there is only one node. rear gets NULL since front
//           is pointing to NULL. delete the node p is pointing to. decrement 
//           count return num.
//           Else if there is more than one node create a pointer p and assign
//           it the node front is pointing to. While p->next does not equal the
//           node address that rear is pointing to go inside the loop. p gets 
//           the address that p->next is pointing to. Once you're out of the 
//           while loop give x the element that's in the element field from the
//           node rear is pointing to. delete rear. rear points to the node p 
//           is pointing to. Set the next pointer equal to NULL since it's the
//           last node. Decrement count. return x.
el_t LL::deleteRear()
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
      { 
       p = p->next;
      }	
      el_t x = rear->element; 	
      delete rear;
      rear = p;
      rear ->next = NULL;
      count--;
      return x;
  }
}

//PURPOSE: To delete the node that contains the passed element e.
//PARAMS: New element e of type el_t.
//ALGORITHM: If the linked list is empty return.
//           If the first node has the element e it is deleted. 
//           Create two pointers pre and del.
//           Else pre points to the node front is pointing to. del points to the 
//           node front->next is pointing to. if del does not equal NULL and 
//           del->element does not equal e give pre the node address del is 
//           pointing to and del points to the node del->next is pointing to. If 
//           del is equal to NULL or if del->element is equal to e the condition
//           fails and you're kicked out of the for loop. The for loop is used to
//           move pre and del.
//           if del does not equal NULL pre->next points to the node del->next is
//           pointing to. if del and rear are pointing to the same node, make
//           rear point to the node pre is pointing to. delete del. 
void LL::deleteNode(el_t e)
{
  if (isEmpty())
    return;

  if(front-> element == e)//first node to be deleted
    deleteFront();

  else
  {
    node* pre;
    node* del;   
    for(pre = front, del = front-> next; del!=NULL &&del-> element != e; pre=del, del = del->next)// general case. Does not leave the for loop until condition fails.
  ;

    if (del !=NULL)//condition needed because del could be NULL.
    {
        pre-> next = del-> next;
        if (del == rear)
	  rear = pre;//since pre is right behind del.
        delete del;
    }
  }
}

//PURPOSE: Searches for the passed element e in the linked list.
//PARAMS: New element e of type el_t.
//ALGORITHM: Create a pointer p and it points to the node front is pointing to.
//           While p does not equal NULL go inside the loop. If p->element 
//           equals e return true. Else p points to the node p->next is pointing
//           to. If p equals NULL return false. 
bool LL::search(el_t e)
{
  node* p = front;
  while(p != NULL)
  {
    if (p->element == e)
      return true;//will return true if e is found in the linked list.
    else
      p = p-> next;
  }

  if (p == NULL)//if the linked list is empty, front is set equal to NULL by 
    return false;//default. That would make p == NULL and false will be returned.
}

//PURPOSE: To delete the nodes that contain the passed element e.
//PARAMS: New element e of type el_t.
//ALGORITHM: If the linked list is empty return. Create 3 pointers. Make a counter.
//           Go inside the while loop. Once the condition fails you get out of the 
//           while loop.

void LL::deleteNodes(el_t e)//e.c
{
 if (isEmpty())
    return;
  
  node* ptr1 = front;
  node* del;
  node* p = front;
  int count = 0;
  //  cout << "The first node is " << front->element << endl;
  //  displayAll(); //commented out 5/8/16
  //cout << endl;//commented out 5/8/16
  while(p !=NULL)
  {
    if (p->element == e)
    {
	if (p == front)
        {
	    front = front ->next;
        }
	del = p;
	ptr1-> next = p->next;
	p= p->next;

	//cout << "Going to delete " <<del->element <<endl;
	delete del;
	count++;
    }
    else
    {
      ptr1 = p;
      p = p -> next;
    }
  }
  //cout << "There were " << count << " deleted nodes of the element " << e << endl;
  return;
}

//PURPOSE: To put the passed element in ascending order.
//PARAMS: New element e of type el_t.
//ALGORITHM: if the linked list is empty or if the passed element e is less than
//           the element in front->element call addFront with e passed to its 
//           parameter.
//           Else create a pointer p and it points to the node front is pointing 
//           to. While p->next does not equal NULL and the element of the node 
//           pointed to by p->next is less than the new element e go inside the
//           loop. Once you get out of the loop create a pointer n and assign it
//           a new node. e is stored in the n->element field. n->next points to
//           the node p->next is pointing to. Then p->next points to the node
//           n is pointing to. p->next can only point to one node at a time so 
//           it breaks the previous link(At least that's how I see it).  
void LL::addInOrderAscend(el_t e)
{
  if (isEmpty() || e < front -> element)
    addFront(e);
  
  else
  {
         node* p = front;
       
         while(p->next != NULL && p->next->element < e)
         {
	  p = p->next;
         }
       
         node*n = new node;
         n-> element = e;
         n->next = p->next;
         p ->next = n;	
  }  
}

//PURPOSE: To put the passed element in descending order.
//PARAMS: New element  e of type el_t.
//ALGORITHM: If the linked list is empty or if the passed element e is less 
//           than the element in the front -> element call addRear with e 
//           passed to its parameter.
//           Else create a pointer p and it points to the node front is pointing    
//           to. While p->next does not equal NULL and the element of the node      
//           pointed to by p->next is greater than the new element e go inside the     
//           loop. Once you get out of the loop create a pointer n and assign it    
//           a new node. e is stored in the n->element field. n->next points to     
//           the node p->next is pointing to. Then p->next points to the node       
//           n is pointing to.                                                  
 
void LL::addInOrderDescend(el_t e)//e.c
{
  if (isEmpty() || e < front->element)
    addRear(e);
  else
    {
      node* p = front;
      while(p-> next != NULL && p->next->element > e)
	{
	  p= p -> next;
	}
      node*n = new node;
      n-> element = e;
      n->next = p-> next;
      p-> next = n;
    }
}
 
  
