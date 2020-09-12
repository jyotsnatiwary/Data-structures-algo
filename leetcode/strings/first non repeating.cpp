#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int i,j,c=0,n;
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(s[i]==s[i]){
				c++;
			}
		}
	}
	if(c>0)return c;
	else return -1;
}


