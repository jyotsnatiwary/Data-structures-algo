#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
vector<ll> submask[22];
bool visited[1<<22];
ll dp[1<<22];
ll n;
ll ans(ll mask) {
    if(mask==(1<<(n+1))-2)
        return 1;
    if(dp[mask]!=-1)
        return dp[mask];
    ll res = 0;
    for(ll i = 1; i<=n; i++) {
        if(!(mask&(1<<i))) {
            bool ok = true;
            for(ll j: submask[i])
                if(!(mask&(1<<j)))
                    ok = false;
            if(ok)
                res+=ans(mask|(1<<i));
        }
    }
    return dp[mask] = res;
}
int main() {
    cin>>n;
    for(ll i = 1; i<=20; i++) {
        for(ll j = i-1; j>=1; j--)
            if((i&j)==j) submask[i].pb(j);
    }
    memset(dp, -1, sizeof(dp));
    cout<<ans(0);
    // cout<<dp;
    return 0;
}



In this question, basically we are given any number n 

so we have to output the number of permutations such that 
if i&j==i, then in that permutation, i should come first, 
else it is not the permutation we want
so, for example, n = 4
so, numbers are 1 2 3 4
so, one such permutation can be, 4 1 2 3

now here, 4&3==4, so itis a correct permutation

also, 1&3==1 and 1 comes earlier than 3

so it is correct
we can use bitmasking

we can use a mask which tells which position has been assigned currently
so, for example, if 4th position is currently assigned(int the recursion), 
4th bit in the mask is one
now, as 4&3==4 so, 4th bit should of been 1 before the 3rd bit becomes one
so, only that permutation is valid
so, before applying the recursion, we can store an array of vectors, 
basically like an adjacency list

That list stores from 1 o n, for every i, if i&j==j, that maps i to j
somewhat like:
for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=1;j--)
            {
                if((i&j)==j)
                	adj[i].push_back(j);
            }
        }


this stores every i and corresponding numbers to i where j<i and i&j==j
now, you can simply use recursion and bitmasking

the base case would be when all elements are assigned, or mask is like 1111111
return 1 for that case


then go for every i
and first see if it is set or not, like:
if(!(mask&(1<<i))){

then use the adjacency list to see if that any j is assigned previuosly which is linked to i

if any such j is there already set, then we cannot onsider that case so 
continue the loop
else, just follow the normal procedure, like ans = ans + solve(mask|(1<<i), n)
