/*
Edgar Cruz
2/24/16
CS 211
Assignment 2
*/
#include <string>
using namespace std;

class Car
{
 private:
  string make;
  string model;
  int year;
  string color;
  int mileage;
  int x ;
  int y ;
 public:
  Car(string, string, int , string, int , int, int);
  void goForward(int );
  void goBackward(int);
  void goRight(int );
  void goLeft(int);

  string getMake() const;
  string getModel() const;
  int getYear() const;
  string getColor() const;

  int getMileage() const;
  int getP() const;
  int getQ() const;

  void updateColor(string );  
};
