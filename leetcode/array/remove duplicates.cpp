#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(),nums.end()) - nums.begin();
    }
};
/*
int main(){
	int n,i;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n;i++){
		if(arr[i]==arr[i+1]){
			break;
		}
	}
	while(i<n){
		for(int j=i;j<n;j++){
			n--;
			arr[i]=arr[i+1];
		}
	}	
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" "<<endl;
	}
}
*/
