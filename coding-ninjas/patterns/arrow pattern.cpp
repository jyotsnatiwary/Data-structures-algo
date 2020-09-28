#include <iostream>
using namespace std;
int main() {
	int n,i,j,k;
	cin>>n;
	int n1=n/2+1, n2=n/2;
	for(i=1;i<=n1;i++){
		for(k=1;k<i;k++) cout<<" ";
		for(j=1;j<=i;j++) cout<<"* ";
		cout<<endl;
	}
	for(i=1;i<=n2;i++){
		for(k=0;k<n2-i;k++) cout<<" ";
		for(j=0;j<=n2-i;j++) cout<<"* ";
		cout<<endl;
	}
}
