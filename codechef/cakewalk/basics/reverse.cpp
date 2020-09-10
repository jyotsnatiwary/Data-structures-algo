#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,d,n;
	cin>>t;
	while(t--){
		d=0;
		cin>>n;
		while(n){
			d=d*10+(n%10);
			n/=10;
						
		}
		cout<<d;
	}
}
