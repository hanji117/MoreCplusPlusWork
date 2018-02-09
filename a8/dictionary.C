//Edgar Cruz
//CS 211 Lab 12-1 Dictionary.C, HW 7
//LL class - client file
//=============================================================

#include <iostream>
#include <fstream> //for files
#include "LL_T.h"
using namespace std;

//PURPOSE: Builds the linked list.
//PARAMS: A linked list object LinkedList.
//ALGORITHM: Create a string variable word, ifstream variable fin, and a char 
//           variable lowCh. Open essay.txt. If it doesn't exist cout message.
//           Else go in the while loop. If there is a capital letter it changes to //           lower case. Then it checks to see if there are any puctuations and 
//           deletes them. If the word is not in the linked list add it in 
//           ascending order. Close the file.   
void buildLL(LL<string> & LinkedList)
{
  //char letter;
  string word;
  ifstream fin;
  char lowCh;

  fin.open("essay.txt");
  
  if (!fin)
    cout << " essay doesn't exist " << endl;
  else 
    {
      while (fin >> word)//same as below
      {
	for (int i = 0; i <= word.length()-1; i++)
	  if (isalpha(word[i]))
          {
	  lowCh = tolower(word[i]);
	  word[i] = lowCh;	  
          }
        if(!isalpha(word[word.length()-1]))
        { //I dont know whats going on.
	  //use a function word.substr
	  word = word.substr(0, word.length()-1);  
        }
    
    if(!LinkedList.search(word))
    LinkedList.addInOrderAscend(word);
 }

  fin.close();
}
}
//PURPOSE: To remove bad words.
//PARAMS: A linked list object called link.
//ALGORITHM: Create a string variable word and create an ifstream variable inFile.
//           Open the file badWords.txt. If the word is found in the linked list
//           delete it.   
void removeBadWords(LL<string> & link)
{
  string word;
  ifstream inFile;
  inFile.open("badWords.txt");

  while (inFile >> word)
  if (link.search(word))
    link.deleteNode(word);

  inFile.close();
}
  
//PURPOSE: To create the .txt files.
//PARAMS: A linked list object called Link_List.
//ALGORITHM: Create variables that will be needed. While the linked list is not 
//           empty go inside the while loop. If the word is not in the list 
//           then put it in the appropriate .txt file in the dictionary2 directory.
void outputToFile(LL<string> & Link_List)
{
  string word;
  string fileName;
  //  LL templA;
  //LL templB;
  ofstream outFile;
  char ourLet = '?';//dummy
  char previous;//

  while(!Link_List.isEmpty())
  {
      previous = ourLet;
      word = Link_List.deleteFront();
      ourLet = toupper(word[0]);
      cout << previous << " " << ourLet << endl;
      if (ourLet != previous)
      {
     
	//if 
	fileName= "./dictionary2/";
	fileName += toupper(word[0]);
	fileName += ".txt";
	outFile.close();
	
	outFile.open(fileName.c_str());
	cout << fileName << endl;
       
      }
      outFile << word << endl;
    }

}
//rm *.txt to clear .txt files.


int main()
{
  LL<string> myLL;
  buildLL(myLL);
 
  removeBadWords(myLL);  
  myLL.displayAll(); 
  outputToFile(myLL);

return 0;
}
  
