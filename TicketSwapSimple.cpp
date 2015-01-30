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

const int maxm = 1000+10;
struct event
{
    int vt;
    int p;
    int t;
};
int l[maxm],r[maxm],p[maxm];
int n,m,T;
vector<event> e;

bool mycmp(event a,event b)
{
    return make_pair(a.vt,a.t) < make_pair(b.vt,b.t);
}

event mevent(int vt, int p, int t)
{
    event res;
    res.vt = vt;
    res.p = p;
    res.t = t;
    return res;
}
int main()
{
    freopen("ticketswap.inp","r",stdin);
    freopen("ticketswap.out","w",stdout);
    scanf("%d",&T);
    for (int sT = 1; sT <= T; sT++)
    {

        scanf("%d%d",&n,&m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d",&l[i],&r[i],&p[i]);
            e.push_back(mevent(l[i],p[i],1));
            e.push_back(mevent(r[i],p[i],2));
        }
    }
    sort(e.begin(),e.end(),mycmp);
    vector<event>::iterator it = unique(e.begin(),e.end());
    e.resize(distance(e.begin(),it));
    fclose(stdin);
    fclose(stdout);
    return 0;
}

