#include<bits/stdc++.h>
using namespace std;
int max(int a, int b, int c, int d){
	int max=a;
	if(b>max){
		max= b;
	}
	if(c>max){
		max= c;
	}
	if(d>max){
		max =d;
	}
	return max;
//	if(a>b&&a>c&&a>d){
//		return a;
//	}
//	if(b>a&&b>c&&b>d){
//		return b;
//	}
//	if(c>b&&a<c&&c>d){
//		return c;
//	}
//	if(d>b&&d>c&&a<d){
//		return d;
//	}
}
int main(){
	int a,b,c,d, ans;
	cin>>a>>b>>c>>d;
	ans=max(a,b,c,d);
	cout<<ans;
}
