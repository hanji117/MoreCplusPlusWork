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
