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
unsigned long long oo = 2100000000000000000ll;
const int maxn = 100+10;
unsigned long long n,m,bt;
unsigned long long F[3][(1<<20)+10];
//long long c[maxn];
unsigned long long d[maxn];
//long long bi[maxn];
unsigned long long mi,u,res;
struct trip
{
    unsigned long long x;
    unsigned long long k;
    unsigned long long b;
} t[maxn];

bool mycmp(trip u, trip v)
{
    return u.k < v.k;
}

int main()
{
    //freopen("B418.inp","r",stdin);
    //freopen("B418.out","w",stdout);
    scanf("%d%d%d",&n,&m,&bt);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d",&t[i].x,&t[i].k,&mi);
        for (int j = 1; j <= mi; j++)
        {
            scanf("%d",&u);
            t[i].b |= 1<<(u-1);
        }
    }
    sort(t+1,t+1+n,mycmp);
    res = oo;
    int mb = (1 << m) - 1;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= mb; j++)
            F[i][j] = oo;
    F[0][0] = 0;

    for (int ii = 0; ii < n; ii++)
    {
        int i = ii & 1;
        for (int j = 0; j <= mb; j++)
            F[1-i][j] = oo;
        for (int j = 0; j <= mb; j++)
        {
            if (F[i][j] < oo)
            {
                F[1-i][j] = min(F[1-i][j],F[i][j]);
                F[1-i][j | (t[ii+1].b)] = min(F[1-i][j | (t[ii+1].b)],F[i][j] + t[ii+1].x);
            }
        }
        if (F[1-i][mb] < oo)
            res = min(res,F[1-i][mb] + t[ii+1].k * bt);
    }

    if (res >= oo) cout<<-1; else
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

