#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int main() {
	int n,m;
	cin >> n >> m;
	int a[n][m],dp[n][m];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			dp[i][j] = 0;
			cin >> a[i][j];
		}
	}
	for(int i=0;i<m;i++) {
		dp[0][i] = a[0][i];
	}
	for(int i=1;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(j == 0) {
				dp[i][j] = a[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
			} else if(j == m-1) {
				dp[i][j] = a[i][j] + min(dp[i-1][j-1],dp[i-1][j]);
			} else {
				dp[i][j] = a[i][j] + min(min(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1]);
			}
		}
	}
	int ans = 1e9;
	for(int i=0;i<m;i++) ans = min(ans,dp[n-1][i]);
	cout << ans << endl;
  	return 0;
}

