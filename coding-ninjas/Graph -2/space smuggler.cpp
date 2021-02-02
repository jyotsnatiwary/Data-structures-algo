/*Space smugglers
Send Feedback
Nathan Reynolds is a famous smuggler and captain of a spaceship "Serenade".He was offered a potentially dangerous job on Ariel, one of the border planets of the 
star system. But to save all the "honest" earnings of the previous adventures, he decided to store them on one of the planets on the way to the border.

Star system is represented by  n planets and m space tunnels between them. Space tunnel is one-way wormhole to travel from one planet to another, requiring an amount of gravitonium to perform the gravity jump. There may be several space tunnels between two planets, but no space tunnel leads to the same planet it starts from.

Your task as a first officer is to find the minimum amount of gravitonium to travel from the base planet to Ariel, visiting some other planet to store the earnings, and return back to base, picking up the earnings on the way back.

Note, that storing the earnings in a base planet or the planet, where the job is taking place, is not allowed. But it's allowed to visit Ariel with the earnings as long as you are not doing a job on this planet.
Input format
The first line of input contains four integers n,  m,  s and  t — number of planets in a star system, number of space tunnels, the index number of the base planet and the index number of Ariel, respectively.

Each of the next m lines contains three integers  u,  v and g — the planet, where the space tunnel starts, the planet, where the space tunnel goes to, and the amount of gravitonium required to travel through the space tunnel, respectively ().
Constraints
2=n=10^5
1<=m<=10^5
1=s,t=n
s?t 
1=u,v=n 
1=g=103
Output format
 Output the minimum time required to travel from the base planet to Ariel, visiting some other planet to store the earnings, and return back to base, picking up the earnings on the way back, or output -1, if it's impossible.
Sample input
5 9 1 2
1 3 1
1 5 5
2 5 1
3 1 10
3 4 5
4 2 1
5 1 5
5 3 100
5 4 5
Sample output
17*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define max 100010
#define INF 10000000000
#define mp make_pair
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > pq;
vector<pii> g[max],gt[max];
void debug(vector<ll> a,int n)
{
	for(int i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
}
int main()
{
	ll n,m,s,t;
	cin>>n>>m>>s>>t;
	for(ll i=1;i<=m;i++)
	{
		ll a,b,wt;
		cin>>a>>b>>wt;
		g[a].push_back(mp(b,wt));
		gt[b].push_back(mp(a,wt));
	}
	vector<ll> dist1(max,INF),dist2(max,INF),dist3(max,INF),dist4(max,INF);
	dist1[s]=0;
	pq.push(mp(0,s));
	while(!pq.empty())
	{
		ll u,v,wet;
		pii pp=pq.top();
		pq.pop();
		u=pp.second;
		for(ll j=0;j<g[u].size();j++)
		{
			pii pp1=g[u][j];
			v=pp1.first;
			wet=pp1.second;
			if(dist1[v]>dist1[u]+wet)
			{
				dist1[v]=dist1[u]+wet;
				pq.push(mp(dist1[v],v));
			}
		}
	}
	// debug(dist1,n);
	dist2[s]=0;
	pq.push(mp(0,s));
	while(!pq.empty())
	{
		ll u,v,wet;
		pii pp=pq.top();
		pq.pop();
		u=pp.second;
		for(ll j=0;j<gt[u].size();j++)
		{
			pii pp1=gt[u][j];
			v=pp1.first;
			wet=pp1.second;
			if(dist2[v]>dist2[u]+wet)
			{
				dist2[v]=dist2[u]+wet;
				pq.push(mp(dist2[v],v));
			}
		}
	}
	// debug(dist2,n);
	dist3[t]=0;
	pq.push(mp(0,t));
	while(!pq.empty())
	{
		ll u,v,wet;
		pii pp=pq.top();
		pq.pop();
		u=pp.second;
		for(ll j=0;j<g[u].size();j++)
		{
			pii pp1=g[u][j];
			v=pp1.first;
			wet=pp1.second;
			if(dist3[v]>dist3[u]+wet)
			{
				dist3[v]=dist3[u]+wet;
				pq.push(mp(dist3[v],v));
			}
		}
	}
	// debug(dist3,n);
	dist4[t]=0;
	pq.push(mp(0,t));
	while(!pq.empty())
	{
		ll u,v,wet;
		pii pp=pq.top();
		pq.pop();
		u=pp.second;
		for(ll j=0;j<gt[u].size();j++)
		{
			pii pp1=gt[u][j];
			v=pp1.first;
			wet=pp1.second;
			if(dist4[v]>dist4[u]+wet)
			{
				dist4[v]=dist4[u]+wet;
				pq.push(mp(dist4[v],v));
			}
		}
	}
	// debug(dist4,n);
	ll ans=INF;
	for(ll i=1;i<=n;i++)
	{
		if(dist1[i]!=INF&&dist2[i]!=INF&&dist3[i]!=INF&&dist4[i]!=INF&&i!=s&&i!=t)
		{
			ans=min(ans,dist1[i]+dist2[i]+dist3[i]+dist4[i]);
		}
	}
	if(ans==INF)
		cout<<"-1\n";
	else
		cout<<ans<<endl;
}
