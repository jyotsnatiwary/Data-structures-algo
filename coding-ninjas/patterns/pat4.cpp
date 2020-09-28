/*Write a program to print the following pattern.

sample input :  5
sample output :
                 *
              * * *
            * * * * *
          * * * * * * *
        * * * * * * * * *
          * * * * * * *      
            * * * * *
               * * *
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
		for(j=1;j<=(2*i-1);j++){
			cout<<"*";
		}
		cout<<"\n";
	}
	for(i=n;i>0;i--){
		for(k=i;k<n;k++){
			cout<<" ";
		}
		for(j=1;j<=(2*i-1);j++){
			cout<<"*";
		}
		cout<<"\n";
	}
}
 
