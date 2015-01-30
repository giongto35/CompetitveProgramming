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
const int cmod = 1000000000;
const int maxn=2*100000+10;
struct interval
{
    int s1;
    int s2;
    int val;
} it[maxn*4],res;
int hs1[maxn];
int hs2[maxn];
int a[maxn],n,m,dd,s[maxn],f[maxn],t,x,u,v,d;

void merge(interval it1,interval it2,interval &it,int dd)
{
    it.s1 = (((long long)it2.s1*hs1[dd+1]+(long long)it2.s2*hs2[dd+1])%cmod+it1.s1)%cmod;
    it.s2 = (((long long)it2.s1*hs1[dd]  +(long long)it2.s2*hs2[dd]  )%cmod+it1.s2)%cmod;
}

void build(int node,int l,int r)
{
    if (l>r) return;
    if (l==r)
    {
        it[node].s1=a[l];
        it[node].s2=0;
        return;
    }
    int mid = (l+r)/2;
    build(node * 2,l,mid);
    build(node * 2 + 1,mid+1,r);
    merge(it[node*2],it[node*2+1],it[node],mid-l+1);
}

void extract(int node,int l,int r)
{
    if (it[node].val!=0)
    {
        int mid = (l+r)/2;
        it[node*2].val=(it[node*2].val+it[node].val)%cmod;
        it[node*2].s1=(it[node*2].s1+((long long)s[mid-l+1]*it[node].val)%cmod)%cmod;
        it[node*2].s2=(it[node*2].s2+((long long)s[mid-l  ]*it[node].val)%cmod)%cmod;
        it[node*2+1].val=(it[node*2+1].val+it[node].val)%cmod;
        it[node*2+1].s1=(it[node*2+1].s1+((long long)s[r-mid  ]*it[node].val)%cmod)%cmod;
        it[node*2+1].s2=(it[node*2+1].s2+((long long)s[r-mid-1]*it[node].val)%cmod)%cmod;
        it[node].val=0;
    }
}

void get (int node ,int l,int r,int u,int v)
{
    if (r<u||l>v) return;
    if (u<=l&&r<=v)
    {
        merge(res,it[node],res,dd);
        dd=dd+r-l+1;
        return;
    }
    extract(node,l,r);
    int mid = (l+r)/2;
    get(node*2  ,l,mid,u,v);
    get(node*2+1,mid+1,r,u,v);
}

void update(int node,int l,int r,int u,int v,int gt)
{
    if (r<u||l>v) return ;
    if (u<=l&&r<=v)
    {
        it[node].val=(it[node].val+gt)%cmod;
        //cout<<"ABC "<<gt<<' '<<it[node].val<<endl;
        it[node].s1 =(it[node].s1+((long long)gt*s[r-l+1])%cmod)%cmod;
        it[node].s2 =(it[node].s2+((long long)gt*s[r-l])%cmod)%cmod;
        return;
    }
    extract(node,l,r);
    int mid = (l+r)/2;
    update(node*2  ,l,mid,u,v,gt);
    update(node*2+1,mid+1,r,u,v,gt);
    merge(it[node*2],it[node*2+1],it[node],mid-l+1);

}

int calc(int u,int v)
{
    res.s1=0;res.s2=0;
    dd=0;
    get(1,1,n,u,v);
    return res.s1;
}

int main()
{
    //freopen("E316.inp","r",stdin);
    //freopen("E316.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    f[1]=1;s[1]=1;
    f[2]=1;s[2]=2;
    FOR(i,3,n)
    {
        f[i]=(f[i-2]+f[i-1])%cmod;
        s[i]=(s[i-1]+f[i])%cmod;
    }
    hs1[0]=0;
    hs1[1]=1;
    FOR(i,2,n+2) hs1[i]=(hs1[i-1]+hs1[i-2])%cmod;
    hs2[0]=1;
    hs2[1]=0;
    FOR(i,2,n+2) hs2[i]=(hs2[i-1]+hs2[i-2])%cmod;
    build(1,1,n);
    FOR(i,1,m)
    {
        cin>>t;
        if (t==1)
        {
            cin>>x>>v;
            update(1,1,n,x,x,(v-calc(x,x))%cmod);
        }
        else
        if (t==2)
        {
            cin>>u>>v;
            cout<<(calc(u,v)+cmod)%cmod<<endl;
        }
        else
        if (t==3)
        {
            cin>>u>>v>>d;
            update(1,1,n,u,v,d);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

