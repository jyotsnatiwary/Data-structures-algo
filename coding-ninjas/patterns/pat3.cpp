#include <iostream>
using namespace std;

int main() {
	int n,i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++) cout<<j;
		for(k=i*2;k<n*2;k++) cout<<" ";
		for(l=i;l>=1;l--) cout<<l;
		cout<<endl;
	}
}
