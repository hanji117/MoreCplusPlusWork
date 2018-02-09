#ifndef STACK_H
#define STACK_H

const int MAX = 3;

template<class T>
class Stack
{
 private:
  int top;
  T el[MAX];

 public:
  Stack() {top = -1;}
  bool isEmpty() {return top == -1;}
  bool isFull() {return top == MAX - 1;}
  T pop();
  void push(T);

  //Exception classes
  class Underflow {};
  //class Overflow {};
  class Overflow
  {
  private:
    T val;
  public:
    //constructor
    Overflow(T v){val = v;}
    //get function to access the private data member
    T getElem(){return val;}
  };
};

template<class T>
T Stack<T>::pop()
{
  if(isEmpty())
    //throw "Error: trying to pop when the stack is empty";
    throw Underflow();

  return el[top--];
}

template<class T>
void Stack<T>::push(T e)
{
  if(isFull())
    //throw "Error: trying to push when the stack is full";
    //throw Overflow();
    throw Overflow(e); //throws back the element that was tried to be inserted.

  el[++top] = e;
}

#endif
