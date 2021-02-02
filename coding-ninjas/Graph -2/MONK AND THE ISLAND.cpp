/*Monk and the Islands
Send Feedback
MONK AND THE ISLAND
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 = T = 10
1 = N = 10000
1 = M = 100000
1 = X, Y = N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2
*/

#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007
int t;
int n,m,x,y;
vi a[10001];
vi dist(10001);
vector<bool> visited(10001);
int main()
{   ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        for(int i=1;i<=n;i++){
            a[i].clear();
        }
        dist.clear();
        visited.clear();
        cin>>n>>m;
        dist.resize(n+1);
        visited.resize(n+1);
        fill(visited.begin(), visited.end(), false);
        while(m--){
            cin>>x>>y;
            a[x].PB(y);
            a[y].PB(x);
        }
        dist[1]=0;
        queue<int> s;
        s.push(1);
        visited[1]=true;
        while(!s.empty()){
            int g=s.front();
            s.pop();
            for(auto G:a[g]){
                if(visited[G]==false){
                visited[G]=true;
                dist[G]=dist[g]+1;
                s.push(G);
                }
            }
        }
        cout<<dist[n]<<"\n";
    }
    return 0;
}
