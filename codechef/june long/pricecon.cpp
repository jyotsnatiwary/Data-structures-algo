/*Chef and Price Control
Chef has N items in his shop (numbered 1 through N); for each valid i, the price of the i-th item is Pi. Since Chef has very loyal customers, all N items are guaranteed to be sold regardless of their price.

However, the government introduced a price ceiling K, which means that for each item i such that Pi>K, its price should be reduced from Pi to K.

Chef's revenue is the sum of prices of all the items he sells. Find the amount of revenue which Chef loses because of this price ceiling.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers P1,P2,…,PN.
Output
For each test case, print a single line containing one integer ? the amount of lost revenue.

Constraints
1=T=100
1=N=10,000
1=Pi=1,000 for each valid i
1=K=1,000
Subtasks
Subtask #1 (100 points): original constraints

Example Input
3
5 4
10 2 3 4 5
7 15
1 2 3 4 5 6 7
5 5
10 9 8 7 6
Example Output
7
0
15
Explanation
Test Case 1: The initial revenue is 10+2+3+4+5=24. Because of the price ceiling, P1 decreases from 10 to 4 and P5 decreases from 5 to 4. The revenue afterwards is 4+2+3+4+4=17 and the lost revenue is 24-17=7.

Test Case 2: The initial revenue is 1+2+3+4+5+6+7=28. For each valid i, Pi=15, so there are no changes, the revenue after introduction of the price ceiling is the same and there is zero lost revenue.

Test Case 3: The initial revenue is 10+9+8+7+6=40. Since Pi>5 for each valid i, the prices of all items decrease to 5. The revenue afterwards is 5·5=25 and the lost revenue is 40-25=15.
*/

#include <iostream>
using namespace std;
//
//int main() {
//	
//	int t,n,k,arr[n],i,s1=0,s2=0,j=1,p=1;
//	cin>>t;
//	while(j<=t){
//		cin>>n>>k;
//	    for(i=0;i<n;i++){cin>>arr[i];}
//		j++;
//	}
//		
//	while(p<=t){
//		for(i=0;i<n;i++){s1+=arr[i];}
//		for(i=0;i<n;i++){
//	    	if(arr[i]>k){arr[i]=k;}
//	    	s2+=arr[i];
//		}
//		cout<<s1-s2;
//		p++;
//	}	
//	return 0;
//}

int main()
{
    int t;
	cin>>t;
	int j=0;
	while(j<t){
	    int n,k,i,s=0;
	    cin>>n>>k;
	    int arr[n];
	    for(i=0;i<n;i++){cin>>arr[i];}
	    for(i=0;i<n;i++)
	    {
	        if(arr[i]>k)
	        {
	            s+=arr[i]-k;
	        }
	    }
	    cout<<s<<endl;
	    j+=1;
	}
	return 0;
}

