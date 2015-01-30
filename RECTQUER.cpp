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

const int maxn = 300+10;
const int maxq = 100000+10;
int a[maxn][maxn];
int b[maxn][maxn];
struct query
{
    int y1,x1,y2,x2;
} Q[maxq];
int res[maxq];
int n;
int sQ;

int get(int y1,int x1,int y2,int x2)
{
    return (b[y2][x2] - b[y2][x1-1] - b[y1-1][x2] + b[y1-1][x1-1]);
}
int main()
{
    //freopen("RECTQUER.inp","r",stdin);
    //freopen("RECTQUER.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n)
    FOR(j,1,n)
    scanf("%d",&a[i][j]);

    scanf("%d",&sQ);
    FOR(i,1,sQ)
        scanf("%d%d%d%d", &Q[i].y1,&Q[i].x1,&Q[i].y2,&Q[i].x2);
    FOR(x,1,10)
    {
        FOR(i,1,n)
        FOR(j,1,n)
        {
            b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + (a[i][j] == x);
        }
        FOR(i,1,sQ)
        {
            res[i] += (get(Q[i].y1,Q[i].x1,Q[i].y2,Q[i].x2) > 0);
        }
    }
    FOR(i,1,sQ) cout<<res[i]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

