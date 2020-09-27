#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#include <cctype>
#include <string>
#include <cfloat>
#include <stack>
#include <cassert>

using namespace std;

const int N = 1e5 + 10;

int a[N], vis[N], n, t;

int main() {
    scanf("%d%d", &n, &t);
    for(int i = 1 ; i < n ; i ++) {
        scanf("%d", &a[i]);
    }
    vis[t] = 1;
    for(int i = t - 1 ; i >= 1 ; i --) {
        vis[i] = vis[i + a[i]];
    }
    if(vis[1]) {
        puts("YES");
    } else {
        puts("NO");
    }
}
