#include "price.h"

Price::Price (int d, int c)
{
  dollar = d;
  cent = c;
}

Price Price::operator+(const Price& another)
{
  int doll = this-> dollar + another.dollar;
  int centQ = this ->cent + another.cent;
  
if (centQ >= 100)
{ 
 doll = doll + 1;
 centQ = centQ - 100;
}
  Price p(doll, centQ);
  return p;
}

int Price::getDollar()const
{
  return dollar;
}

int Price::getCent()const
{
  return cent;
}

//This one works only if the first price is greater
//than the second price
Price Price::operator-(const Price& other)
{
  //convert each price to cents
  int p1 = this->dollar * 100 + this->cent;
  int p2 = other.dollar * 100 + other.cent;
  int diff;
  //if the first price is greater than or equal to the second price
  if(p1 >= p2)
    {
      diff = p1 - p2;
      Price diffOb(diff/100, diff%100);
      return diffOb;
    }
  else //if the first price is less than the second price
    {
      Price negOb(-9999999, -9999999);//Don't do the math if p2 is less than p1
      return negOb;
    }
}
Price::Price()
{
  dollar = 0;
  cent = 0;
}
