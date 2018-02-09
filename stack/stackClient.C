//why does topElem need myStack? myStack.topElem()

#include <iostream>
#include "stack.h"
using namespace std;
//prototypes
void addPerson(Stack&s, string name);
int main()
{
  Stack myStack;

 if(myStack.isEmpty())
   cout << "Stack is empty" << endl;

addPerson(myStack, "Mike");
 addPerson(myStack, "Kathy");
 cout <<  myStack.topElem() << " is at the top" << endl;
 addPerson(myStack, "Dave");
 addPerson(myStack, "Alice");
 addPerson(myStack, "Tom");
 if (myStack.isFull())
   cout << "Stack is full" << endl;

 myStack.printAll();//Display everybody in the stack.
 addPerson(myStack, "Meg");

 if (! myStack.isEmpty())  
 myStack.pop();

 cout <<  myStack.topElem() << " is at the top" << endl;
 myStack.clearAll();
 if (myStack.isEmpty())
   cout << "Stack is empty" << endl;
 return 0;
}
void addPerson(Stack&s, string name)
{
if (!s.isFull())
  s.push(name);
 else//try else if(s.isFull() 
    cout << "You cannot push. The stack is full" << endl;
}



