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
const int maxn = 500+10;
const int maxso = 100000+2;
int a[maxn][maxn];
//long long s[maxn][maxn];
//long long KQ[maxso*2+10];
//long long IT[maxso*2*4+10];
int GTmin[maxn][maxn][2];
int GTmax[maxn][maxn][2];
int BIT[maxn][maxso+10];
int Val[maxn][maxso+10];
//double so;
int l,r,t;
int m,n,q,ms;
/*
void update(int i,int k,int gt)
{
    while (i<=maxso)
    {
        BIT[k][i]=max(BIT[k][i],gt);
        i=i+(i & (-i));
    }
}


int get(int i,int k)
{
    int gt=0;
    while (i>=1)
    {
        gt=max(BIT[k][i],gt);
        i=i-(i & (-i));
    }
    return gt;
}

void build(int node,int l,int r)
{
    if (l>r) return;
    if (l==r)
    {
        IT[node]=KQ[l];
        return;
    }
    int m = (l+r)/2;
    build(node*2,l,m);
    build(node*2+1,m+1,r);
    IT[node]=max(IT[node*2],IT[node*2+1]);
}

int get(int node,int l,int r,int u,int v)
{
    if (r<u||l>v) return 0;
    if (u<=l&&r<=v) return IT[node];
    int m = (l+r)/2;
    return max(get(node*2,l,m,u,v),get(node*2+1,m+1,r,u,v));
}*/

int calc(int left,int right)
{
    int kq = 0;
    int mid;
    l=1;r=min(m,n);
    while (l<=r)
    {
        mid=(l+r)/2;
        if (Val[mid][min(ms,right)]>=left) kq=mid,l=mid+1;
        else r=mid-1;
    }
    return kq;
}

int main()
{
    //freopen("grape_13.inp","r",stdin);
    //freopen("grape_13.out","w",stdout);
    scanf("%d%d%d",&m,&n,&q);
    ms=0;
    FOR (i,1,m)
    FOR (j,1,n)
    {
        scanf("%d",&a[i][j]);
        a[i][j]++;
        ms=max(ms,a[i][j]);
        //s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    }

    FOR(i,1,m)
    FOR(j,1,n)
        GTmin[i][j][1]=a[i][j],GTmax[i][j][1]=a[i][j],Val[1][GTmax[i][j][1]]=max(Val[1][GTmax[i][j][1]],GTmin[i][j][1]);
    t=0;
    FOR(k,1,min(m,n))
    {
        if (k>1)
        FOR(i,k,m)
        FOR(j,k,n){
            GTmin[i][j][k]=min(min(GTmin[i][j-1][k-1],GTmin[i-1][j][k-1]),GTmin[i-1][j-1][k-1]);
            GTmax[i][j][k]=max(max(GTmax[i][j-1][k-1],GTmax[i-1][j][k-1]),GTmax[i-1][j-1][k-1]);
            Val[k][GTmax[i][j][k]]=max(Val[k][GTmax[i][j][k]],GTmin[i][j][k]);
        }
        FOR(i,1,ms)
        //if (Val[k][i]!=0) update(i,k,Val[k][i]);
        Val[k][i]=max(Val[k][i-1],Val[k][i]);
        t=1-t;
    }
        FOR(i,1,q)
    {
        scanf("%d%d",&l,&r);
        l++;
        r++;
        int gt=calc(l,r);
        printf("%d\n",gt*gt);
    }
    /*
    build(1,1,maxso);
    FOR(i,1,q)
    {
        scanf("%d%d",&l,&r);
        l=l*2+1;
        r=r*2+1;
        printf("%d\n",get(1,1,maxso,l,r));
    }*/
}

