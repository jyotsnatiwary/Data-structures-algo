/*Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> components;
vector<int> ind;

void DFS(int **graph,int n,int sv,int *visited)
{
    ind.push_back(sv);
    visited[sv] = true;
    for(int i = 0; i < n; i++)
    {
        if(i == sv) continue;
        if(graph[sv][i] == 1)
        {
            if(visited[i])  continue;
            else DFS(graph,n,i,visited);
        }
    }
}

void dfs_disconnected(int **graph,int n)
{
    int *visited = new int[n];
    memset(visited,0,sizeof(visited));
    for(int i = 0; i < n; i++)
    {
        ind.clear();
        if(!visited[i])
        {
            DFS(graph,n,i,visited);

            sort(ind.begin(),ind.end());
            
            components.push_back(ind);
        }
    }
    delete [] visited;
}
int main()
{
    int n,e;
    cin >> n >> e;
    int **graph = new int*[n];
    for(int i = 0;i < n; i++)
    {
        graph[i] = new int[n];
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
    }
    for(int i = 0; i < e; i++)
    {
        int f,s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
    dfs_disconnected(graph,n);
    for(int i = 0; i < components.size(); i++)
    {
        for(int j = 0; j < components[i].size(); j++)
        {
            cout<<components[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i = 0;i < n; i++)
    {
        delete [] graph[i];
    }
    delete [] graph;
    return 0;
}   
