/*#include<bits/stdc++.h>
using namespace std;

int ps(int n, int ar[]){
	int s=0;
	for(int i=1;i<=n;i++) s+=ar[i];
	return s;
}
int ss(int n,int ar[]){
	int s=0;
	for(int i=n;i>=0;i--) s+=ar[i];
	return s;
}

int main(){
	int t;cin>>t;
	while(t--){
		int n,ans=0; cin>>n;
		int ar[n];
		for(int i=0;i<n;i++) cin>>ar[i];
		int i=0;
		for(i=0;i<n;i++){
			ans=min(ans, ps(i,ar)+ss(i,ar));
			
		}
		cout<<i+1<<endl;
	}
}*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<long long>
#define vi vector<int>
#define vb vector<bool>
#define pql priority_queue<long long>
#define pqp priority_queue<pair<ll,ll> >

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,i,j,k;
        cin>>n;
        ll a[n],ps[n],ss[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        ps[0] = a[0];
        ss[n-1] = a[n-1];
        for(i=1;i<n;i++){
            ps[i] = ps[i-1]+a[i];
            ss[n-i-1] = a[n-i-1]+ss[n-i];
        }
        ll ans = ps[0]+ss[0];
        ll ansi = 0;
        for(i=0;i<n;i++){
            if(ans > ps[i]+ss[i]){
                ans = ps[i]+ss[i];
                ansi = i;
            }
        }
        cout<<ansi+1<<"\n";
    }
    return 0;
}
