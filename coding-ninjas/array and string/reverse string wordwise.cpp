/*Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always*/

#include<bits/stdc++.h>
using namespace std;
/*
void reverseStringWordWise(char input[]) {
    // Write your code here
	int len=0,i=0;
while(input[i] != '\0'){
	len++;
	i++;
}
	int start=0;
	int end=len-1;
	while(start<end){
		swap(input[start], input[end]);
		start++;
		end--;
	}
	i=0;
	while(input[i]!='\0'){
		start=i;
		while(input[i]!=' '&&input[i]!='\0') 
        {
            i++;
        }
		end=i-1;
		while(start<end){
			swap(input[start], input[end]);
			start++;
			end--;
		}
        i++;
	}
	end=i-1;
	while(start<end){
			swap(input[start], input[end]);
			start++;
			end--;
		}
}
*/


#include<bits/stdc++.h>
using namespace std;

void reverse(char input[],int start,int end)
{
    while(start<end){
			swap(input[start], input[end]);
			start++;
			end--;
		}
}
void reverseStringWordWise(char input[]) {
    int s=-1;
 int i=0;
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]==' ')
        {
             reverse(input,s+1,i-1);
            s=i;
        }
       
    }
    reverse(input,s+1,i-1);
        reverse(input,0,i-1);

}
