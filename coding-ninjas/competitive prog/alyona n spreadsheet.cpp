#include <bits/stdc++.h>
using namespace std;
void construct(int**arr,int**dp ,int n,int m,int*output)
{
    for(int i=0;i<m;i++)
        dp[0][i]=0;
    output[0]=0;
    for(int i=1;i<n;i++)
    {
        int min=INT_MAX;
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]>=arr[i-1][j])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=i;
            if(dp[i][j]<min)
                min=dp[i][j];
        }
        output[i]=min;
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<output[i]<<" ";
    cout<<endl;
    cout<<endl;*/
}
int main()
{
    int n,m;
    cin>>n>>m;
    int**arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;*/
    int**dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[m];
        for(int j=0;j<m;j++)
            dp[i][j]=0;
    }
    int*output=new int[n];
    construct(arr,dp,n,m,output);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(output[y-1]<=x-1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    /*for(int i=0;i<n;i++)
    {
        delete[]arr[i];
        delete[]dp[i];
    }
    delete[]arr;
    delete[]dp;
    delete[]output;*/
    return 0;
}

