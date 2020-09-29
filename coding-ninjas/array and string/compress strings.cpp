/*Code : Compress the string
Send Feedback
Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.
Exmple:
If a String has 'x' repeated 5 times, replace this "xxxxx" with "x5".

The string is compressed only when the repeated character count is more than 1.
Note :
Consecutive count of every character in the input string is less than equal to 9.


Input Format :
The first and the only line of input contains a string(no spaces in between).
Output Format :
The only line of output print the compressed string.
 Note:
Return the compressed string and hence, no need to print.
Constraints :
0 <= |S| <= 10^7
Where |S| represents the length of string, S.

Time Limit: 1sec
Sample Input 1 :
aaabbccdsa
Sample Output 1 :
a3b2c2dsa
Sample Input 2 :
aaabbcddeeeee
Sample Output 2 :
a3b2cd2e5*/

#include<bits/stdc++.h>
using namespace std;

string stringCompression(string str)
{
    // Write your code here
    int n=str.length(),c=1;
    string op="";
    if(n==0) return "";
    op+=str[0];
    for(int i=1;i<n;i++){
    	
    	if(str[i]==str[i-1]){
    		c++;
			if(i==n-1){
				op+=to_String(count);
			}
		}
		else{
			if(c>1){
				op+=to_String(c);
				op+=str[i];
			}
			else{
				op+=str[i];
			}
			c=1;
		}
	}
	return op;
	
}

int main(){
	
}
