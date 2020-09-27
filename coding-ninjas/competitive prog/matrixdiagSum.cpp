#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[n][n],i,j,d1=0,d2=0,s=0, sum=0,t=0,sum1=0;
    cin>>n;
    if(n>=1&&n<=100)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
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
    cout<<sum1;
    
	return 0;
}

