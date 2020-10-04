#include<bits/stdc++.h>
using namespace std;

int kadane(int *arr[],int n){
	int curr_sum=0,best_sum=0;
	for(int i=0;i<n;i++){
		curr_sum+=arr[i];
		if(best_sum<curr_sum){
			best_sum=curr_sum;
		}
		if(curr_sum<0){
			curr_sum=0;
		}
	}
	return best_sum;
}

