#include<bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)

vector<pair<char,int> > v; 
unordered_map<int,int> m;
vector<int> bit(200001,0);
vector<int> a; 

void insert(int val,int x,int n){
	if(x>n)
	return ;

	bit[x]+=val;
	insert(val,x+ (x&(-x)),n);
}

int query(int x)      //returns the sum of first x elements in given array a[]
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += bit[x];
     return sum;
}

int search(int val){
	int i,j,k,x,y,z,ans=a.size();

	x=0,y=a.size()-1;
	while(x<=y){
        
		z=(x+y)/2;
    
		if(query(m[a[z]])>=val){
			ans=z;
			y=z-1;
		}else{
			x=z+1;
		}
	}

	return ans;
}

int main(){
	int i,j,k,x,y,z,n;
	scanf("%d",&n);

	v.clear();
	a.clear();
	m.clear();

	char c;
	for(i=0;i<n;i++){
		cin>>c;
        scanf("%d",&j);
		v.pb(mk(c,j));
		m[j]=1;
	}
    
	for(auto u:m){
		a.push_back(u.first);
	}
    
    sort(a.begin(),a.end());
    
    for(i=0;i<a.size();i++){
           m[a[i]]=1+i;
    }

	for(i=0;i<n;i++){
		if(v[i].first=='I'){
            if(query(m[v[i].second])==query(m[v[i].second]-1)){
                insert(1,m[v[i].second],a.size());
            }
		}else if(v[i].first=='D'){
			if(query(m[v[i].second])!=query(m[v[i].second]-1)){
				insert(-1,m[v[i].second],a.size());
			}
		}else if(v[i].first=='K'){
			j=search(v[i].second);
			if(j==a.size()){
				printf("invalid\n");
			}else{
				printf("%d\n",a[j]);
			}
		}else{
			j=lower_bound(a.begin(),a.end(),v[i].second)-a.begin();
			j--;

			if(j<0){
				printf("0\n");
			}else{
				printf("%d\n",query(m[a[j]]));
			}
		}
	}
}


So the problem is about designing a data structure which can:

Add an element x in the set if x is not in present
Delete an element x if present in set
Find the Kth Smallest number in the set
Find number of elements in set lesser than x

ham phle yeh saari queries store kr lega 
pair of char and int banake
ek set banaega or yeh saari queries pe iterate krega 
or jiska b char i tha iusko set mah daal dega


8
I -1
I -1
I 2
C 0
K 2
D -1
K 1
K 2


yeh wala hi le lo


to set mah {-1,2} hoga
