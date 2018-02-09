/*
Edgar Cruz
CS211 Lab6-1, HW3
Fibonacci recursive - Client file
===================================================================================
*/
#include <iostream>
#include <time.h>
using namespace std;
//prototype
int fib(int pos);

//PURPOSE: A recursive function will calculate a Fibonacci number at a specified position.
int main()
{
 clock_t start, end;
 int pos,fibNum;
 cout << "Enter a position: ";
 cin >> pos;
 //start timing
 start = clock(); //clock() returns the number of clock 
                  //ticks elapsed since the beginning of
                  //the program execution.
 fibNum = fib(pos);//Calculate a Fibonacci number at a specified position.
 //stop timing
 end = clock();
 cout << "Elapsed time: " << (end - start)/double(CLOCKS_PER_SEC)*1000 << " milliseconds" << endl;
 //CLOCKS_PER_SEC is the number of clock ticks per second
 
 cout << "Fibonnaci number at position " << pos << " is " << fibNum << endl; 
 return 0;
}

//PURPOSE: This function will return the Fibonacci number 
//         at the position (passed as a parameter)
//         e.g. fib(6) returns 8, fib(3) returns 2 
//PARAMS: some integer, pos
//ALGORITHM: If pos <= 1 return pos
//           else return fib(pos-2) + fib(pos-1).
int fib(int pos)
{
  if(pos <= 1) //position is 0 or 1 (base cases) 
    return pos;
  else
    //return fib(pos - 2) + fib(pos – 1);
    return fib(pos-2) + fib(pos-1);
}
