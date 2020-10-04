#include<bits/stdc++.h>
using namespace std;

char nonRepeating(string str){
	map<string,int> freq;
	for(int i=0;i<str.length();i++){
		char currChar=str[i];
		freq[currChar++];
	}
	for(int i=0;i<str.length();i++){
		if(freq[str[i]]==1){
			return str[i];
		}
	}
	return str[0];
}
