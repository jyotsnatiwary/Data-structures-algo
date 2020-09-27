#include <bits/stdc++.h>
 
using namespace std;
 
#define read(x) x = 0; while (isdigit(c = getchar_unlocked())) x = (x<<3) + (x<<1) + (c&15)
#define write(x) u = 0; do o[u++] = x%10; while (x /= 10); do putchar_unlocked(o[--u] + 48); while (u); putchar_unlocked(32)
 
int main()
{
    register int c, u, o[7], n;
    read(n);
    vector<int> p(n+1, -1);
 
    for (int i = 2; i*i <= n; ++i)
    {
        if (p[i] != -1)
            continue;
 
        for (int j = i*i; j <= n; j += i)
            p[j] = i;
    }
 
    vector<vector<int>> a;
    vector<int> q(n+1, -1);
    int s = 0;
    for (int i = n; i > 1; --i)
    {
        if (q[i] == -1)
        {
            int pr = 1e9, j = i;
            while (p[j] != -1)
            {
                int pj = p[j];
                assert(pr >= pj);
                if (pr > pj)
                {
                    for (int k = pj; k <= n; k += pj)
                        if (q[k] == -1)
                            q[k] = s;
                    pr = pj;
                }
                j /= pj;
            }
            if (j != 1 && pr != j)
                for (int k = j; k <= n; k += j)
                    if (q[k] == -1)
                        q[k] = s;
            vector<int> v;
            v.push_back(i);
            a.push_back(v);
            ++s;
        }
        else
        {
            a[q[i]].push_back(i);
        }
    }
 
    for (auto &v: a)
        for (auto &x: v)
        {
            int ox = x;
            write(ox);
        }
    putchar_unlocked(49);
    return 0;
}
