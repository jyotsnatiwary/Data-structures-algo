#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,i,a[n];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	a.remove(3);
	for(i=0;i<n-1;i++){
		a[i]=a[i+1];
	}
	for(i=0;i<n;i++){
		cout<<a[i];
	}
}
