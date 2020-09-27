#include<bits/stdc++.h>
using namespace std;

int main() {
    int b;
    double s;
    char g;
    cin>>b>>g;
    if(g=='A'){
        s=b+(0.2*b)+(0.5*b)+1700-(0.11*b);
        cout<<round(s);
    }
    else if(g=='B'){
        s=b+(0.2*b)+(0.5*b)+1500-(0.11*b);
        cout<<round(s);
    }
    else{
        s=b+(0.2*b)+(0.5*b)+1300-(0.11*b);
        cout<<round(s);
    }
	// Write your code here
	
}

