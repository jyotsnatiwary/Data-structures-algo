#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Graph{
public:
    map<ll,vector<ll>>l;
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print(){
        for(auto it=l.begin();it!=l.end();it++){
            cout<<it->first<<" -> ";
            for(int j=0;j<it->second.size();j++){
                cout<<it->second[j]<<",";
            }
            cout<<"\n";
        }
    }
    void dfsUtil(int src,bool visited[],set<int>& s){
        s.insert(src);
        visited[src]=true;
        for(auto it=l[src].begin();it!=l[src].end();it++){
            if(!visited[*it]){
                dfsUtil(*it,visited,s);
            }
        }
    }
    
    int dfs(int v,int *p,int *q){
        bool visited[v+1]={false};
        for(int i=1;i<=v;i++){
            if(!visited[i]){
                set<int>s,s1,s2;
                dfsUtil(i,visited,s);
                for(auto j=s.begin();j!=s.end();j++){
                    s1.insert(p[*j]);
                    s2.insert(q[*j]);
                }
                if(s1!=s2){
                    return 0;    
                }
            }
        }
        return 1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,m,i,a,b;
        Graph g;
        cin>>n>>m;
        int *p=new int[n+1];
        int *q=new int[n+1];
        for(i=1;i<=n;i++){
            cin>>p[i];
        }
        for(i=1;i<=n;i++){
            cin>>q[i];
        }
        for(i=0;i<m;i++){
            cin>>a>>b;
            g.addEdge(a,b);
        }
        if(g.dfs(n,p,q)) cout<<"YES\n";
        else cout<<"NO\n";
        delete []p;
        delete []q;
    }
    return 0;
}

Let's consider indices as vertices of some graph and allowed pairs as 2-ways edges. Than our graph can be divided in connected components.

The key observation: we can get any permutation of elements in one connected component. And obvisously there is no way to swap to elements that belong to different components. Thus we get simple solution:

Find connected components in our graph.
For each component compare element in permuations P and Q. If these elements differ for at least one component than the answer is "NO" otherwise answer is "YES".
