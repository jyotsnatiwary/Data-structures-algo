#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int a,b,c,i, j, x,t;
    cin>>t;
    while(t--){
    cin>>a>>b>>c;    
            if (a >= b && a>=c) {
            	cout<<a<<endl;
			}
			else if(b>=a && b>=c){
				cout<<b<<endl;
			}
			else if(c>=a && c>=b){
				cout<<c<<endl;
			}
			
    }
}
