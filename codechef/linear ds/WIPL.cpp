/*Get excited, folks, because it is time for the final match of Codechef Premier League (CPL)!

Mike and Tracy also want to watch the grand finale, but unfortunately, they could not get tickets to the match. However, Mike is not someone who gives up so easily — he has a plan to watch the match.

The field where the match is played is surrounded by a wall with height K. Outside, there are N boxes (numbered 1 through N). For each valid i, the i-th box has a height Hi.

Mike wants to take some boxes and stack them on top of each other to build two towers. The height of each tower is the sum of heights of all the boxes that form it. Of course, no box may be in both towers. The height of each tower should be at least K. Then Mike can climb on top of one tower and Tracy on top of the other, and they can watch the match uninterrupted!

While Mike is busy stacking the boxes, Tracy would like to know the smallest number of boxes required to build two towers such that each of them has height at least K, or at least that it is impossible to build such towers. Can you help Tracy?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers H1,H2,…,HN.
Output
For each test case, print a single line containing one integer — the smallest number of boxes required to build two towers, or -1 if it is impossible.

Constraints
1=T=5
1=N,K=4,000
1=Hi=105 for each valid i
Subtasks
Subtask #1 (30 points):

1=N,K=100
1=Hi=100 for each valid i
Subtask #2 (70 points): original constraints

Example Input
2
8 38
7 8 19 7 8 7 10 20
4 5
2 10 4 9
Example Output
7
2
Explanation
Example case 1: The first tower can be built with boxes 8+10+20=38 and the second tower with boxes 7+7+8+19=41. In this case, the box with height 7 is left unused.

Example case 2: We only need the box with height 10 for one tower and the box with height 9 for the other tower.*/


//java correct ans
/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner scan=new Scanner(System.in);
		int t=scan.nextInt();
		while(t--!=0){
		    int n=scan.nextInt();
		    int k=scan.nextInt();
		    int h[]=new int[n];
		    LinkedHashSet<Integer> h1=new LinkedHashSet<Integer>();
		    
		    int sum=0;
		    for(int i=0;i<n;i++){
		        h[i]=scan.nextInt();
		    }
		    Arrays.sort(h);
		    h1.add(h[n-1]);
		    sum=h[n-1];
		    int z=-1;
		    for(int i=n-2;i>=0;i--){
		        LinkedHashSet<Integer> h2=new LinkedHashSet<Integer>();
		        sum=sum+h[i];
		        Iterator i1=h1.iterator();
		        while(i1.hasNext()){
		            int p=(int)(i1.next());
		            h2.add(p);
		            h2.add(h[i]);
		            h2.add(p+h[i]);
		            if(((p+h[i])>=k)&& ((sum-p-h[i])>=k)){
		                z=n-i;
		                break;
		            }
		            if(((h[i])>=k)&&((sum-h[i])>=k)){
		                z=n-i;
		                break;
		            }
		        }
		        if(z!=-1){
		            break;
		        }
		        h1=h2;
		    }
		    System.out.println(z);
		}
	}
}




#include <bits/stdc++.h>
#define vpp vector<pp>
#define vll vector<ll>
#define endl "\n"
#define vbb vector<bool>
#define w(t) while(t--)
#define PP pair<ll,ll>
#define test(x) ll t;cin>>t; w(t) x()
#define __lb lower_bound
#define __ub upper_bound
#define szs(x) x.length()
#define szv(x) x.size()
#define ll long long int
#define takeINP(arr,n) for(long long int i=0;i<n;i++) cin>>arr[i];
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define rsz(x,n) x.resize(n)
#define rsr(x,n) x.reserve(n)
#define  mp(a,b) make_pair(a,b)
#define float long long double
#define pb push back
#define print(arr,s,e) f(i,s,e) cout<<arr[i]<<" "; cout<<endl;
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define vll vector<ll>
#define triple pair<ll,pair<ll,ll>
#define MTTR(a,b) map<a,b>::reverse_iterator


using namespace std;
using namespace chrono;

ll dp[4020][4020];
ll pref[4020];

ll Dfn(ll idx,ll taken, ll n, ll k, vll &arr){
    if(taken>=k and (pref[idx]-taken>=k)) return 0;
    
    
    else if(idx>=n) return 1e10;
    else if(dp[idx][taken]!=-1) return dp[idx][taken];
    
    
    ll c1=Dfn(idx+1,min(taken+arr[idx], pref[idx]-taken),n,k,arr);
    ll c2=Dfn(idx+1,min(pref[idx]-taken+arr[idx],taken),n,k,arr);
    
    return dp[idx][taken]=1+min(c1,c2);
}

ll givemedp(vll &arr,ll n,ll k){
    f(i,0,n/2) swap(arr[i],arr[n-i-1]);
    cf(i,0,n+10){
        pref[i]=0;
        cf(j,0,k+10) dp[i][j]=-1;
    }
    cf(i,1,n) pref[i]=pref[i+1]+arr[i-1];
    ll(ans)=Dfn(0,0,n,k,arr);
    return ans>1e9?-1:ans;
}

void solve(){
    ll n,k; cin>>n>>k;
    vll arr(n,0);
    takeINP(arr,n);
    sort(all(arr));
    if(n==1){
        cout<<"-1"<<endl;
        return;
    }
    cout<<givemedp(arr,n,k)<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	//ios_base::sync_with_studio(false);
	cin.tie(NULL);
	auto start1=high_resolution_clock::now();
	
	test(solve);
	auto stop1 = high_resolution_clock::now();
	auto duration= duration_cast<microseconds>(stop1-start1);
	#ifndef ONLINE_JUDGE
	cerr<<"Time: "<<duration.count()/1000.0<<endl;
	cout<<duration.count()/1000.0<<endl;
	#endif
}

