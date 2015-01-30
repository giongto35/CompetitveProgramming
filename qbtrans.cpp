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

const int maxn = 20000+10;
const int MAXCHECK = 100000;
const double eps = 0.00001;
struct edge{
int u;
int v;
int d;
} E[maxn];
double d[maxn];
vector<int> a[maxn];
int sz;
int n,m;
int q[maxn],TC;

bool check(double r)
{
    for (int i = 1; i <= n; i++)
    {
        E[i+m].d = r;
        d[i] = oo;
    }
    d[0] = 0;
    int sz = 1;
    int fr = -1;
    int re = 0;
    q[0] = 0;

    int cnt = 0;
    while(sz >= 1)
    {
        fr = (fr + 1) % (n + 2);
        //for (int i = 0; i<= n; i++) cout<<d[i]<<' ';cout<<endl;
        sz--;
        //cout<<"front = "<<q[fr]<<endl;
        FOREACH(it, a[q[fr]])
        {
            cnt++;
            edge v = E[*it];
            if (d[v.v] > d[v.u] + v.d - r)
            {
                d[v.v] = d[v.u] + v.d - r;
                re = (re + 1) % (n + 2);
                q[re] = v.v;
                cnt++;
                sz++;
            }
        }
        if (cnt >= MAXCHECK) return true;
    }
    return false;
}

edge make_edge(int u,int v,int d)
{
    edge res;
    res.u = u;
    res.v = v;
    res.d = d;
    return res;
}

int main()
{
    freopen("QBTRANS.inp","r",stdin);
    //freopen("C5.out","w",stdout);
    /*scanf("%d",&TC);
    while (TC > 0)
    {*/
        scanf("%d%d",&n,&m);
        double r = 0;
        for (int i = 0; i <= n; i++) a[i].clear();
        double gtmax = 0;
        for (int i = 1; i <= m; i++)
            {
                scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].d),gtmax=max(gtmax,(double)E[i].d);
                a[E[i].u].push_back(i);
            }
            r = gtmax + 1;
        for (int i = 1; i <= n; i++)
        {
            E[i + m] = make_edge(0,i,0);
            a[0].push_back(i+m);
        }
        double l = 0;
        for (int i = 1; i <= 20; i++)
        {
            double mid = (l + r) / 2;
            if (check(mid))
                r = mid;
            else
                l = mid;
        }
        if (l + eps < gtmax + 1)
            cout<<fixed<<setprecision(4)<<l<<endl;
        else
            cout<<"-1";
    fclose(stdin);
    fclose(stdout);
    return 0;
}


