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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 100000+10;
const int l10 = log2(maxn);
int G[maxn][18];
int smin[maxn][18];
int smax[maxn][18];
int a[maxn];
map<int,int> b;
int n,q,l,r;
int bit[maxn];

int GCD(int u,int v)
{
    if (v==0) return u;
    return GCD(v,u % v);
}
void setup()
{
    FOR(i,1,n) smin[i][0]=a[i],smax[i][0]=a[i],G[i][0]=abs(a[i+1]-a[i]);
    FOR(j,1,log2(n))
    FOR(i,1,n-(1<<j)+1)
    {
        //cout<<i<<' '<<j<<endl;
        smin[i][j]=min(smin[i][j-1],smin[i+(1<<(j-1))][j-1]);
        smax[i][j]=max(smax[i][j-1],smax[i+(1<<(j-1))][j-1]);
        G   [i][j]=GCD(G   [i][j-1],G   [i+(1<<(j-1))][j-1]);
    }
}

void update(int i,int gt)
{
    if (i==0) return;
    while (i<=n)
    {
        bit[i]=max(bit[i],gt);
        i=i+(i&(-i));
    }
}

int get(int i)
{
    int gt=0;
    while (i>=1)
    {
        gt=max(gt,bit[i]);
        i=i-(i&(-i));
    }
    return gt;
}

int main()
{
    //freopen("AVLBIT.inp","r",stdin);
    //freopen("AVLBIT.out","w",stdout);
    scanf("%d%d",&n,&q);
    FOR(i,1,n)
    {
        scanf("%d",&a[i]);
        if (b.count(a[i])>0) update(i,b[a[i]]);
        b[a[i]]=i;
    }
    setup();
    FOR(i,1,q)
    {
        scanf("%d%d",&l,&r);
        if (l==r)
        {
            printf("YES\n");
            continue;
        }
        if (get(r)>=l)
        {
            printf("NO\n");
            continue;
        }
        int k=(int)log2(r-l+1);
        //cout<<dd<<' '<<smin[l][dd]<<endl;
        int s0=min(smin[l][k],smin[r-(1<<(k))+1][k]);
        int sn=max(smax[l][k],smax[r-(1<<(k))+1][k]);
        k=(int)log2(r-1-l+1);
        int d =GCD(G   [l][k],G   [r-1-(1<<(k))+1][k]);
        //cout<<s0<<' '<<sn<<' '<<d<<endl;
        if (s0+d*(r-l)==sn)
            printf("YES\n"); else printf("NO\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

