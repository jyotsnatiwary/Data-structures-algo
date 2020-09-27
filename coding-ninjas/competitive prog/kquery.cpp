#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>

#define MAX 30001

struct Query {
    int l;
    int r;
    int k;
    int index;
};

int tree[1 << 15]; // BIT

void update_tree(int pos)
{
    while (pos <= MAX)
    {
        tree[pos] += 1;
        pos += (pos & -pos);
    }
}

int query_tree(int pos)
{
    int result = 0;
    
    while(pos > 0)
    {
        result += tree[pos];
        pos -= (pos & -pos);
    }
    
    return result;
}

int main()
{
    std::memset(tree, 0, sizeof(int) * (1 << 15));
    
    int n;
    std::scanf("%d", &n);
    
    std::vector<std::pair<int,int>> arr (n); // pair [value, original index]
    
    for (int i = 0; i < n; ++i)
    {
        std::scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    
    // Sort arr by decreasing order of value
    std::sort(arr.rbegin(), arr.rend());
    
    int q;
    std::scanf("%d", &q);
    
    std::vector<Query> queries (q);
    std::vector<int> result (q);
    
    for (int i = 0; i < q; ++i)
    {
        std::scanf("%d%d%d", &queries[i].l, &queries[i].r, &queries[i].k);
        queries[i].index = i;
    }
    
    // Sort queries by decreasing order of k
    std::sort(std::begin(queries), std::end(queries), [](const Query& a, const Query& b){return a.k > b.k;});
    
    // Solve
    int pos = 0;
    for (int i = 0; i < q; ++i)
    {
        while (pos < n && arr[pos].first > queries[i].k)
        {
            update_tree(arr[pos].second + 1);
            ++pos;
        }
        
        result[queries[i].index] = query_tree(queries[i].r) - query_tree(queries[i].l-1);
    }
    
    // Print
    for (auto num: result)
        std::printf("%d\n", num);

    return 0;
}
