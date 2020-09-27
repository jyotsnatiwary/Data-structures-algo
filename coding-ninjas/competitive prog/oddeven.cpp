#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a[n],s1=0,s2=0;
    cin>>n;
    
    if (n>=1&&n<=100000)
    {
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }
    
    for(i=0;i<n;i++)
    {
        if(a[i]>=1&&a[i]<=1000000)
        {
            if(i%2==0&&a[i]%2==0)
            {
                s1=s1+a[i];
            }
            if(i%2!=0&&a[i]!=0)
            {
                s2=s2+a[i];
            }
        }
    }
    cout<<s1<<" ";
    cout<<s2;
	return 0;
}
