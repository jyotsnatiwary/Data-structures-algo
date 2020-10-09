/*Print Keypad Combinations Code
Send Feedback
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf*/

#include <iostream>
#include <string>
using namespace std;

string findstring(int num)
{   string st("");
  if(num==2)
     st="abc";
 else if(num==3)
     st="def";
 else if(num==4)
     st="ghi";
  else if(num==5)
  st="jkl";
 else if(num==6)
     st="mno";
  else if(num==7)
      st="pqrs";     
 else if(num==8)
     st="tuv";
 else if (num==9)
     st="wxyz";
return(st);
    
}
 void util(int num,string st)
 {   if(num==0)
 { cout<<st<<endl;
   return;}
  int digit=num%10;
  string temp=findstring(digit);int len=temp.size();
  //cout<<len;
  for(int i=0;i<len;i++)
      util(num/10,temp[i]+st);
     
 }



void printKeypad(int num){
  string st(" ");
    util(num,st);


}
