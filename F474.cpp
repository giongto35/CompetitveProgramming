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

const int maxn = 100000 + 10;
struct interval{
    int min;
    int cnt;
    int gcd;
} ss;

interval it[maxn*8];

int n,t;
int l,r;
int a[maxn];

void build(int node, int l, int r)
{
    if (l > r) return;
    if (l == r)
    {
        it[node].min = a[l];
        it[node].gcd = a[l];
        it[node].cnt = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    it[node].gcd = __gcd(it[node * 2].gcd, it[node * 2 + 1].gcd);
    if (it[node * 2].min == it[node * 2 + 1].min)
    {
        it[node].min = it[node * 2].min;
        it[node].cnt = it[node * 2].cnt + it[node * 2 + 1].cnt;
    }
    else
    if (it[node * 2].min < it[node * 2 + 1].min)
    {
        it[node].min = it[node * 2].min;
        it[node].cnt = it[node * 2].cnt;
    }
    else
    if (it[node * 2].min > it[node * 2 + 1].min)
    {
        it[node].min = it[node * 2 + 1].min;
        it[node].cnt = it[node * 2 + 1].cnt;
    }
}

void get(int node, int l, int r, int u, int v)
{
    if (r < u) return;
    if (l > v) return;
    if (u <= l && r <= v)
    {
        if (ss.gcd == -1) ss.gcd = it[node].gcd;
        else ss.gcd = __gcd(ss.gcd, it[node].gcd);
        if (ss.min == it[node].min) ss.cnt += it[node].cnt;
        else
        if (ss.min > it[node].min)
        {
            ss.min = it[node].min;
            ss.cnt = it[node].cnt;
        }
        return;
    }
    int mid = (l + r) / 2;
    get(node * 2, l, mid, u, v);
    get(node * 2 + 1, mid + 1, r, u, v);
}

int main()
{
    //freopen("F474.inp","r",stdin);
    //freopen("F474.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    build(1,1,n);
    scanf("%d",&t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d%d",&l,&r);
        ss.gcd = -1;
        ss.min = 1100000000;
        get(1,1,n,l,r);
        //cout<<ss.gcd<<' '<<ss.min<<endl;
        if (ss.gcd == ss.min)
        {
            printf("%d\n", r - l + 1 - ss.cnt);
        }
        else
        {
            printf("%d\n", r - l + 1 );
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

