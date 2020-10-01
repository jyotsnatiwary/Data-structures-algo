/*Fredo is assigned a new task today. He is given an array A containing N integers. His task is to update all elements of array to some minimum value x , that is,  ;  such that sum of this new array is strictly greater than the sum of the initial array. Note that x should be as minimum as possible such that sum of the new array is greater than the sum of the initial array.

Input Format:
First line of input consists of an integer N denoting the number of elements in the array A.
Second line consists of N space separated integers denoting the array elements.

Output Format:
The only line of output consists of the value of x.

Input Constraints:


SAMPLE INPUT 
5
1 2 3 4 5
SAMPLE OUTPUT 
4
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
		s+=a[i];
	}
	cout<<(s/n)+1;
}
