/*Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,i,j,k;
	cin>>n>>m;
	int p=m+n;
	int ar1[n],ar2[m],ar3[p];
	for(int i=0;i<n;i++){
		cin>>ar1[i];
	}
	for(int i=0;i<m;i++){
		cin>>ar2[i];
	}
	while(i<n&&j<m){
		if(ar1[i]<=ar2[j]){
			ar3[k++]=ar1[i++];
		}
		else ar3[k++]=ar2[j++];
	}
	for(;i<n;i++)ar3[k++]=ar1[i];
	for(;j<m;j++)ar3[k++]=ar1[j];
	for(int i=0;i<p;i++){
		cout<<ar3[i]<<" "<<endl;
	}
}



