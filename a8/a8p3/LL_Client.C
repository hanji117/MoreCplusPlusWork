#include<iostream>
using namespace std;
#include "LL_T_E.h"

int main()
{
  LL<int> l;
  try
  {
    l.deleteFront();
    //l.deleteRear();
  }
  catch(LL<int>::Underflow)
  {
    cout << "Error: list is empty."<< endl;
  }
  cout << "AFTER" << endl;
return 0;
}
