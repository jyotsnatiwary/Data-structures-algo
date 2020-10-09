/*Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 50
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1*/



#include <bits/stdc++.h> 
using namespace std; 

int minCount(unsigned int n) 
{ 
	// if n is perfect square then Minimum squares required is 1 (144 = 12^2) 
	if (sqrt(n) - floor(sqrt(n)) == 0) 
		return 1; 
	if (n <= 3) 
		return n; 
    
	int res = n; // Maximum squares required is n (1*1 + 1*1 + ..) 

	for (int x = 1; x <= n; x++) { 
		int temp = x * x; 
		if (temp > n) 
			break; 
		else
			res = min(res, 1 + minCount(n - temp)); 
	} 
	return res; 
} 


