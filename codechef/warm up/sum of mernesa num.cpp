
#include<bits/stdc++.h>
using namespace std;
bool check(int n){
	for(int i=1;i<=n;i++){
		if(n==pow(2,i)-1) return true;
	}
	return false;
}
int sum(int ar[], int n){
	int s=0;
	for(int i=0;i<n;i++) {
		if (ar[i] > 0 && check(ar[i])) s+=ar[i];
	}
	return s;
}
int main(){
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++) cin>>ar[i];
	cout<<sum(ar,n);
}
