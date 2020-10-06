Murder
Send Feedback
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).

#include<bits/stdc++.h>  
#define pb push_back
using namespace std;
long long int merge(int* a,int start,int mid,int last)
{
	int i=start,k=0,j=mid;
	long int ans=0;
	long int partialSum=0;
	int* temp=new int[last-start+1];
	bool flag=0;
	while(i<mid && j<=last)
	{
		if(a[j]>a[i])
		{   
            ans=ans+a[i]*(last-j+1);
            temp[k++]=a[i++];
		}else{
			temp[k++]=a[j++];
		}
	}
	while(i<mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=last)
	{   
		temp[k++]=a[j++];
	}
	for(int i=start,k=0;i<=last;k++,i++)
	{
		a[i]=temp[k];
	}
	return ans;
}
long long int merge_sort(int* a,int left,int right)
{
	long int totSum=0;
	if(left<right)
	{
		int mid=(left+right)/2;
		long int leftSum=merge_sort(a,left,mid);
		long int rightSum=merge_sort( a,mid+1,right);
		long int mergeSum=merge(a,left,mid+1,right);
		totSum=leftSum+rightSum+mergeSum;
	}
	return totSum;
}
int main(){
	int T;cin>>T;
	while(T--)
	{
 			int n;cin>>n;
 			int* a=new int[n];
 			for(int i=0;i<n;i++)cin>>a[i];
			cout<<merge_sort(a,0,n-1)<<endl;
	}
    return 0;
}
