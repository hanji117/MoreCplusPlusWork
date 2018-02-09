
#ifndef PRICE_H
#define PRICE_H

class Price
{
 private:
  int dollar;
  int cent;
 public:
  Price();//default constructor
  Price (int, int);
  Price operator+(const Price& another);
  Price operator-(const Price& other);
  int getDollar()const;
  int getCent()const;
};


#endif
