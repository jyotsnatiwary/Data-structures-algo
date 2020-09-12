/*Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,c=0,s=0,num,a;
	cin>>n;
	int arr[n],arr2[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		arr2[i]=arr[i]*arr[i];
	}
	sort(arr2,arr2+n);
	for(int i=0;i<n;i++){
	cout<<arr2[i]<<" ";
	}
}

