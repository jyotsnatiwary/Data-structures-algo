/*Chef likes prime numbers. However, there is one thing he loves even more. Of course, it's semi-primes! A semi-prime number is an integer which can be expressed as a product of two distinct primes. For example, 15=3·5 is a semi-prime number, but 1, 9=3·3 and 5 are not.

Chef is wondering how to check if an integer can be expressed as a sum of two (not necessarily distinct) semi-primes. Help Chef with this tough task!

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.
Output
For each test case, print a single line containing the string "YES" if it is possible to express N as a sum of two semi-primes or "NO" otherwise.

Constraints
1=T=200
1=N=200
Example Input
3
30
45
62
Example Output
YES
YES
NO
Explanation
Example case 1: N=30 can be expressed as 15+15=(3·5)+(3·5).

Example case 2: 45 can be expressed as 35+10=(5·7)+(2·5).

Example case 3: 62 cannot be expressed as a sum of two semi-primes.*/


#include<bits/stdc++.h>
using namespace std;

bool prime(int n){
	if(n==1) return false;
	for	(int i=2;i<n;i++){
		if(n%i==0) return false;
	}
	return true;
}
bool halfprime(int n){
	for(int i=2;i<n;i++){
		if(n%i==0 && prime(i) && prime(n/i) && i!=n/i) return true;
	}
	return false;
}

bool compute(int n){
	if(n<=4) return false;
	for(int i=5;i<n;i++){
		if(halfprime(i) && halfprime(n-i)) return true;
	}
	return false;
}

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		if(compute(n)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 

