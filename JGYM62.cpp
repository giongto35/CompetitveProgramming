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

struct kdl
{
    int u;

    kdl(int v):u(v) {};
};
const int maxn =100000+10;
int T,n;
int x[maxn],p[maxn],m[maxn];
set<kdl>  s;
long long res;

bool operator < (kdl u, kdl v)
{
    if (p[u.u] == p[v.u]) return u.u < v.u;
    return p[u.u] > p[v.u];
}


int main()
{
    //freopen("JGYM6.inp","r",stdin);
    //freopen("JGYM6.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d",&x[i],&p[i],&m[i]);
        }
        //cout<<n<<endl;
        s.clear();
        /*for (int i = n; i >= 1; i--)
            s.insert(kdl(i));
        for (int i = 1; i <= n; i++)
        {
            while (x[i] > 0 && !s.empty()) {
                int j = (*s.begin()).u;
                int gt = min(x[i],m[j]);
                x[i] = x[i] - gt;
                m[j] = m[j] - gt;
                res = res + gt * p[j];
                //cout<<i<<' '<<j<<' '<<p[j]<<' '<<gt<<' '<<res<<endl;
                if (m[j] == 0)
                {
                    s.erase(s.begin());
                }
            }
            s.erase(kdl(i));
        }*/
        res = 0;
        for (int i = n; i >= 1; i--)
        {
            s.insert(kdl(i));
            while (x[i] > 0 && !s.empty()) {
                int j = (*s.begin()).u;
                int gt = min(x[i],m[j]);
                x[i] = x[i] - gt;
                m[j] = m[j] - gt;
                res = res + (long long)gt * p[j];
                //cout<<i<<' '<<j<<' '<<p[j]<<' '<<gt<<' '<<res<<endl;
                if (m[j] == 0)
                {
                    s.erase(s.begin());
                }
            }
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

