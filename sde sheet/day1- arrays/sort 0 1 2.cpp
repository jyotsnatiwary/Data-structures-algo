#include<bits/stdc++.h>
using namespace std;

//counting sort-count num of 0,1,2 and insert in array
//time-o(2n)

//dutch national flag algo- low, mid, high pointer
int sort012(int *arr, int n){
	int mid=0, low=0, high=n-1;
	while(mid<=high){
		if(arr[mid]==0){
			swap(arr[low],arr[mid]);
			low++; mid++;
		}
		else if(arr[mid]==2){
			swap(arr[mid],arr[high]);
			high--;
		}
		else mid++;
	}
}
