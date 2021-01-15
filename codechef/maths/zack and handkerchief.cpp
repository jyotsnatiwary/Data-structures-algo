/*Problem Description

Zack is a tailor by profession. He is famous for making square-shaped beautifully-cut and sewed handkerchieves.

The customers demand large-sized handkerchieves. So, now Zack is determined to get the maximum size out of the cloth. He has a rectangular piece of cloth of length 'L' and breadth 'B'.

His task is to divide it into 'N' square-shaped cloth pieces each of side length ‘S’. So he can make handkerchieves out of them of the maximum size.

Input:
The first line of the input contains T- the number of test cases. T lines follow. Each line of the test case contains L followed by B.

Output:
S -the maximum length of each square-shaped handkerchief.

Constraints:

1 <= T <= 1000

1 <= L, B <= 1000
Sample Input:

1

40 30
Sample Output:

10*/


#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if (b==0) return a;
	else return gcd(b,a%b);
}
int main(){
	int t; cin>>t;
	while(t--){
		int l,b; cin>>l>>b;
		cout<<gcd(l,b)<<endl;
	}
}
