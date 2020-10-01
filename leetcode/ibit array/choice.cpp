/*Write a program that asks the user for a number N and a choice C. And then give them the possibility to choose between computing the sum and computing the product of all integers in the range 1 to N (both inclusive).
If C is equal to -
 1, then print the sum
 2, then print the product
 Any other number, then print '-1' (without the quotes)
Input format :
Line 1 : Integer N
Line 2 : Choice C
Output Format :
 Sum or product according to user's choice
Constraints :
1 <= N <= 12
Sample Input 1 :
10
1
Sample Output 1 :
55
Sample Input 2 :
10
2
Sample Output 2 :
3628800*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int ar[n];
	int c,sum=0,pro=1;
	cin>>c;
	if(c==1){
		for(int i=0;i<=n;i++){
			sum=sum+i;
		}
		cout<<sum;
	}
	else if(c==2){
		for(int i=0;i<=n;i++){
			pro=pro*i;
		}
		cout<<pro;
	}
	else cout<<"-1";
}

