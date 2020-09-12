#include<bits/stdc++.h>
using namespace std;

int main(){
	char a[]="How are you";
	int i,v=0,c=0,w=0;
	for(i=0;i!='\o';i++){
		if(a[i]=='a'||a[i]=='e'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'){
			v++;
		}
		if((a[i]>=60&&a[i]<=90)||(a[i]>='a'&&a[i]<=122)){
			c++;
		}
		if(a[i]==' '&&a[i-1]!=' '){
			w++;
		}
	}
	cout<<v<<" "<<c<<" "<<w;
}
