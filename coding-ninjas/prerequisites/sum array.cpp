/*Sum Array
Send Feedback
Given a 2-d square matrix of order ‘N’, find the sum of elements of both diagonals and all boundaries elements. Boundary elements refer to the elements present on all the four boundaries of matrix.
Input format:
First line will have a single integer ‘N' denoting the order of matrix.
Next ‘N’ lines will have ‘N’ space separated integers each denoting the elements of matrix.
Output format:
Print a single integer denoting the sum.
Constraints:
0 <= N <= 10^4
Sample input 1:
3
1 2 3
4 5 6
7 8 9
Sample Output 1:
45
Sample input 2:
5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
Sample Output 2:
273*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,d1=0,d2=0,s=0, sum=0,t=0,sum1=0;
    cin>>n;
    int a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    
    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                {
                    d1+=a[i][j];
                }
                if ((i + j) == (n - 1)) 
                {
                    d2+=a[i][j];
                }
                if(i==0||j==0||i==n-1||j==n-1)
                {
                	s=s+a[i][j];
				}
            }
    }
    sum=d1+d2+s;
    if(n%2!=0) 
    { 
        t=2*(a[0][0]+a[0][n-1]+a[n-1][0]+a[n-1][n-1]+a[n/2][n/2]);
    } 
    else
    { 
        t=2*(a[0][0]+a[0][n-1]+a[n-1][0]+a[n-1][n-1]+2*a[n/2][n/2]); 
    } 
    sum1= sum-t;
    cout<<sum1<<endl;
    
	return 0;
}



