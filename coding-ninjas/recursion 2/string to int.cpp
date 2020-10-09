/*String to Integer
Send Feedback
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 <= |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
1231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567*/

#include<bits/stdc++.h>
using namespace std;

int stringToNumber(string str) 
{  
	if (str.length() == 1) 
		return (str[0] - '0'); 
	double y = stringToNumber(str.substr(1));
	double x = str[0] - '0'; 

	// First digit multiplied by the 
	// appropriate power of 10 and then 
	// add the recursive result 
	// For example, xy = ((x * 10) + y) 
	x = x * pow(10, str.length() - 1) + y; 
	return int(x); 
} 



