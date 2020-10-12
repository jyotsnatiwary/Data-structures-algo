//max diff between 2 items


#include<bits/stdc++.h>
using namespace std;

int max(int a[], int n){
	int min=a[0];
	int max=a[0];
	for(int i=0;i<n;i++){
		min=min(min,a[i]);
		max=max(max,a[i]);
	}
	return max-min;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<max(a,n);
}
