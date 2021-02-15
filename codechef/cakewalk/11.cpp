#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    //string s;cin>>s;
	    //stringstream iss(s); 
	    //while (iss >> s) {    }
	    char s[n*10];
	    for(int i=0;i<n;i++){
	        cin>>s[i];
	    }
	    int size = sizeof(s) / sizeof(s[0]);
	    for(int i=0;i<size;i++){
	    	cout<<s[i]<<endl;
	   }
	}
	return 0;
}

