#include <iostream>
#define mod 1000000007
using namespace std;
void sieve(int ar[],int a[])
{
   // int k=0;
    //for(int j=0;j<n;j++)
    for(int i=0;i<900000;i++)
    {
        if(ar[i]==1)
        {
    for(int j=2*i;j<900000;j=j+i)
    {
        if(ar[j]==1)
        {
        a[j]=(a[j]+a[i])%mod;
        }
    }
        }
    }


}
int main()
{
int *ar=new int[900000];
int *a=new int[900000];
int t;
cin>>t;
for(int i=0;i<900000;i++)
{
    ar[i]=0;
    a[i]=0;
}
while(t--)
{
    int n,b,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {

        cin>>b;
        ar[b]=1;
        a[b]=1;
    }
    sieve(ar,a);
    for(int i=0;i<900000;i++)
{
   // cout<<sum<<" + ";
     sum =(sum+a[i])%mod;

     ar[i]=0;
    a[i]=0;
}
cout<<sum%1000000007<<endl;
}
    return 0;
}
