
#include<bits/stdc++.h>
using namespace std;

void pattern(string str, int n){
	for(int i=0;i<n;i++){
		int j=n-1-i;
		for(int k=0;k<n;k++){
			if(k==i || k==j) cout<<str[k];
			else cout<<" ";
		}
		cout<<endl;
	}
}
int main(){
	string str;
	cin>>str;
	int n=str.size();;
	pattern(str, n);
}
