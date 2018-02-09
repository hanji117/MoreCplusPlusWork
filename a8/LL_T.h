#ifndef LL_H
#define LL_H

#include <iostream>
using namespace std;

template<class T>
struct node
{
  T element;
  node<T>* next;
};

template <class T>
class LL
{
 private:
  node<T>* front;
  node<T>* rear;
  int count;
  void listError(string);
 public:
  LL();
  ~LL();
  bool isEmpty();
  void addRear(T);
  T deleteFront();
  void displayAll();
  void printAllReverse();
  void printAllReverse(node<T>* p);
  void addFront(T el);
  T deleteRear();
  void deleteNode(T);
  void deleteNodes(T e);
  void addInOrderAscend(T e);
  void addInOrderDescend(T);
  bool search(T);
};

template <class T>
LL<T>::LL()
{
  front = NULL;
  rear = NULL;
  count = 0;
}

template <class T>
LL<T>::~LL()
{
  while(!isEmpty())
    deleteFront();
}

template <class T>
void LL<T>::addRear(T e)
{
  if(isEmpty())
  {
    front = new node<T>; //Front points to a new node                            
    rear = front; //Rear points to the node front is pointing to.              
    rear -> next = NULL; //The last node points to nothing.               
    rear-> element = e; // Put data in the rear node.                         
    count++;
  }
  else//This adds a node to the rear                                          
  {
    rear->next = new node<T>;//Make the rear node point to a new node. 
    rear = rear->next;//Rear points to the new node.                       
    rear->next = NULL; //The last node points to nothing.
    rear-> element = e; //Put e in the new node.                      
    count++;
  }
}
template <class T>
T LL<T>::deleteFront()
{ 
  if(isEmpty())
    listError("Error: list is empty.");
  else
  {
    node<T>* temporary = front;
    front = front ->next;
    count--;
    T x = temporary -> element;
    delete temporary;
    if (front == NULL)
      rear = NULL;
    return x;
  }
}
template <class T>
bool LL<T>::isEmpty()
{
  if(front == NULL && rear == NULL)
    return true;
  else 
    return false;
}
template <class T>
void LL<T>::displayAll()
{
  if (isEmpty())
    cout << "[ empty ]" << endl;
  else
  {
    node<T>* temp = front;
    while(temp != NULL)
    {
      cout << temp-> element << " ";
      temp = temp -> next;
    }
  }
}

template <class T>
void LL<T>::listError(string msg)
{
  cout << msg << endl;
  exit(1);
}

template <class T>
void LL<T>::printAllReverse()
{
  printAllReverse(front);
}

template <class T>
void LL<T>::printAllReverse(node<T>* p)
{
  if (p == NULL)
    return;
  else
  {
    printAllReverse(p-> next);
    cout << p-> element;
  }
}

template <class T>
void LL<T>::addFront(T el)
{
  if (isEmpty())
  {
    front = new node<T>;
    rear = front;
    front -> element = el;
    rear -> next = NULL;
    count++;
  }
  else
  {
    node<T>* p = new node<T>;
    p -> element = el;
    p-> next = front;
    front = p;
    count++;
  }
}

template <class T>
T LL<T>::deleteRear()
{
  if (isEmpty())
    listError("Error: list is empty.");

  else if (count == 1)
  {
    node<T>* p = front;
    T num = front->element;
    front = front->next;
    rear = front;
    delete p;
    count--;
    return num;
  }
  else
  {
    node<T>* p = front;
    while (p->next != rear)
    {
      p = p->next;
    }
    T x = rear->element;
    delete rear;
    rear = p;
    rear->next = NULL;
    count--;
    return x;
  }
}

template<class T>
void LL<T>::deleteNode(T e)
{
  if (isEmpty())
    return;

  if (front-> element == e)
    deleteFront();

  else
  {
    node<T>* pre;
    node<T>* del;
    for(pre = front, del = front->next; del!=NULL &&del->element !=e; pre=del,del = del->next);

    if(del !=NULL)
    {
      pre ->next = del->next;
      if(del==rear)
	rear = pre;
      delete del;
    }
  }
}

template<class T>
bool LL<T>::search(T e)
{
  node<T>* p = front;
  int num = 0;
  while(p != NULL)
  {
    num++;
    if(p->element == e)
    {
      cout << num << " nodes checked" << endl;
      return true;
    }
    else
      p = p-> next;
  }

  if (p == NULL)
  {
    cout << num << " nodes checked" << endl;
    return false;
  }
}

template<class T>
void LL<T>::deleteNodes(T e)
{
  if (isEmpty())
    return;

  node<T>* ptr1 = front;
  node<T>* del;
  node<T>* p = 0;
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
      ptr1->next = p->next;
      p = p->next;
      delete del;
      count++;
    }
    else
    {
      ptr1 = p;
      p = p -> next;
    }
  }
  return;
}

template<class T>
void LL<T>::addInOrderAscend(T e)
{
  if (isEmpty() || e < front -> element)
    addFront(e);
  else
  {
    node<T>* p = front;
    while(p->next != NULL && p->next->element < e)
    {
      p = p->next;
    }
    node<T>* n = new node<T>;
    n -> element = e;
    n->next = p->next;
    p->next = n;
  }
}

template<class T>
void LL<T>::addInOrderDescend(T e)
{
  if (isEmpty() || e < front->element)
    addRear(e);
  else
  {
    node<T>* p = front;
    while(p->next !=NULL && p->next->element > e)
    {
      p = p -> next;
    }
    node<T>* n = new node<T>;
    n-> element = e;
    n->next = p-> next;
    p-> next = n;
  }
}
#endif
