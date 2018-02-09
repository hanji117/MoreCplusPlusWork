#include <iostream>
#include "car.h"

void print(const Car & c);
int main()
{
  Car car1("Toyota", "Celica", 2016, "white", 0, 0, 0);
  Car car2("Honda", "Civic", 2008, "black", 20000, 2, 2);

  car1.goForward(3);
  car2.goBackward(1);
  car1.goRight(2);
  car2.goLeft(5);


  print(car1);
  print(car2);
  car1.updateColor("red");
  print(car1);


  return 0;
}

void print(const Car & c)
{//Client doesn't care what functions are const
  cout << c.getColor() 
       << " " 
       <<  c.getMake() 
       << " "
       << c.getModel()  
       << "("
       << c.getYear()  
       << ")" 
       << " is at location " 
       << "("
       << c.getP() 
       << ", "
       << c.getQ() 
       << ")"
       << " with mileage " 
       << c.getMileage()  
       << " miles." 
       << endl;
}
