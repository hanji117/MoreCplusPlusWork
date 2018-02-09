//Edgar Cruz
//CS211 Lab5-2: postfix.C, HW3
//Stack class - Client file 
//========================================================================
#include <iostream>
#include "stack.h" //includes <string>

//prototypes
bool isOperand(char ch); 
int charToInt(char ch); 
bool isOperator(char ch); 
int doMath(int opr1, char opt, int opr2); 

//PURPOSE:To read a postfix expression from the keyboard and evaluate the experession.
int main()
{
  string expr;
  Stack myStack;//Create a stack object called myStack.
  char ch;
 
 do 
 {
 cout << "Enter an expression(type e to exit): ";
  cin >> expr;
  bool error = false;
  bool invalid = false;
  for (int i=0; i < expr.size() && !error;i++)//(there are still items left 
  {                                            //in the expression and no error).
                                               //.size() returns the number of 
                                               //bytes in the string. 
                                               //expr.length() also works.
    ch = expr[i];//gets the current character
      if(isOperand(ch))//(if character is an operand go inside)
      {
	  if (!myStack.isFull())
      	    myStack.push(charToInt(ch));	  
       	  else//stack is full
	    error = true;      
      }
      else if(isOperator(ch))//(if the character is an operator go inside)
      {
	  if (!myStack.isEmpty())
          {
	    int n = myStack.pop();//Store the popped operand into n.
	           if (!myStack.isEmpty())
	           {
		     int n2 = myStack.pop();//Store the popped operand into n2.
	             myStack.push(doMath(n2,ch,n));
	           }
                   else
		     error = true;
           } 
           else 
           error = true;
      }
      else //invalid item
      {
       error = true;    
       invalid = true;
      }
  }

  if (invalid && expr != "e")
       cout<< "Invalid expression" <<endl;

  else if (error)
  {
    if (myStack.isFull())
    {
       cout << "The program cannot handle your attempted postfix expression. It is too long."<< endl;
       myStack.clearAll();
    }
    else if(myStack.isEmpty()&& expr!= "e")
       cout << "Stack is empty. There are not enough operands." << endl; 
  }
  else //no error was found
  {  
       if (!myStack.isEmpty())
       {
	   int total  = myStack.pop();          
	   if (!myStack.isEmpty())
	   {
	     cout << "Incomplete expression" << endl;
	     // cout << "Incomplete expression was found due to" << endl;
	     //cout << "additional items being left in the stack" << endl;
             //cout << "after evaluation was completed" << endl;
	     myStack.clearAll();
	   }
           else 
	     cout << total << endl;
       }
      
  }
 }while (expr != "e");
return 0;
}
//PURPOSE: Checks to see if the character is an operand.
//PARAMS: Some character, ch
//ALGORITHM: If the character ch is bewteen 0-9 return true
//           else return false.
bool isOperand(char ch) //return true if ch is an operand (digit)
{
  if (ch >= '0' && ch <= '9')
    return true;
  else 
    return false;
}
//PURPOSE: Convert a character to an integer (if an item is a digit)
//PARAMS: Some character, ch
//ALGORITHM: Returns an integer.
int charToInt(char ch)
{
 int num = ch - '0';
 return num;
}

// PURPOSE:checks to see if the passed character is an operator: +, -, * or /
// PARAMS: some character, ch
// ALGORITHM: return true if ch is one of the operators. Otherwise, return false.
bool isOperator(char ch) //return true if ch is an operator (+, -, *, /)
{
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
    return true;
  else //ch is not an operator
    return false;
}

//PURPOSE: Does the algebra(depends on what the passed operator is)
//         for two passed operands and returns the result.
//PARAMS: Some integer opr1, some character opt, and some integer opr2.
//ALGORITHM: returns the result depending on the operatror.          
int doMath(int opr1, char opt, int opr2) //returns the result of opr1 opt opr2
{                                        //using switch 

 switch(opt)
   {
   case '+': return opr1 + opr2;
   case '-' :return opr1 - opr2;
   case '*' :return opr1 * opr2;
   case '/': return opr1 / opr2;   
   }
}
