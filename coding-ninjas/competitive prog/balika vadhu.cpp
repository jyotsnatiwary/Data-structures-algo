#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[123][123][123];
string str1,str2;
ll K;
vector<char> v;
ll N,M;
ll fun(ll idx1,ll idx2,ll remain)
{
	if(idx1==N || idx2==M)
	{
		if(remain>0)
		return -1e18;
		else
		return 0;
	}
	if(dp[idx1][idx2][remain]!=-1)
	return dp[idx1][idx2][remain];
	if(str1[idx1]==str2[idx2])
	{
		if(remain>0)
			return dp[idx1][idx2][remain]=max(str1[idx1]+fun(idx1+1,idx2+1,remain-1),max(fun(idx1+1,idx2,remain),fun(idx1,idx2+1,remain)));
		else
			return 0;
	}
	return dp[idx1][idx2][remain]=max(fun(idx1+1,idx2,remain),fun(idx1,idx2+1,remain));
}
int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		v.clear();
		memset(dp,-1,sizeof dp);
		cin>>str1>>str2;
		N=str1.size();
		M=str2.size();
		scanf("%lld",&K);
		printf("%lld\n",max(0LL,fun(0,0,K)));
	}
	return 0;
}
