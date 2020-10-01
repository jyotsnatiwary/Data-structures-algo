#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
int sum = 1;
for (int i=2; i*i<=n; i++)
{
if (n%i==0)
{
if(i*i!=n)
sum = sum + i + n/i;
else
sum=sum+i;
}
}
if (sum == n && n != 1)
cout<<"YES"<<endl;

else cout<<"NO"<<endl;
}
}

