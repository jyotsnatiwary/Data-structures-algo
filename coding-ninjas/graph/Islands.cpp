/*Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 */

#include <bits/stdc++.h>

using namespace std;

void DFS(int** arr, int* visited, int n, int sv){

	visited[sv] = 1;

	for (int i = 0; i < n; ++i)
	{
		if (i==sv)
		{
			continue;
		}
		if (arr[sv][i] == 1 && visited[i] == 0)
		{
			DFS(arr, visited, n, i);
		}
	}

	return;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	int** arr = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			arr[i][j] = 0;
		}
	}



	for (int i = 0; i < m; ++i)
	{
		arr[u[i]][v[i]] = 1;
		arr[v[i]][u[i]] = 1;
	}

	int* visited = new int[n];

	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}

	int count = 0;
    
    for (int i = 0; i < n; ++i)
    {
        // cout<<i<<" "<<visited[i]<<endl;
        if (visited[i]==0)
        {
            // cout<<i<<" temp-> ";
            count++;
            DFS(arr, visited, n, i);
        }
    }

	return count;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 

	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
        // cout<<x<<" ";
		u.push_back(x);
        v.push_back(y);
	}
	cout<<solve(n,m,u,v)<<endl;

}
