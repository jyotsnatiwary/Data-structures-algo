#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll tree[400400];
ll lazy[400400];

ll query(ll idx,ll queryStart,ll queryEnd,ll treeStart,ll treeEnd)
{
    if(lazy[idx]!=0)
    {
        tree[idx]+=(treeEnd-treeStart+1)*lazy[idx];
        if(treeStart!=treeEnd)
        {
            lazy[2*idx]+=lazy[idx];
            lazy[2*idx+1]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(treeStart>treeEnd || treeStart>queryEnd || treeEnd<queryStart)
    {
        return 0;
    }
    if(treeStart>=queryStart && treeEnd<=queryEnd)
    {
        return tree[idx];
    }
    ll mid=treeStart+(treeEnd-treeStart)/2;
    return query(2*idx,queryStart,queryEnd,treeStart,mid)+query(2*idx+1,queryStart,queryEnd,mid+1,treeEnd);
}

void update(ll idx,ll updateStart,ll updateEnd,ll treeStart,ll treeEnd,ll val)
{
    if(lazy[idx] != 0)
    {
        tree[idx]+=(treeEnd-treeStart+1)*lazy[idx];
        if(treeStart!=treeEnd)
        {
            lazy[2*idx]+=lazy[idx];
            lazy[2*idx+1]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(treeStart>treeEnd || treeStart>updateEnd || treeEnd<updateStart)
    {
        return ;
    }
    if(treeStart>=updateStart && treeEnd<=updateEnd)
    {
        tree[idx]+=(treeEnd-treeStart+1)*val;
        if(treeStart!=treeEnd)
        {
            lazy[2*idx]+=val;
            lazy[2*idx+1]+=val;
        }
        return ;
    }
    ll mid=treeStart+(treeEnd-treeStart)/2;
    update(2*idx,updateStart,updateEnd,treeStart,mid,val);
    update(2*idx+1,updateStart,updateEnd,mid+1,treeEnd,val);
    tree[idx]=tree[2*idx]+tree[2*idx+1];
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        ll temp,a,b;
        while(c--)
        {
            cin>>temp;
            if(temp)
            {
                cin>>a>>b;
                cout<<query(1,a,b,1,n)<<"\n";
            }
            else
            {
                cin>>a>>b>>temp;
                update(1,a,b,1,n,temp);
            }
        }
    }
    return 0;
}
