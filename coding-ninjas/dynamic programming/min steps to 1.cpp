/*Code : Min Steps to 1
Send Feedback
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 10 ^ 6

Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  */

//naive
#include <bits/stdc++.h>
using namespace std;
int countStepsToOne(int n)
{
	//Write your code here
	int c=0;
	while(n!=1){
		if(n%2==0) {
			n/=2;
			c++;
		}
		if(n%3==0) {
			n/=3;
			c++;
		}
		else {
			n-=1;
			c++;
		}
	}
	return c;
}

//dynamic approach
int countStepsToOne(int n){
	int *minStep=new int[n+1];
	minStep[1]=0;
	for(int i=2;i<=n;i++){
		int a=minStep[i-1];
		int b=INT_MAX;
		int c=INT_MAX;
		if(i%2==0) b=minStep[i/2];
		if(i%3==0) c=minStep[i/3];
		minStep[i]=1+min(a,min(b,c));
	}
	int ans=minStep[n];
	delete[] minStep;
	return ans;
}




