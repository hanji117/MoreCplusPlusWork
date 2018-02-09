#include "car.h"

Car::Car(string mk,string mdl, int yr, string clr, int mlg, int p, int q)
{
  make = mk;
  model = mdl;
  year = yr;
  color = clr;
  mileage = mlg;
  x = p;
  y = q;
}

string Car::getMake() const
{
  return make;
}
string Car::getModel()const
{
  return model;
}
int Car::getYear()const
{
  return year;
}
string Car::getColor() const
{
  return color;
}
int Car::getMileage() const 
{  
return mileage;
}
int Car::getP() const
{
  return x;
}
int Car::getQ() const
{
  return y;
}

void Car::goForward(int block)
{  
  y = y + block;
   mileage = mileage + block;   

}

void Car::goBackward(int block)
{
  y = y - block;
  mileage = mileage + block;
}

void Car::goRight(int block)
{
  x = block + x;
  mileage = mileage + block;
}

void Car::goLeft(int block)
{
  x = x - block;
  mileage = mileage + block;
}

void Car::updateColor(string c)
{
  color = c;
}
