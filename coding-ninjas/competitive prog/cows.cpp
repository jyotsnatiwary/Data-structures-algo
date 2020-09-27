#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define eps 1e-9
#define maxp 100000
#define mod 1000000007
#define sin(s) scanf("%lld",&s);
#define sout(s) printf("%lld\n",s);
#define in(s) cin>>s
#define in2(a,b) cin>>a>>b
#define out(s) cout<<s
#define outs(s,a) cout<<s<<a
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define gear_change ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define nfl(i,n) for(i=0;i<n;i++)
#define sfl(i,s,e) for(i=s;i<e;i++)
#define ufl(i,n) for(i=n-1;i>=0;i--)
bool check(ll dis,ll a[],ll n,ll c)
{
	ll last=a[0],cows_that_fit=1,i;
	for(i=0;i<n;i++)
	{
		if(a[i]-last>=dis)
		{
			last=a[i];
			cows_that_fit++;
		}
	}
	if(cows_that_fit>=c)
		return true;
	return false;
}
void solve()
{
	ll c,n,i,k,p;
	in(n),in(c);
	ll a[n];
	nfl(i,n)
	{
		in(a[i]);
	}
	sort(a,a+n);
	ll low=0,high=1000000000,mid,pos=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(check(mid,a,n,c))
		{
			low=mid+1;
			pos=mid;
		}
		else
		{
			high=mid-1;
		}
	}
	cout<<pos<<"\n";
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in00.txt","r",stdin);
	freopen("out00.txt","w",stdout);
	#endif
	gear_change;
	ll test=1;
	in(test);
	while(test--)
	{
		solve();
	}
}	
