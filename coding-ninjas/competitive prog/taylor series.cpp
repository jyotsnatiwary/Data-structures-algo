#include<bits/stdc++.h>
using namespace std;

double taylor(int x, int n)
{
	int i;
	double s=1;
	double num=1;
	double den=1;
	for(i=1;i<n;i++){
		num*=x;
		den*=i;
		s+=num/den;
	}
	return s;
}
int main(){
	cout<<taylor(1,10);
	return 0;
	
}
