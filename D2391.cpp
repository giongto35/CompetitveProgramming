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

const int maxn = 50000+10;
struct vertical{
    int x;
    int y;
    int l;
} v[maxn];

struct horizontal{
    int x;
    int y;
    int l;
} h[maxn];

struct event{
    int i;
    int t;
    int x;
} e[maxn * 3];
int n,m;
int spt;
int res;
int gh;
int b[maxn * 3];
vector<int> Y;
int ySize;

int get(int i)
{
    int sum = 0;
    //cout<<"get "<<i<<endl;
    for (;i >= 1; i -= (i & (-i))) sum += b[i];
    return sum;
}

void update(int i, int gt)
{
    //cout<<"update "<<i<<' '<<gt<<endl;
    int sum = 0;
    if ( i == 0) return;
    for (;i <= ySize; i += (i & (-i))) b[i]+=gt;
}

bool mycmp(const event &e1,const event &e2)
{
    if (e1.x == e2.x) return e1.t<e2.t;
    else
    return e1.x < e2.x;
}

inline int TimY(int v)
{
    return lower_bound(Y.begin(),Y.end(),v) - Y.begin() + 1;
}

bool check(int val)
{
    spt = 0;
    Y.clear();
    for (int i = 1; i <= n; i++)
    {
        if (v[i].l >= 2 * val)
        {
            e[++spt].x = v[i].x;
            e[spt].i = i;
            e[spt].t = 2;
            Y.push_back(v[i].y + val - 1);
            Y.push_back(v[i].y + v[i].l - val);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (h[i].l >= 2 * val)
        {
            e[++spt].x = h[i].x + val;
            e[spt].i = i;
            e[spt].t = 1;

            e[++spt].x = h[i].x + h[i].l - val;
            e[spt].i = i;
            e[spt].t = 3;
            Y.push_back(h[i].y);
        }
    }
    sort(Y.begin(),Y.end());
    Y.resize(unique(Y.begin(),Y.end()) - Y.begin());

    sort(e + 1, e + 1 + spt, mycmp);
    ySize = Y.size();
    for (int i = 1; i <= ySize; i++) b[i] = 0;
    for (int i = 1; i <= spt; i++)
    {
        if (e[i].t == 1)
            update(TimY(h[e[i].i].y),1);
        else
        if (e[i].t == 3)
            update(TimY(h[e[i].i].y),-1);
        else
            if (get(TimY(v[e[i].i].y + v[e[i].i].l - val)) - get(TimY(v[e[i].i].y + val - 1)) > 0)
                return true;
    }
    return false;
}

int main()
{
    //freopen("D2.inp","r",stdin);
    //freopen("D2.out","w",stdout);
    scanf("%d%d",&n,&m);
    spt = 0;
    gh = 0;
    FOR(i,1,n) scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].l);
    FOR(i,1,m) scanf("%d%d%d",&h[i].x,&h[i].y,&h[i].l);
    int r = 1;
    while (check(r)) r *= 2;
    int l = 1;
    while ( l <= r)
    {
        int mid = (l  +  r) / 2;
        if (check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

