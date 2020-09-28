/*Write a program to print the following pattern.
sample input :  5
sample output :
     * * * * *
     * * * *
     * * *
     * *
     *
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,j,n;
	cin>>n;
	for(i=n;i>0;i--){
		for(j=i;j>0;j--){
			cout<<"*";
		}
		cout<<"\n";
	}
}

