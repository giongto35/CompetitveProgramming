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
int l[maxn];
int r[maxn];
int q[maxn];
int IT[maxn * 4];
int res[maxn];
int vt[maxn];
int n,m;

void extract(int node)
{
    if (IT[node] == 1)
    {
        IT[node * 2] = 1;
        IT[node * 2 + 1] = 1;
    }
}

void fill(int node, int l, int r, int u, int v)
{
    if (v < l) return;
    if (u > r) return;
    if (u <= l && r <= v) {
        IT[node] = 1;
        return;
    }
    extract(node);
    int mid = (l + r) / 2;
    fill(node * 2, l, mid, u, v);
    fill(node * 2 + 1, mid + 1, r, u, v);
    IT[node] = IT[node * 2] & IT[node * 2 + 1];
}

int get(int node, int l, int r, int u, int v)
{
    if (v < l) return (1 << 30) - 1;
    if (u > r) return (1 << 30) - 1;
    if (u <= l && r <= v) {
        return IT[node];
    }
    extract(node);
    int mid = (l + r) / 2;
    return get(node * 2, l, mid, u, v) & get(node * 2 + 1, mid + 1, r, u, v);
}

void build (int node, int l, int r)
{
    //cout<<node<<' '<<l<<' '<<r<<endl;
    if (r < l) return;
    if ( l == r) {
        vt[l] = node;
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
}

int calc(int u)
{
    while (u >= 1)
    {
        if (IT[u] == 1) return 1;
        u/=2;
    }
    return 0;
}

int main()
{
    freopen("B4822.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d",&l[i],&r[i],&q[i]);
    }
    build(1,1,n);
    for (int k = 0; k <= 29; k++)
    {
        memset(IT, 0, sizeof(IT));
        for (int i = 1; i <= m; i++)
        {
            if (((q[i] >> k) & 1) == 1) {
                fill(1, 1, n, l[i], r[i]);
            }
        }
        for (int i = 1; i <= m; i++)
        {
            int b = ((q[i] >> k) & 1);
            if (get(1, 1, n, l[i], r[i]) != b) {
                cout<<"NO";
                return 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (calc(vt[i]))
            {
                res[i] += (1 << k) ;
            }
        }
    }
    cout<<"YES"<<endl;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ",res[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

