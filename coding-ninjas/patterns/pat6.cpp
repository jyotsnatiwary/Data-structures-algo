#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,j,k,n;
	cin>>n;
	for(i=0;i<n;i++){
		for(k=n;k>i;k--){
			cout<<" ";
		}
		for(j=1;j<=i+1;j++){
			cout<<" * ";
		}
		cout<<"\n";
	}
}
