#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int cmod=95542721;
const int smod=48;
const int maxn=100000+10;
int a[maxn];
int tmp[smod];
int n,m,t,l,r;
struct IntervalTree
{
    int p[smod];
    int val;
} IT[maxn*4];

void build (int node,int l,int r)
{
    if (l>r) return;
    if (l==r)
    {
        long long t=a[l];
        FOR(i,0,smod-1)
        {
            IT[node].p[i]=t;
            t=((t*t)%cmod*t)%cmod;
        }
        return ;
    }
    int mid = (l+r)>>1;
    build(node<<1,l,mid);
    build((node<<1)+1,mid+1,r);
    FOR(i,0,smod-1) IT[node].p[i]=(IT[node<<1].p[i]+IT[(node<<1)+1].p[i])%cmod;
}

void extract(int node)
{
    if (IT[node].val>0)
    {
        memcpy(tmp,IT[node<<1].p,sizeof(tmp));
        FOR(i,0,smod-1)IT[node<<1].p[i]=tmp[(i+IT[node].val)%smod];
        IT[node<<1].val+=IT[node].val;
        memcpy(tmp,IT[(node<<1)+1].p,sizeof(tmp));
        FOR(i,0,smod-1)IT[(node<<1)+1].p[i]=tmp[(i+IT[node].val)%smod];
        IT[(node<<1)+1].val+=IT[node].val;
        IT[node].val=0;
    }
}

int get(int node,int l,int r,int &u,int &v)
{
    if (v<l||u>r) return 0;
    if (u<=l&&r<=v)
    {
        return IT[node].p[0];
    }
    int mid = (l+r)>>1;
    extract(node);
    return (get(node<<1,l,mid,u,v) + get((node<<1)+1,mid+1,r,u,v))%cmod;
}

void update(int node,int l,int r,int &u,int &v)
{
    if (v<l||u>r) return;
    if (u<=l&&r<=v)
    {
        memcpy(tmp,IT[node].p,sizeof(tmp));
        FOR(i,0,smod-1)IT[node].p[i]=tmp[(i+1)%smod];
        IT[node].val++;
        return;
    }
    int mid = (l+r)>>1;
    extract(node);
    update(node<<1,l,mid,u,v);
    update((node<<1)+1,mid+1,r,u,v);
    FOR(i,0,smod-1)
    IT[node].p[i]=(IT[node<<1].p[i]+IT[(node<<1)+1].p[i])%cmod;
}

int main()
{
    //freopen("D311.inp","r",stdin);
    //freopen("D311.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) cin>>a[i];
    build(1,1,n);
    scanf("%d",&m);
    FOR(i,1,m)
    {
        scanf("%d%d%d",&t,&l,&r);
        if (t==1) cout<<get(1,1,n,l,r)<<endl;
        if (t==2) update(1,1,n,l,r);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

