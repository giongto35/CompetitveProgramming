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
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 100000+10;
int a[maxn];
long long BIT[maxn];
int IT[maxn*4];
int n,m,t;
int u,v,x;

void update(int i,int gt)//change long long
{
    while (i<=n)
    {
        BIT[i]=BIT[i] + gt;
        i=i+(i & (-i));
    }
}


long long get(int i)
{
    long long gt=0;//change long long
    while (i>=1)
    {
        gt=BIT[i] + gt;
        i=i-(i & (-i));
    }
    return gt;
}

void update_IT(int node,int l,int r,int u)
{
    if (u < l) return;
    if (u > r) return;
    if (l == u && r == u)
    {
        IT[node] = u;
        return ;
    }
    int mid = (l + r) / 2;
    update_IT(node * 2, l, mid, u);
    update_IT(node * 2 + 1, mid + 1, r, u);
    int gu = IT[node * 2];
    int gv = IT[node * 2 + 1];
    if (a[gu] > a[gv]) IT[node] = gu;
    else IT[node] = gv;
}

int get_IT(int node,int l,int r, int u, int v)
{
    if (v < l) return 0;
    if (u > r) return 0;
    if (u <= l && r <= v)
    {
        return IT[node];
    }
    int mid = (l + r) / 2;
    int gu = get_IT(node * 2, l, mid, u, v);
    int gv = get_IT(node * 2 + 1, mid + 1, r, u, v);
    if (a[gu] > a[gv]) return gu;
    else return gv;
}

int main()
{
    //freopen("D438.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        update(i,a[i]);
        update_IT(1,1,n,i);
    }
    a[0] = - 123124;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d",&t);
        if (t == 1)
        {
            scanf("%d%d",&u,&v);
            printf("%I64d\n",get(v) - get(u-1));
        }
        if (t == 2)
        {
            scanf("%d%d%d",&u,&v,&x);
            while(true)
            {
                int f = get_IT(1,1,n,u,v);
                if (a[f] >= x)
                {
                    update(f,-a[f]);
                    a[f] %= x;
                    update_IT(1,1,n,f);
                    update(f,a[f]);
                }
                else break;
            }
        }
        if (t == 3)
        {
            scanf("%d%d",&u,&v);
            update(u,-a[u]);
            a[u] = v;
            update_IT(1,1,n,u);
            update(u,a[u]);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

