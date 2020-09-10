/*Write a program to generate the first 'n' terms of the following series 3, 8, 13, 24, 41, 70, 117, 194,....... . 
The input will be an integer number indicating value of 'n' .

Test case 1 :
Sample input : 6
Sample output : 3 8 13 24 41 70

Test case 2 :
Sample input : 2 
Sample output : 3 8

Test case 3 :
Sample input : 7
Sample output :  3 8 13 24 41 70 117*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ar[n];
	ar[0]=3;
	ar[1]=8;
	if(n==1) cout<<"3";
	else if(n==2) cout<<"3 8";
	else{
		cout<<ar[0]<<" ";
		cout<<ar[1]<<" ";
	for(int i=3;i<n;i++){
		ar[i]=ar[i-2]+ar[i-3]+(i-1);
		cout<<ar[i]<<" ";
	}}
}
