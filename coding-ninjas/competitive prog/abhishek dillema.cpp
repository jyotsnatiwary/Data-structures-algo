/*Ashutosh touches 2nd bit from the start of both the  binary string. 
     in first touch (to string 1) he sees that the value is1.
     in second touch (to string 2)he sees that the value is 0.
     so he concludes both strings are different in 2 touch.*/
     
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1000000000000

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;

ll dp[1050][105];
string arr[15];
ll n;
ll cnt[1050];
ll get(ll mask, ll i)
{
    if(dp[mask][i]!=-1)
        return dp[mask][i];
    if(mask == 0)
        return dp[mask][i] = 0;
    
    if(i == arr[0].length())
    {
        if(cnt[mask] == 1)
            return dp[mask][i] = 0;
        else return dp[mask][i] = inf;    
    }
    
    if(cnt[mask] == 1)
        return dp[mask][i] = 0;
    
    
    ll ans = inf;
    ll temp = 0;
    //ll smask = (1ll<<i);
    for(ll j=0;j<n;j++)
    {
        if((mask&(1ll<<j)) == 0)
            continue;
        if(arr[j][i] == '1')
            temp+=(1ll<<j);
    }
    
    ll temp1 = mask - temp;
    if(temp1 == 0 || temp == 0)
        return dp[mask][i] = inf;
   // cout<<"for mask = "<<mask<<" and "<<i+1<<" = "<<temp<<" "<<temp1<<"\n";
    dp[mask][i] = min(ans, get(temp,i+1)+get(temp1,i+1)+cnt[mask]);
    //cout<<"for "<<mask<<" and "<<i+1<<" = "<<dp[mask][i]<<"\n";
    return dp[mask][i];
}

int main()
{
   FAST/**/
   
   //ll n;
   cin>>n;
   
   //string arr[n];
   for(ll i=0;i<n;i++)
        cin>>arr[i];
   
   for(ll i=0;i<1050;i++)
        for(ll j=0;j<105;j++)
            dp[i][j] = -1;
   
   ll ans = inf;
   for(ll i=0;i<1050;i++)
   {
       ll temp = 0;
       ll temp1 = i;
       while(temp1>0)
       {
           if(temp1&1)
                temp++;
           temp1>>=1;
       }
       cnt[i] = temp;
   }
   
   ll lim = (1<<n) - 1;
  // cout<<lim<<"\n";
       for(ll j=0;j<arr[0].length();j++)
            ans = min(ans, get(lim,j));
   
   
   cout<<ans;
   
   return 0;        
}  
   
