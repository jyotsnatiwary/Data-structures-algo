/*Chef started solving a lot of mathematics problems during the lockdown period.

He was recently trying a problem related to square numbers but couldn't solve it, so needs your help.

He has a positive number N, he wants to find out the smallest perfect square X which when added to N yields another perfect square number.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, the integer N.
Output:
For each testcase, output in a single line containing the number X. If no such number exists, print -1.

Constraints
1=T=1000
1=N=108
Subtasks
50 points : 1=N=1000
50 points : original constraints
Sample Input:
3
1
3
11
Sample Output:
-1
1
25
EXPLANATION:
In first case, there exists no perfect square which if added to 1 results in another perfect square.

In second case, 1+3=4=22.*/


#include<bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		long long n,m,a,b,x=-1; 
		cin>>n;
		m=sqrt(n);
		for(int i=1;i<=m;i++){
			if(n%i==0 && i!=n/i){
				a=(n/i-i)/2;
				b=(n/i+i)/2;
				if(n+a*a==b*b) x=a*a;
			}
		}
		cout<<x<<endl;
	}
}
