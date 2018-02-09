//Edgar Cruz
//CS211 Lab6-1, HW3
//Fibonacci non-recursive - Client file
//=========================================================================
#include <time.h>
#include <iostream>
using namespace std;
//prototype
int fib(int pos);

int main()
{

  clock_t start, end;
  int pos, fibNum;
  cout << "Enter a position: ";
  cin >> pos;

  //start timing 
  start = clock();
  fibNum = fib(pos);
  //stop timing
  end = clock();
  cout << "Elapsed time: " << (end - start)/double (CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;

  //CLOCKS_PER_SEC is the number of clock ticks per second
  cout << "Fibonnaci number at position " << pos << " is " << fibNum << endl;
}
//PURPOSE: Returns the Fibonacci number at the position (passed as a parameter)
//PARAMS: Some integer, pos.
//ALGORITHM: Adds two numbers until it reaches the desired position and returns the Fibonacci number at that position.  
int fib(int pos)
{
  int slot = 0;
  int slot2 = 1;
  int x;

  for(int i = 0; i < pos; i++)
    {
      x = slot;
      slot = slot + slot2;
      slot2 = x;
    }
  return slot;
}
