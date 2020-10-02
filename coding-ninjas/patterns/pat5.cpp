/*Write a program to print the following pattern.

sample input :  5
sample output :
                *
              *   *
            *       *
          *           *
        *               *
          *           *      
            *       *
              *   *
                *
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,n;
	cin>>n;
	for(i=0;i<n;i++){
		for(k=i;k<n;k++){
			cout<<" ";
		}
		for(j=0;j<=(2*i-1);j++){
			if(j==0 or j==2*i-2) cout<<"*";
			else cout<<" ";
		}
		cout<<"\n";
	}
	for(i=n;i>0;i--){
		for(k=i;k<n;k++){
			cout<<" ";
		}
		for(j=0;j<=(2*i-1);j++){
			if(j==0 or j==2*i-2) cout<<"*";
			else cout<<" ";
		}
		cout<<"\n";
	}
}