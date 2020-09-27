#include <bits/stdc++.h>
using namespace std;
#define N 100000
#define pb push_back
typedef pair<int,int> pii;
inline int read(){
    int n= 0;
    char c;
    while((c=getchar_unlocked())<48);
    n += (c-'0');
    while((c=getchar_unlocked())>=48){
        n=n*10+(c-'0');
    }
    return n;
}
int find(int parent[],int d[], int x){
    if(parent[x]<0){
        return x;
    }
    int root = find(parent,d,parent[x]);
    d[x] = d[x]^d[parent[x]];
    parent[x] = root;
    return root;
}
bool unionE(int parent[],int d[], int u, int v, int x){
    int root1 = find(parent,d,u);
    int root2 = find(parent,d,v);
    if(root1 == root2){
        
        if(d[u]^d[v]!=x){
            return false;
        }
        return true;
    }else{
        
        if(parent[root1] == parent[root2]){
            parent[root1]--;
        }
        if(parent[root1]<parent[root2]){
            parent[root2] = root1;
            d[root2] = d[u]^d[v]^x;
        }else{
            
            parent[root1] = root2;
            d[root1] = d[u]^d[v]^x;
        }
        
    }
    return true;
}
int main() {
	int t = read();
	int n,q,u,v,x;
	while(t--){
	 n = read();
	 q = read();
	 int parent[n+1];
	 int d[n+1];
	 for(int i=1;i<=n;i++){
	     parent[i] = -1;
	     d[i] = 0;
	 }
	 bool possible = true;
	 for(int i=0;i<q;i++){
	     u = read();
	     v = read();
	     x = read();
	     if(possible){
	         possible = unionE(parent,d,u,v,x);
	     }
	 }
	 if(!possible){
	     cout<<"no\n";
	 }else{
	     cout<<"yes\n";
	 }
	}
	return 0;
}



The problem statement states that: A matrix B (consisting of integers) 
of dimension N × N is said to be good if there exists an array A (consisting of integers) 
such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value 
of integer x.

Consider one of the m queries to be: 1 2 1
What your code does is initialize node 1 with 1 and node 2 with “value of node 1 + 1”.
So, val[1] contains 1 and val[2] contains 2. 

but If you assign val[1] with 1, then val[2] can be both 2 as well as 0 ( the problem statement clearly mentions integers).
If val[2] = 0, then |val[1] - val[2]| = 1.
If val[2] = 2, then |val[1] - val[2]| = 1.

You filled a single slot in the value array(val[]) in just one way 
while there were two possible ways to fill a single slot in val[]. 
This mistake compounded as the number of queries increased.

How to get AC then??
You fill val[] the same as you are doing now. But instead of,
 if(abs(val[x]-val[v[x][y].first])!=v[x][y].second) 
do this,
 if(abs((val[x]-val[v[x][y].first])-v[x][y].second) % 2 != 0) 
Since, we can fill a single slot in two ways (but we are just doing 
it in one way), the difference should be either 0(this case arises if 
the test case was for a matrix which was filled as the way we are 
doing i.e. adding 1) or a multiple of 2 (this case arises if the 
test case was for matrix which has some of its cells filled in the 
other way i.e. subtracting 1).
