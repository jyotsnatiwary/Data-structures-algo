/*A permutation p1,p2...pN of {1,2,...,N} is beautiful if pi&pi+1 is greater than 0 for every 1=i<N . You are given an integer N, and your task is toconstruct a beautiful permutation of length N or determine that it's impossible.

Note that a&b denotes the bitwise AND of a and b.

Input:
First line will contain T, number of testcases. Then the testcases follow. Each testcase contains a single line of input, an integer N.

Output:
For each test case output -1 if there is no suitable permutation of length N, otherwise output N integers in a single line which form a beautiful permutation. If there are multiple answers output any of them.

Constraints
1=N=105
The sum of N over all test cases does not exceed 106
Subtasks
50 points : 1=N,T=9
50 points : Original constraints
Sample Input:
3
4
3
5
Sample Output:
-1
1 3 2
2 3 1 5 4*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==0) return 0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i&j>0) cout<<i<<" ";
				//else if(!i | !(i+1)>0) cout<<i<<" ";
			}
		}
		cout<<endl;
	}
}



