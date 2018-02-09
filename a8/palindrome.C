//Edgar Cruz
//CS 211 Lab 10-2, HW6
//LL class - Client file
//=================================================================
#include "LL_T.h"
#include <iostream>
//prototypes
void createLL(LL<char>& ll, string s);
bool palindrome(LL<char>& ll);
int main()
{
  LL<char> myLL;
  string sentence;
  cout << "Enter a string"<< endl;
  getline(cin, sentence);

  createLL(myLL, sentence);
  // myLL.displayAll();
  if (palindrome(myLL) == true)
    cout << sentence << " is a palindrome" << endl;

  else 
    cout << sentence << " is NOT a palindrome" << endl;

  return 0;
}
//PURPOSE: To construct a linked list from the string minus punctuations and 
//         spaces with each node having one letter.
//PARAMS: A linked list object ll and a string s.
//ALGORITHM: Create a variable lowCh of type el_t. While i is less than the 
//           length of the string go inside the loop. If the character is a 
//           letter then make it lower case and pass it to addRear().
void createLL(LL<char>& ll, string s)
{
  char lowCh;
  for (int i = 0; i < s.length() ; i++) 
  {
      if(isalpha(s[i]))
      {
       lowCh = tolower(s[i]);
       ll.addRear(lowCh);
      }
  }
}

//PURPOSE: Checks to see if the string is a palindrome. 
//PARAMS: A linked list object ll. 
//ALGORITHM: Create char variables ch, ch2. While the linked list is not empty
//           go inside the loop. Delete the front node and store the element 
//           the deleted node returned in ch. If the linked list is not empty
//           delete the rear node and store the returned element in ch2. If 
//           ch is not equal to ch2 return false. If it gets out of the while
//           loop then it returns true.
bool palindrome(LL<char>& ll)// string s) different length because we got rid of spaces and punctuations. Different length.
{
  char ch, ch2;

  while(!ll.isEmpty())
  {
    ch = ll.deleteFront();
   
    if(!ll.isEmpty())
    {
        ch2 = ll.deleteRear();
	//cout << endl;
	//cout << ch << " " << ch2 << endl;

    if( ch != ch2)
        return false;
    }
  }
  return true;
}



