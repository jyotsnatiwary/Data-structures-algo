#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
#define MOD 1000000006
#define M 1000000007
long long int a,b,c,d;
ll fir,sec;
void fast_fib(long long int n,long long int ans[])
{
    if(n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n/2),ans);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      /* F(2n) */
    d = (a*a + b*b) % MOD;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
    }
}
ll powd(ll base, ll exp,ll mod) {
    ll res=1;
    while(exp>0) {
       if(exp&1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    long long int n;        /* nth value to be found */
	    scanf("%lld %lld",&fir,&sec);
	    scanf("%lld",&n);
	    long long int ans[2]={0};
	    fast_fib(n,ans);
	    //printf("%lld\n", ans[0]);
	    //printf("%lld %lld\n\n",ans[0],ans[1]);
	    ans[1]-=ans[0];
	    ans[1]=(ans[1]+MOD)%MOD;
	    ll answer = powd((1+ fir),ans[1],M);
	    answer =  (answer*powd(1+sec,ans[0],M))%M;
	    answer =(answer-1+M)%M;
	    printf("%lld\n",answer);
	}
    return 0;
