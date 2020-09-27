#include <bits/stdc++.h>
#define MX 100005
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int const md=1e9+7;
vector<int> G[MX];
int vis[MX];
stack<int> s;
void dfss(int u)
{
	vis[u]=1;
	for(auto v:G[u])
	{
		if(!vis[v])
			dfss(v);
	}
	s.push(u);
	
}
void dfs(int u)
{
	vis[u]=1;
	for(auto v:G[u])
	{
		if(!vis[v])
			dfs(v);
	}
	
}
int main() 
{	
	
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<MX;i++)
			G[i].clear();
		memset(vis,0,sizeof(vis));
		while(!s.empty())
			s.pop();
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
		}
		
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
				dfss(i);
		}
		memset(vis,0,sizeof(vis));
		int c=0;
		while(!s.empty())
		{
			int u=s.top();s.pop();
			if(!vis[u])
			{
				dfs(u);
				c++;
			}
		}
		
		cout<<c<<endl;
		
		
	}
	return 0;
}

Give the relationship between dominoes falling down. If u falls down, then V falls down. 
Then ask at least how many times you need to manually let one 
card fall so that all cards fall. ? Idea: We first find out all 
the strong connected components, and then we find out a dag. We 
regard each component as a point, because if any card in it 
falls, all the cards in it will follow. So at this time, how
 many points are equal to 0, you need to manually push down how 
 many cards.
