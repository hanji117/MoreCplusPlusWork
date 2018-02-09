//Edgar Cruz
//CS 211 Lab12-1, HW9
//DLL class - implementation file
//=============================================================================

#include "DLL.h"
#include <iostream>

//PURPOSE: Default constructor that initializes front, rear, and count
DLL::DLL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//PURPOSE: To delete all the nodes in the Double Linked List.
//ALGORITHM: While the List is not empty, call deleteFront repeatedly 
//           to delete all nodes. 
DLL::~DLL()
{
  while(!isEmpty())
  deleteFront();
}

//PURPOSE: To add a node at the rear of the Double Linked List. 
//PARAMS: New element e of type el_t.
//ALGORITHM: Increment count.
//           If the Double Linked List is empty then create a new node and 
//           front gets the new nodes's address. Rear gets the fronts
//           address. rear->next refers to the next field of the node. 
//           rear->next is the pointer to the next node. That next 
//           pointer is set to NULL. rear prev is set to NULL. 
//           rear-> element refers to the element 
//           field of the node. e is stored in that field.
//           
//           Else create a pointer p and make it point to a new node.
//           The rear nodes's next pointer gets the new nodes address.
//           (next points to the node p is pointing to).  
//           p ->prev is given the address rear is pointing to (prev points
//           to that node). rear points to the node p is pointing to.
//           rear->next = NULL means that the last nodes 
//           next pointer is set equal to NULL. rear-> element refers to the element
//           field of the node. e is stored in that field.  
void DLL::addRear(el_t e)//DLL should be ok
{
  count++; 
  if(isEmpty())
  {
    front = new node; //Front points to a new node
    rear = front; //Rear points to the node front is pointing to.
    rear -> next = NULL; 
    rear -> prev = NULL; 
    rear-> element = e; 
  }
  else//This adds a node to the rear
  {
    node*p = new node;
    rear->next = p;
    p -> prev = rear;
    rear = p;//Rear points to the new node.
    rear->next = NULL; //The last node points to nothing.
    rear-> element = e; //Put e in the new node.
  }
}

//PURPOSE: To delete the front node in the Double Linked List.
//ALGORITHM: If the Double Linked List is empty, listError is called. 
//           Store the front's element in a variable x.
//           if count equals 1, delete the node front is pointing to and set
//           front and rear equal to NULL.
//           else if count is greater than 1, front gets the address that 
//           front next is pointing to. delete front-> prev deletes the node
//           front was originally pointing to. front-> prev is set equal to NULL.
//           Decrement count and return x (the element from the deleted node).

el_t DLL::deleteFront()//DLL should be ok here.
{
  if (isEmpty())
    listError("Error: list is empty.");//exit(1) remember. Doesn't go any further than 
  //this if it's empty.
  
  el_t x = front ->element;

  if (count == 1)
  {
    
    delete front;
    front = rear = NULL;
  }
  else if (count > 1)
  { 

    front = front ->next;
    delete front->prev;
    front->prev = NULL;
  }
  count--;
  return x;
}

//PURPOSE: Checks to see if the Double Linked List is empty.
//ALGORITHM: If the front pointer is pointing to NULL and the rear pointer is 
//           pointing to NULL then the Double Linked List is empty and returns true
//           else false is returned.
bool DLL::isEmpty()
{
if(front == NULL && rear == NULL)
    return true;
  else 
    return false;
}

//PURPOSE: To print all the nodes elements in the Double Linked List.
//ALGORITHM: If the Double Linked List is empty then cout "[ empty ]"
//           else create a temporary pointer and give it the address 
//           that the front pointer contains. While the temporary pointer is 
//           not equal to NULL cout the element of the current node that temp
//           is pointing to and then temp points to the next node.
void DLL::displayAll()
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
void DLL::listError(string msg)
{
  cout << msg << endl;
  exit(1);
}

//PURPOSE: To print the elements in reverse order.
//ALGORITHM: printAllReverse() is called and the front pointer
//           is passed to its parameter.
void DLL::printAllReverse()
{
  printAllReverse(front);
}

//PURPOSE: To reverse the order of the elements.
//PARAMS: A pointer p
//ALGORITHM: If the pointer p is pointing to NULL then return. 
//           else printAllReverse() is called and p-> next is passed
//           to its parameter. cout what is in the  p-> element field.
void DLL::printAllReverse(node* p)
{
  if(p == NULL)
    return;
  else
  {
    printAllReverse(p-> next);
    cout << p-> element;
  }
}

//PURPOSE: To add a node at the front of the Double linked list.
//PARAMS: New element el of type el_t.
//ALGORITHM: If the Double linked list is empty then create a new node and front
//           gets the new nodes address. Rear gets the fronts address.
//           front -> element refers to the element field of the node. el is
//           stored in that field. rear ->next refers to the next field of the
//           node. Set the next pointer equal to NULL. set prev equal to NULL.
//           increment count.
//           Else create a pointer p and assign it a new node. p->element 
//           refers to the element field of the node. el is stored there.
//           p->next points to the node that the front pointer is pointing to.
//           p->prev is set to NULL since it's a DLL.
//           prev points to the new node. front points to the node p is 
//           pointing to.
//           Increment count.
void DLL::addFront(el_t el)//DLL should be ok just 
{
  if (isEmpty())
  {
      front = new node;
      rear = front;
      front -> element = el;
      rear -> next = NULL;
      front -> prev = NULL;
      count++;
  }
  else
  {
      node* p =  new node;
      p-> element = el;
      p->next = front;
      p-> prev = NULL;
      front->prev = p;
      front=p;
      count++;
      
  }
}

//PURPOSE: To delete the rear node in the Double linked list. 
//ALGORITHM: If the Double linked list is empty, listError is called.
//           rear element is stored in x. 
//           if count in greater than 1, create a d pointer and make it 
//           point to rear. rear points to what rear-> prev
//           is pointing to. delete d. rear-> next is set equal to NULL.
//          
//           else if count equals 1, delete rear and set rear and front 
//           equal to NULL. Decrement count and return x.
el_t DLL::deleteRear()//DLL should be ok here.
{
  if (isEmpty())
    listError("Error: list is empty.");
  
  el_t x = rear -> element;
   
  if (count > 1)
  {
    node* d = rear;
    rear = rear -> prev;
    delete d;
    rear-> next = NULL;
  }
  else if (count == 1)
  {
    delete rear;
    rear = front = NULL;
  }

    count--;
    return x;
}

//PURPOSE: To delete the node that contains the passed element e.
//PARAMS: New element e of type el_t.
//ALGORITHM: if the DLL is empty return. if the front element equals 
//           the passed element, deleteFront.
//           else create a pointer p and make it point to front.
//           while p does not equal NULL and p element does not 
//           equal e make p point to the node next is pointing to.
//           if p does not equal NULL go inside. 
//           if p equals rear go inside. rear points to what prev is
//           pointing to. delete p. set rear next equal to NULL.
//           decrement count. 
//           else the node p next is pointing to  and the prev  of that
//           node get what p prev is pointing to.
//           the node p-> prev is pointing to and the next of that 
//           node get what p next is pointing to. 
//           delete p and decrement count.
void DLL::deleteNode(el_t e)//DLL ok
{
  if (isEmpty())
    return;

  if(front-> element == e)
  {
      deleteFront();
  }
  else
  {
    node *p = front;
    while (p != NULL && p->element != e ) 
    {
      p= p->next;
    }
    if(p != NULL )
    {
      if (p == rear)
      {
	 rear = rear -> prev;
	 delete p;
	 rear->next = NULL;
	 count--;
      }
      else
      {
	 p->next -> prev = p-> prev;
	 p->prev->next = p-> next;
	 delete p;
	 count--;
      }
    }  
  }
}
//PURPOSE: Searches for the passed element e in the Double linked list.
//PARAMS: New element e of type el_t.
//ALGORITHM: Create a pointer p and it points to the node front is pointing to.
//           While p does not equal NULL go inside the loop. If p->element 
//           equals e return true. Else p points to the node p->next is pointing
//           to. If p equals NULL return false. 
bool DLL::search(el_t e)
{
  node* p = front;
  int num = 0;
  while(p != NULL)
  {
    num++;
    if (p->element == e)
    {
      // cout << num << " nodes checked" << endl;
      return true;//will return true if e is found in the Double linked list.
    }
    else
      p = p-> next;
  }

  if (p == NULL)//if the linked list is empty, front is set equal to NULL by 
  {
    //cout << num << " nodes checked" << endl;
    return false;//default. That would make p == NULL and false will be returned.
  }
}

//PURPOSE: To delete the nodes that contain the passed element e.
//PARAMS: New element e of type el_t.
//ALGORITHM: If the Double linked list is empty return. Create 3 pointers. Make a counter.
//           Go inside the while loop. Once the condition fails you get out of the 
//           while loop.

void DLL::deleteNodes(el_t e)//e.c
{
 if (isEmpty())
    return;
  
  node* ptr1 = front;
  node* del;
  node* p = front;
  int count = 0;
  //  cout << "The first node is " << front->element << endl;
  displayAll();
cout << endl;
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
    else{
      ptr1 = p;
      p = p -> next;
    }
  }
  //cout << "There were " << count << " deleted nodes of the element " << e << endl;
  return;
}

//PURPOSE: To put the passed element in ascending order.
//PARAMS: New element e of type el_t.
//ALGORITHM: if the Double linked list is empty or if the passed element e is less than
//           the element in front->element call addFront with e passed to its 
//           parameter and return.
//           if e is greater than or equal to rear->element go inside.
//           call addRear with e passed to it's parameter and return.
//
//           Else create a pointer p and it points to the node front is pointing 
//           to. While p->next does not equal NULL and the element of the node 
//           pointed to by p->next is less than the new element e go inside the
//           loop. p points to what p next is pointing to.
// 
//           Once you get out of the loop create a pointer n and assign it
//           a new node. e is stored in the n->element field. n->next points to
//           the node p->next is pointing to. n prev points to the node p is 
//           pointing to. the node p next is pointing to it's prev pointer points
//           to the node n is pointing to. p next points to the node n is 
//           pointing to. increment count.
void DLL::addInOrderAscend(el_t e)
{
  if (isEmpty() || e < front -> element)
  {
    addFront(e);
    return;
  }
  if( e >= rear->element)
    {
      addRear(e);
      return;
    }  

  else
  {
         node* p = front;
       
         while(p->next != NULL && p->next->element < e)
         {
	  p = p->next;
         }
       
         node* n = new node;
         n-> element = e;
	 n-> next = p-> next;
	 n -> prev = p;
         p->next->prev = n;
         p->next = n;
  }  
  count ++;
}

//PURPOSE: To put the passed element in descending order.
//PARAMS: New element e of type el_t.
//ALGORITHM: If the Double linked list is empty or if the passed element e is less 
//           than the element in the front -> element call addRear with e 
//           passed to its parameter.
//           Else create a pointer p and it points to the node front is pointing    
//           to. While p->next does not equal NULL and the element of the node      
//           pointed to by p->next is greater than the new element e go inside the     
//           loop. Once you get out of the loop create a pointer n and assign it    
//           a new node. e is stored in the n->element field. n->next points to     
//           the node p->next is pointing to. Then p->next points to the node       
//           n is pointing to.                                                  
 
void DLL::addInOrderDescend(el_t e)//e.c
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

//PURPOSE: To print the DLL in reverse order.
//ALGORITHM: if the DLL is empty cout message.
//           create a node pointer p and make it point to
//           the node rear is pointing to.
//           while p is not equal to NULL cout p-> element
//           and p points to the node p-> prev is pointing to.
void DLL::printAllReverseDLL()//DLL should be ok
{
  if (isEmpty())
    cout << "[empty]";

  node* p = rear;
  while (p != NULL)
  {
    cout << p-> element << " ";
    p = p -> prev;
  }
} 
  
