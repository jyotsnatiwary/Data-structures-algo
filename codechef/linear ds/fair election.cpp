//Py
# cook your dish here
for t in range(int(input())):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    
    i=0
    x=True
    while sum(a)<=sum(b):
        a.sort()
        b.sort()
        if a[0]<b[-1]:
            temp=b[-1]
            b[-1]=a[0]
            a[0]=temp
            i+=1
        else:
            x=False
            print(-1)
            break
    if x==True:
        print(i)
        
//1.
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int j=0,c=0;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[n],b[m];
		int sa=0,sb=0;
		for(int i=0;i<n;i++) {
			cin>>a[i];
			sa+=a[i];
		}
		for(int i=0;i<m;i++) {
			cin>>b[i];
			sb+=b[i];
		}
		if(sa>sb) cout<<0<<endl;
		else{
		sort(a,a+n);
		sort(b,b+m);
		reverse(b,b+m);
		
		for(int i=0;i<n;++i){
			if(j<m){
				sa=sa-a[i]+b[j];
				sb=sb-b[j]+a[i];
				swap(a[i],b[j]);
				c++;
				j++;
				if(sa>sb) break;
			}
		}
	}
	cout<<c<<endl;
}
}

//2.
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[n],b[m];
		int sa=0,sb=0;
		for(int i=0;i<n;i++) {
			cin>>a[i];
			sa+=a[i];
		}
		for(int i=0;i<m;i++) {
			cin>>b[i];
			sb+=b[i];
		}
		sort(a,a+n);
		sort(b,b+m);
		int count=0,x=0,temp=0,z,y,s1=0,s2=0;
		while(sa<sb&&x<n&&m>=0){
			temp=a[x];
			a[x]=b[m-1];
			b[m-1]=temp;
			x++;
			m--;
			count++;
			for(z=0;z<n;z++) {
				s1+=a[z];
				sa=s1;
			}
			for(y=0;y<m;y++) {
				s2+=b[y];
				sb=s2;
			}				
		}
		cout<<count<<endl;
	}
}


