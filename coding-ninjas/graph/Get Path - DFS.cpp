/*Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3*/
void getDFSPath(int **graph,int n,int *visited,int sv,int ev)
{
    visited[sv] = true;
    //Differnce 1 from DFS
    if(sv == ev)
    {
        path.push_back(ev);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(i == sv) continue;
        if(graph[sv][i] == 1)
        {
            if(visited[i]) continue;
            else
            {
                getDFSPath(graph,n,visited,i,ev);
                //Difference 2 From DFS
                if(!path.empty())
                {
                    path.push_back(sv);
                    return;
                }
            }
        }
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    int **graph = new int*[n];
    for(int i = 0;i < n; i++)
    {
        graph[i] = new int[n];
        for(int j = 0; j < n; j++) graph[i][j] = 0;
    }
    for(int i = 0; i < e; i++)
    {
        int f,s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }
    int start,end;
    cin >> start >> end;
    int *visited = new int[n];
    for(int i = 0; i < n; i++) visited[i] = 0;
    getDFSPath(graph,n,visited,start,end);
    for(int i = 0; i < path.size(); i++) cout<<path[i]<<" ";
    for(int i = 0;i < n; i++) delete [] graph[i];
    delete [] graph;
    delete [] visited;
    return 0;
}

