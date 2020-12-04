/*Shortest Subsequence
Send Feedback
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= N <= 1000
1 <= M <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.*/

int solve(string s, string v){
	int n=s.length();
	int m=v.length();
	vector<vector<int>> dp(n+1, vector<int>(m+1));
	vector<vector<int>> next(n+1, vector<int>(m+1));
	for(int i=0;i<n;i++){
		int prev=-1;
		for(int j=0;j<m;j++){
			if(s[i]==v[j]){
				prev=j;
			}
			next[i+1][j+1]=prev;
		}
	}
	for(int i=1;i<=n;i++) dp[i][0]=1;
	for(int i=1;i<=m;i++) dp[0][i]=1e9;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(next[i][j]==-1) dp[i][j]=1;
			else dp[i][j]=min(dp[i-1][j], 1+dp[i-1][next[i][j]]);
			
		}
	}
	return dp[n][m];
}

