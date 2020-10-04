
int maxSubarray(int arr[], int n)
{
	int maxEnding=1, minEnding=1,maximum=0;
	for(int i=0;i<n;i++){
		if(arr[i]>0){
			maxEnding*=arr[i];
			minEnding=min(minEnding*arr[i],1);
			
		}
		else if(arr[i]==0){
			maxEnding=1, minEnding=0;
		}
		else{
			int temp=maxEnding;
			maxEnding=max(minEnding*arr[i],1;
			minEnding=maxEnding*arr[i];
			
		}
		maximum=max(max,maxEnding);
	}
	return maximum;
}
