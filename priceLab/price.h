
#ifndef PRICE_H
#define PRICE_H

class Price
{
 private:
  int dollar;
  int cent;
 public:
  Price (int, int);
  Price operator+(const Price& another);
  int getDollar()const;
  int getCent()const;
};


#endif
