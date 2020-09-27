Prerequisites: BFS, Graph Theory

Problem:  If you think of the islands as the vertices of a graph, the bridges become the edges of the graph as every bridge connects two islands in the same way that every edge connects two vertices.
Now, the question asks us to find the shortest path from vertex 1 to vertex N on an unweighted graph.

Solution: To do this you can run a breadth-first search from vertex 1. The path taken by the breadth-first search to reach vertex N is guaranteed to be the shortest path from vertex 1 to N.
The following solution uses BFS for computing number of edges(bridges).
I would recommend you to read basic concepts of BFS.

Operation – 1: Initially we create an array of nodes with each node being a SET. Corresponding to the set array, we create a visit array to check whether a node has been visited or not. Initially visit array is set to false.

Operation – 2: For each pair p(a,b), we add a connection from a to b and b to a i.e. we push ‘a’ to the set node[b] and we push ‘b’ to the set node[a]. At the same time we reset visit[a] and visit[b] to false to mark them as not visited.

Operation – 3: Now we apply BFS to traverse and count the nodes. Inside BFS function we initialize a queue with starting node that is 1. Then we level order traverse. We keep a track of number of nodes encountered for every node. For ex:
For pairs
1 2
1 4
2 3
1{0} -> 2{1} -> 3{2}
-> 4{1}

Note: We use Fast IO technique for faster input and output.

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
const int N = int(1e4)+1;
const int M = int (1e5)+1;
VI g[N];
int dist[N];
int vis[N];
int main()
{
	int t;si(t);
	assert(t<=10);
	while(t--)
	{
		int n,m;
		si(n);si(m);
		assert(n<N);
		assert(m<M);
		for(int i=0;i<m;i++)
		{
			int u,v;
			si(u);si(v);
			g[u].PB(v);
			g[v].PB(u);
		}
		queue<int> Q;
		Q.push(1);
		vis[1]=1;
		dist[1]=0;
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for(int i=0;i<SZ(g[u]);i++)
				if(!vis[g[u][i]])
				{
					dist[g[u][i]]=dist[u]+1;
					Q.push(g[u][i]);
					vis[g[u][i]]=1;
				}
		}
		dout(dist[n]);
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			vis[i]=0;
		}
	}
	return 0;
}
