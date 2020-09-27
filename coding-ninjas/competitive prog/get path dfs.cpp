#include <iostream>
using namespace std;
bool dfs (int**edge,bool *visited,int si,int ei,int v)
{      if(si==ei)
        
    {
        visited[si]=true;
        
        return true;
    }
    visited[si]=true;
    for(int i=0;i<v;i++)
    {
        if(i==si)
        {continue;
        }
        if(edge[si][i]==1 )
        { if(visited[i])
            continue;
            if(dfs(edge,visited,i,ei,v))
            { cout<<i<<" ";
                 return true;
            }
        
        }
    }
    return false;
    
}

int main()
{
  int v, e, tempX, tempY;
  cin >> v >> e;
    int **edge=new int*[v];
    for(int i=0;i<v;i++)
        edge[i]=new int[v];
   for(int i=0;i<v;i++)
   {
    for(int j=0;j<v;j++)
        edge[i][j]=0;
   }
 
     for(int j=0;j<e;j++)
     {
         int x,y;
         cin>>x>>y;
         edge[x][y]=1;
         edge[y][x]=1;
     }
     
 
    cin>>tempX>>tempY;
    
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    
    }
    if(dfs(edge,visited,tempX,tempY,v))
        cout<<tempX;
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */

  return 0;
}
