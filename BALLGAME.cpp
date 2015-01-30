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

const int maxn = 1000+10;
struct point
{
    int y;
    int x;
    int c;
    int idx;
} p[2][maxn],o;
int n;
int g[maxn*2];

bool mycmp(point p1,point p2)
{
    return (p1.y - o.y) * (p1.x - o.x)
}

int main()
{
    freopen("BALLGAME.inp","r",stdin);
    freopen("BALLGAME.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n)
        scanf("%d%d",&p[0][i].x,&p[0][i].y),p[0][i].idx = i;
    FOR(i,1,n)
        scanf("%d%d",&p[1][i].x,&p[1][i].y),p[1][i].idx = n+i;

    FOR(i,1,n)
    {
        o.y = p[0][i].y;
        o.x = p[0][i].x;
        o.idx = i;
        FOR(j,1,n) g[j] = p[1][j]
        sort(p[1]+1,p[1]+1+n,mycmp);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

