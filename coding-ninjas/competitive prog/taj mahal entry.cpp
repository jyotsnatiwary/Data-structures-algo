see we are given windows n 1 person at a time.  
switch in 1 min. and revolve.  at any window we will 
come at i or i+n.


if i+t*n>=a[i] this window we can enter

main()
{
	int n;
	cin>>n;
	long* arr=new long[n+1];
	long* ans=new long[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		arr[i]-=i-1;
		if(arr[i]<0) arr[i]=0;
		long te=arr[i]/n;
		if(arr[i]%n!=0) te+=1;
		ans[i]=(n*te)+i;
	}
	long an=INT_MAX,rv=-1;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]<an)
		{
			an=ans[i];
			rv=i;
		}
	}
	cout<<ev<<endl;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c,min,ans,i;
    cin>>n;
    int arr[n],cycle[n];    
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]-i<0)
        {
            cycle[i]=0;
        }
        else
        {
      c=(arr[i]-i)/n;
        if((arr[i]-i)%n!=0)
        {
            c=c+1;
        }
        cycle[i]=c;
        }
    }
    min=cycle[0];
    ans=1;
    for(i=1;i<n;i++)
    {
        if(min>cycle[i])
        {
            min=cycle[i];
            ans=i+1;
        }
    }
    cout<<ans;
	return 0;
}
