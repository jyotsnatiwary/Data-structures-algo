#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;
 
#define vi vector<int>
#define vs vector<string>
#define vpii vector<pii>
#define all(v) v.begin(), v.end()
 
#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)
 
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)
#define forup(i,a,b) for(int i=(a); i<(b); ++i)
#define fordn(i,a,b) for(int i=(a); i>(b); --i)
#define rep(i,a) for(int i=0; i<(a); ++i)
 
#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf(" %s",x)
 
#define F first
#define S second
 
#define pb push_back
#define pf push_front
#define mp make_pair
 
const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();
 
struct Worker {
	int T, x, y;
	Worker() {}
	Worker(int _T, int _x, int _y) {
		T = _T; x = _x; y = _y;
	}
};
 
vector<Worker> input;
 
bool way(Worker a, Worker b) {
	if (a.T == b.T) {
		if (a.y == b.y) {
			return a.x < b.x;
		}
		return a.y > b.y;
	}
	return a.T < b.T;
}
 
int main() {
	// fr;
	// fw;
	int n, x, y, T;
	LL d;
	gi(n);
	cin >> d;
	rep(i, n) {
		gi(T); gi(x); gi(y);
		input.pb(Worker(T, x, y));
	}
	sort(all(input), way);
	LL area = 0;
	LL bestSpeed = 0, Cost = 0, lastTime = input[0].T;
	rep(i, n) {
		LL additional = bestSpeed * 1LL * (input[i].T - lastTime);
		area += additional;
 
		if (area >= d) {
			break;
		}
 
		if (input[i].y > bestSpeed) {
			bestSpeed = input[i].y;
			Cost += input[i].x;
		}
 
		lastTime = input[i].T;
	}
	cout << Cost;
	return 0;
}
 
