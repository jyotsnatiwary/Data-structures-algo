int f[1002],dp[1002];
int solve(int n,vector<int>A)
{
	for(int i=0;i<A.size();i++)
	{
		f[A[i]]++;
	}
	dp[1]=f[1];
	for(int i=2;i<=1000;i++)
	{
		dp[i]=max(dp[i-1],dp[i-2]+i*f[i]);
	}
	return dp[1000];
}
