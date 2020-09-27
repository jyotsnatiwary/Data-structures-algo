#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, a[n], sum=0;
    cin>>n;
    // if(n>=1&&n<=100000&&n%2==0)
    // cout<<n<<endl;
    // cout<<"hre"<<endl;
          for(i=0;i<n;i++)
            {
                cin>>a[i];
            }
    // cout<<i<<endl;
  for(int i=0;i<n/2;i++)
  {   
      sum= a[i]+a[n-1-i];
      cout<<sum/10<<" "<<sum%10<<endl;
  }
    
	return 0;
}
