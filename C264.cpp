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

using namespace std;
const int maxn = 100000+10;
const long long low = -100000000000000000LL;
int v[maxn];
int c[maxn];
int a,b;
long long f;
int n,q;
long long BIT[2][maxn];
long long res,val;
long long GT[maxn];

inline void update(int i,int k,long long &gt)
{
    while (i<=n+1)
    {
        BIT[k][i]=max(BIT[k][i],gt);
        i=i+(i & (-i));
    }
}


inline long long get(int i,int k)
{
    long long gt=low;
    while (i>=1)
    {
        gt=max(BIT[k][i],gt);
        i=i-(i & (-i));
    }
    return gt;
}


void calc()
{
    FOR(j,0,n+1)
    {
        FOR(i,0,1) BIT[i][j]=low;
        GT[j]=low;
    }
    GT[n+1]=0;
    update(n+1        ,0,GT[n+1]);
    update((n+2)-(n+1),1,GT[n+1]);
    long long res=0;
    FOR(i,1,n)
    {
        f=low;
        //cout<<i<<endl;
        if (GT[c[i]]!=low) f=max(f,GT[c[i]]+(long long)v[i]*a);
        val=get(c[i]-1,0);
        if (val!=low) f=max(f,val+(long long)v[i]*b);
        val=get((n+2)-(c[i]+1),1);
        if (val!=low) f=max(f,val+(long long)v[i]*b);
        GT[c[i]]=max(GT[c[i]],f);
        update(c[i]      ,0,GT[c[i]]);
        update((n+2)-c[i],1,GT[c[i]]);
        res=max(res,f);
    }
    cout<<res<<endl;
}

int main()
{
    freopen("C264.inp","r",stdin);
    freopen("C2642.out","w",stdout);
    cin>>n>>q;
    FOR(i,1,n)scanf("%d",&v[i]);
    FOR(i,1,n)scanf("%d",&c[i]);
    FOR (i,1,q)
    {
        scanf("%d %d",&a,&b);
        calc();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

