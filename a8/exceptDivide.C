#include <iostream>
using namespace std;

double divide(int top, int bottom);

int main()
{
  int top, bottom;

  cout << "Enter the top number: ";
  cin >> top;
  cout << "Enter the bottom number: ";
  cin >> bottom;

  try
    {
      cout << "The answer is " << divide(top,bottom) << endl;
    }
  //catch(string errorMsg)
  catch(const char* errorMsg)
    {
      cout << errorMsg;
    }

  cout << "\nAfter catch"<< endl;

  return 0;

}

double divide(int top, int bottom)
{
  if(bottom == 0)
    {
      //string m = "Error: devide by 0";
      //throw m;
      throw "Error: devide by 0";
    }

  return (double)top/bottom;
}
