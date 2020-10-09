/*Strings of Length k
Send Feedback
Given a string S and an integer k, you need to find and return all the possible strings that can be made of size k using only characters present in string S.
The characters can repeat as many times as needed.
Note : The number of output strings can be at max 1000.
Input format :
String S and Integer k (separated by space)
Output Format :
All possible strings (in different lines)
Constraints :
1 <= Length of String S <= 10
1 <= k <= 5
Sample Input 1 :
abc 2
Sample Output 1 :
aa
ab
ac
ba
bb
bc
ca
cb
cc*/

#include<bits/stdc++.h>
using namespace std;
int t = 0;

int count(char set[], string prefix, int n, int k, char o[][100]) 
{ 

    if (k == 0) 
    { 
        t++ ;
        for(int a=0; a<prefix.size(); a++)
            o[t][a] = prefix[a];
        return 0; 
    } 
      for (int i = 0; i < n; i++) 
    { 
        string newPrefix; 
        newPrefix = prefix + set[i]; 
        count(set, newPrefix, n, k - 1,o); 
    } 
  
} 

int allStrings(char input[], int k, char output[][100]) {
 // Write your code here
    t = 0;
    char temp[k+1];
    count(input, "", strlen(input),k, output);
    return t+1;
}
