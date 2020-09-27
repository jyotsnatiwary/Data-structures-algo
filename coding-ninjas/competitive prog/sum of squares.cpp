#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 100007

using namespace std;

int addv[maxn<<2],setv[maxn<<2];
long long sumv[maxn<<2],sqrsumv[maxn<<2];

inline void pushdown(int k,int l,int r)
{
  int lc=k*2+1,rc=k*2+2,m=l+r>>1;
  addv[lc]+=addv[k];
  addv[rc]+=addv[k];
  addv[k]=0;

  if (setv[k]!=INF)
  {
    setv[lc]=setv[rc]=setv[k];
    sumv[lc]=(LL)setv[lc]*(m-l);sumv[rc]=(LL)setv[rc]*(r-m);
    sqrsumv[lc]=sqr((LL)setv[k]*(m-l));sqrsumv[rc]=sqr((LL)setv[rc])*(r-m);
    addv[lc]=addv[rc]=0;
    setv[k]=INF;
  }
}

inline void pushup(int k,int l,int r)
{
  int lc=k*2+1,rc=k*2+2,m=l+r>>1;

  sumv[k]=sumv[lc]+sumv[rc]+(LL)addv[lc]*(m-l)+(LL)addv[rc]*(r-m);
  sqrsumv[k]=sqrsumv[lc]+sqrsumv[rc]+(LL)(r-l)*(addv[k])+2ll*sumv[k]*addv[k];
}

void build(int k,int l,int r)
{
  addv[k]=0;
  setv[k]=INF;
  sumv[k]=sqrsumv[k]=0ll;

  if (r-l==1)
  {
    scanf("%d",&sumv[k]);
    sqrsumv[k]=sqr((LL)sumv[k]);
    return ;
  }

  build(k*2+1,l,l+r>>1);
  build(k*2+2,l+r>>1,r);

  pushup(k,l,r);
}

void update_add(int a,int b,int v,int k,int l,int r)
{
  if (b<=l || r<=a) return ;
  if (a<=l && r<=b)
  {
    addv[k]+=v;
    sqrsumv[k]+=sqr((LL)v)*(r-l)+2ll*v*sumv[k];
    return ;
  }

  pushdown(k,l,r);

  update_add(a,b,v,k*2+1,l,l+r>>1);
  update_add(a,b,v,k*2+2,l+r>>1,r);

  pushup(k,l,r);
}

void update_set(int a,int b,int v,int k,int l,int r)
{
  if (b<=l || r<=a) return ;
  if (a<=l && r<=b)
  {
    addv[k]=0;
    setv[k]=v;
    sumv[k]=(LL)v*(r-l);
    sqrsumv[k]=sqr((LL)v)*(r-l);
    return ;
  }

  pushdown(k,l,r);

  update_set(a,b,v,k*2+1,l,l+r>>1);
  update_set(a,b,v,k*2+2,l+r>>1,r);

  pushup(k,l,r);
}

long long query(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return 0ll;
  if (a<=l && r<=b) return sqrsumv[k];
  
  pushdown(k,l,r);

  return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T,__=0;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    
    build(0,0,n);

    printf("Case %d:\n",++__);

    int op,a,b,v;
    while (m--)
    {
      scanf("%d",&op);

      switch (op)
      {
        case 0:
          scanf("%d%d%d",&a,&b,&v);
          a--;
          update_set(a,b,v,0,0,n);
          break;
        case 1:
          scanf("%d%d%d",&a,&b,&v);
          a--;
          update_add(a,b,v,0,0,n);
          break;
        case 2:
          scanf("%d %d",&a,&b);
          a--;
          printf(lld "\n",query(a,b,0,0,n));
          break;
      }
    }
  }


  return 0;
}
