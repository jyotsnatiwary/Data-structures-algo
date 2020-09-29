/*Code : Maximise the sum
Send Feedback
Given 2 sorted arrays (in increasing order), find a path through the intersections that produces maximum sum and return the maximum sum.
That is, we can switch from one array to another array only at common elements.
If no intersection element is present, we need to take sum of all elements from the array with greater sum.
Input Format :
 Line 1 : An integer M i.e. size of first array
 Line 2 : M integers which are elements of first array, separated by spaces
 Line 3 : An integer N i.e. size of second array
 Line 4 : N integers which are elements of second array, separated by spaces
Output Format :
Maximum sum value
Constraints :
1 <= M, N <= 10^6
Sample Input :
6
1 5 10 15 20 25
5
2 4 5 9 15
Sample Output :
81
Explanation :
We start from array 2 and take sum till 5 (sum = 11). Then we'll switch to array at element 10 and take till 15. So sum = 36. Now, no elements left in array after 15, so we'll continue in array 1. Hence sum is 81*/

#include<bits/stdc++.h>
using namespace std;
long maxPathSum(int ar1[], int ar2[], int m, int n)
{
   
    long sum=0,s1=0,s2=0,i=0,j=0;
    while(i<m && j<n){
        
    		if(ar1[i]<ar2[j]){
    			s1+=ar1[i];
    			i++;
			}
         else if(ar1[i]>ar2[j])
                s2+=ar2[j++]; 
        else
        {
        sum+=s1>s2?s1:s2;
        s1=0;
        s2=0;
        while(i<m && j<n && ar1[i]==ar2[j])
        {
            sum+=ar1[i];
            i++;
            j++;
        }          
        }

						
    }		
	while(i<m){
		s1+=ar1[i];
		i++;
	}
    while(j<n){
		s2+=ar2[j];
		j++;
	}
    sum +=s1>s2?s1:s2;  
	return sum;
}

int main(){
	int m;
	cin>>m;
	int ar1[m];
	for(int i=0;i<m;i++) cin>>ar1[i];
	int n;
	cin>>n;
	int ar2[n];
	for(int i=0;i<n;i++) cin>>ar2[i];
	long ans=maxPathSum(m,n,ar1,ar2);
	cout<<ans;
}
