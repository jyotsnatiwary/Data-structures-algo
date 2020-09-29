/*Code : Reverse each word
Send Feedback
Given a string S, reverse each word of a string individually. For eg. if a string is "abc def", reversed string should be "cba fed".
Input Format :
String S
Output Format :
Modified string
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
emocleW ot gnidoC sajniN
Sample Input 2:
Give proper names to variables and functions
Sample Output 2:
eviG reporp seman ot selbairav dna snoitcnuf*/

// input - given string
// Update in the given input itself. No need to return or print anything
#include<bits/stdc++.h>
using namespace std;

/*char reverse(input,start, end){
	int mid=(start+end)/2;
	int i=start;
	while(i<mid){
		swap(input[i],input[end]);
		i++;
		end--;
	}
	return;
}*/
void reverse(char input[],int start,int end){
	while(start<end){
		std::swap(input[start++],input[end--]);
	}
}
	
void reverseEachWord(char input[]) {
    // Write your code here
    int prev=-1, i=0;
    for(;input[i]!='\0';i++){
    	if(input[i]==" "){
    		reverse(input,prev+1,i-1);
    		prev=i;
		}
	}
	reverse(input,prev+1,n-1);
}


