#include <iostream>
#include "price.h"
using namespace std;
int main()
{
  //Create 2 prices: $2.50 and $3.75
  //Add the 2 prices.
  Price p1(2,50);
    Price p2(3,75); 
    Price total = p1 + p2;

  cout << "The total price is " 
       << total.getDollar() 
       << " dollars and " 
       << total.getCent() 
       << " cents" 
       << endl;//The total price is 6 dollars and 25 cents

  return 0;
}
