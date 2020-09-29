/*Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false*/
#include<bits/stdc++.h>
bool ispal(char input[],int s,int e){
	if(s==e) return true;
	if(input[s]!=input[e]) return false;
	if(s<e+1) return ispal(input,s+1,e-1);
	return true;
}
bool checkPalindrome(char input[]) {
    // Write your code here
    int n=strlen(input);
    if(n==0) return true;
	return ispal(input,0,n-1);
	
}


