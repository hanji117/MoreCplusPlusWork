//Edgar Cruz
//CS211 Lab 9-1: add2LargeInt.C, HW5
//LQueue class - Client file
//===================================================================
#include <iostream>
#include "LL_T.h"
//prototype
void createReverseLL(LL<int> &l, string s);
void addLLs(LL<int> & myLQ, LL<int> & myLQ2, LL<int> & myLQtotal);
int main()
{
  LL<int> l1;
  LL<int> l2;
  LL<int> total;  
  string n1, n2;
 
  cout << "Enter 2 positive integer numbers:" << endl;
  cin >> n1;
  cin >> n2;

  createReverseLL(l1, n1);
  createReverseLL(l2, n2);
  addLLs(l1, l2, total);  
  total.printAllReverse();
  cout << endl;

  return 0;
}

//PURPOSE: To convert string to integer and to reverse the Linked List.
//PARAMS: A linked Queue object l and a string s.
//ALGORITHM: While the length of the string is greater than or equal to 0
//           go inside the loop and convert the string to int and pass that 
//           integer to the addRear() function. i.e. l.addRear(num).
void createReverseLL(LL<int> &l, string s) 
{
  for(int i = s.length() - 1; i >= 0 ; i--)
  {
    int num = s[i] - '0';//789 012 to access 9 s[i]
    l.addRear(num);
  }
}

//PURPOSE: To add 2 Linked Queues.
//PARAMS: 3 Linked Queue objects called myLQ, myLQ2, and myLQtotal.
//ALGORITHM: Set carry equal to 0. While the first Linked Queue and the 
//           2nd Linked Queue are not empty enter the first loop. Deleting the 
//           front nodes from both Linked Queues returns the element that they 
//           had inside. If the sum is greater than or equal 10 then 10 is 
//           subtracted from the sum and carry becomes 1. The sum is passed 
//           to the addRear() parameter. The 3rd linked Queue calls that 
//           function. i.e. myLQtotal.addRear(sum). Else it's just
//           myLQtotal.addRear(sum). The 2nd while loop is entered if the 
//           condition fails for the first while loop. The 3rd while loop is 
//           entered if the 1st and 2nd while loop's condition fail.
//           If carry contains 1 after going through all 3 while loops then 
//           myLQtotal.addRear(carry) is executed.
void addLLs(LL<int> & myLQ, LL<int> & myLQ2, LL<int> & myLQtotal)
{
    int carry = 0;

  while(!myLQ.isEmpty() && !myLQ2.isEmpty())
  {    

    int sum = carry + myLQ.deleteFront() + myLQ2.deleteFront();

    carry = 0;
    if (sum >= 10)
    {
     sum = sum - 10;
     carry = 1;
     myLQtotal.addRear(sum); //3rd linked Queue
    }
    else
     myLQtotal.addRear(sum);
  }
  
 while(myLQ.isEmpty() && !myLQ2.isEmpty())
 { 
  int  sum = carry + myLQ2.deleteFront();
   carry = 0;

   if (sum >= 10)
   {
     sum = sum -10;
     carry =1 ;
     myLQtotal.addRear(sum);
   }
   else
     myLQtotal.addRear(sum);
 }
 
 while(!myLQ.isEmpty() && myLQ2.isEmpty())
 {
   int sum = carry + myLQ.deleteFront();
   carry = 0;
   if (sum >= 10)
   {
     sum = sum -10;
     carry =1 ;
     myLQtotal.addRear(sum);
   }
   else
     myLQtotal.addRear(sum);
 }

  if (carry == 1)
  {
    myLQtotal.addRear(carry);
    carry = 0;  
  }
}
