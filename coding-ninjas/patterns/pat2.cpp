#include <iostream>
using namespace std;

int main() {
	int n,i,j,k,l,num=1;
	cin>>n;
	for(i=1;i<=n;i++){
		num=i;
		for(k=n-1;k>=i;k--) cout<<" ";
		for(j=1;j<=i;j++) {
			cout<<num;
			num++;
		}
		num=num-2;
		cout<<endl;
	}
}
