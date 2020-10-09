/*Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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

#include <string>
using namespace std;


string value(int n){
	if(n ==2){
		return "abc";
	}
	else if(n==3){
		return "def";
	}
	else if(n==4){
		return "ghi";
	}
	else if(n==5){
		return "jkl";
	}
	else if(n==6){
		return "mno";
	}
	else if(n==7){
		return "pqrs";
	}
	else if(n==8){
		return "tuv";
	}
	else if(n==9){
		return "wxyz";
	}
	else{
		return "";
	} 
}

int keypad(int num, string output[]){
    if(num==0){
    	output[0]="";
    	return 1;
	}
    int recursion=num/10;
    int perform=num%10;
    int out=keypad(recursion,output);
    string values=value(perform);
    //creating multiple copies of output
    for(int i=0; i<values.size()-1; i++){
    	for(int j=0; j<out; j++){
    		output[(i+1)*out + j]=output[j];
		}
	}
	int k=0;
	for(int i=0; i<values.size(); i++){
		for(int j=0; j<out; j++){
			output[k]=output[k]+values[i];
			k++;
		}
	}
	return k;
}
