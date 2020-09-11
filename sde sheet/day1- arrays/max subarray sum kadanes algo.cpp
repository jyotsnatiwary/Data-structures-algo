#include<bits/stdc++.h>
using namespace std;

int kadanes(int ar[],int n){
	int highestmax=0;
	int currentmax=0;
	for(int i=0;i<n;i++){
		currentmax=max(ar[i],currentmax+ar[i]);
		highestmax=max(highestmax,currentmax);
	}
	return highestmax;
}

int main() {
   int l;
   cin >> l;
   int arr[l];
   for (int i = 0; i < l; i++) {
      cin >> arr[i];
   }
   cout << "The Maximum Sum is: "<<kadanes(arr,l) << endl;
   return 0;
}
