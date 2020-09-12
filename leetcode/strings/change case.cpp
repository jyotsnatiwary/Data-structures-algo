#include<bits/stdc++.h>
using namespace std;

int main(){
	char a[]="W5lCOME";
	for(int i=0;i!='\o';i++){
		if(a[i]>='a' && a[i]<=122){
			a[i]-=32;
		}
		else if(a[i]>=65 && a[i]<=90){
			a[i]+=32;
		}
	}
	cout<<a;
}
