#include <bits/stdc++.h>
using namespace std;

void plusMinus(int arr[],int n) {
int i;
long double c1=0,c2=0,c3=0;
for(i=0;i<n;i++)
{
    if(arr[i]>0){c1++;}
    else if(arr[i]<0){c2++;}
    else if(arr[i]==0){c3++;}
}
long double f=c1/n;
long double g=c2/n;
long double h=c3/n;

cout << fixed << setprecision(6) << f <<endl;
cout << fixed << setprecision(6) << g <<endl;
cout << fixed << setprecision(6) << h <<endl;

//cout<<f<<endl;
//cout<<c2/n<<endl;
//cout<<c3/n<<endl;
}
int main(){
	int n,i,arr[n];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	plusMinus(arr,n);
	return 0;
}
