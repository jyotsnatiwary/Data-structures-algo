/*Return all codes - String
Send Feedback
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw*/

#include <bits/stdc++.h>
using namespace std;

void help(string input,string out,vector<string> &str){
    if(input.size()==0){
        str.push_back(out);
        return;
    }
    char c1=(input[0]-48)+96;
    
    //Ignore the output coming from zero in a string
    if(input[0]=='0') return;
    
    help(input.substr(1),out+c1,str);
    
    if(input.size()>1){
        int d=(input[0]-48)*10+(input[1]-48);
        if(d>26) return;
        char c2=96+d;
        help(input.substr(2),out+c2,str);
    }    
}
int getCodes(string input, string output[10000]) {
    /*You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    vector<string> str;
    string out="";
    help(input,out,str);
    
    for(int i=0;i<str.size();i++)
        output[i]=str[i];
    
    int x=str.size();    
    return x;    
}

//alternate- without recursion
int countDecodingDP(char *digits, int n) 
{ 
    // A table to store results of subproblems 
    int count[n+1];  
    count[0] = 1; 
    count[1] = 1; 
    //for base condition "01123" should return 0  
    if(digits[0]=='0')   
         return 0; 
    for (int i = 2; i <= n; i++) 
    { 
        count[i] = 0;   
        // If the last digit is not 0,  
        // then last digit must add to the number of words 
        if (digits[i-1] > '0') 
            count[i] = count[i-1]; 
  
        // If second last digit is smaller  
        // than 2 and last digit is smaller than 7, 
        // then last two digits form a valid character  
        if (digits[i-2] == '1' ||  
              (digits[i-2] == '2' && digits[i-1] < '7') ) 
            count[i] += count[i-2]; 
    } 
    return count[n]; 
} 
