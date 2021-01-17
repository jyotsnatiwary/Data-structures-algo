/*Coach Moony wants the best team to represent their college in ICPC. He has N students standing in a circle with certain rating Xi on a competitive coding platform. It is an established fact that any coder with more rating on the platform is a better coder.

Moony wants to send his best 3 coders based upon their rating. But all coders only want to have their friends in their team and every coder is friends with four other coders, adjacent two on left side in the circle, and adjacent two on right. So Moony comes up with a solution that team with maximum cumulative rating of all three members in a team shall be representing their college.

You need to give the cumulative score of the team that will be representing the college.

Input:
First line will contain T, number of testcases.
First line of each test case contains a single integer N.
Second line of each test case takes N integers, denoting rating of ith coder.
Output:
For each testcase, output a single integer denoting cumulative rating of the team.

Constraints
1=T=10
7=N=105
0=Xi=109
Sample Input:
1
7
10 40 30 30 20 0 0

Sample Output:
100*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int t; cin>>t;
	while(t--){
		int N; cin>>N;
		//int ar[n];
		//for(int i=0;i<n;i++) cin>>ar[i];
		vector<int> a(N);
    for(int &x : a)
        cin >> x;
    int ans = 0;
    for(int i = 0; i < N; ++i)
        ans = max(ans, a[i] + a[(i + 1) % N] + a[(i + 2) % N]);
    cout << ans << '\n';
	}
}



