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

struct edge {
    int a;
    int b;
    int r;
    int p;
    int tt;
};
const int maxn = 30000 + 10;
edge e[maxn];
map<int,int> ma;
int lab[maxn];
int a,b,r,p,n;
int cnt;
long long res;

bool mycmp( edge u, edge v)
{
    if (u.r == v.r)
    {
        return u.p > v.p;
    }
    return u.r > v.r;
}

int getroot(int u)
{
    if (lab[u] == -1) return u;
    lab[u] = getroot(lab[u]);
    return lab[u];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d",&a,&b,&r,&p);
        if (ma.count(a) == 0)
        {
            ma[a] = ++cnt;
        }
        if (ma.count(b) == 0)
        {
            ma[b] = ++cnt;
        }
        e[i].a = ma[a];
        e[i].b = ma[b];
        e[i].r = r;
        e[i].p = p;
        e[i].tt= i;
    }
    sort(e + 1, e + 1 + n, mycmp);
    for (int i = 1; i <= cnt; i++) lab[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        int l1 = getroot(e[i].a);
        int l2 = getroot(e[i].b);
        if (l1 != l2)
        {
            lab[l1] = l2;
            res += e[i].p;
        }

    }
    cout<<res<<endl;
    for (int i = n; i >= 1; i--) printf("%d ",e[i].tt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

