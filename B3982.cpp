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

const int maxn = 2 * 1000+10;

double E[maxn][maxn];
double P[maxn][maxn];
int n,m;
int x,y;
bool r[maxn],c[maxn];
int sa,sb;
int main()
{
    freopen("B398.inp","r",stdin);
    //freopen("B398.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m ; i++)
    {
        scanf("%d%d",&x,&y);
        r[x] = true;
        c[y] = true;
    }
    sa = sb = n;
    for (int i = 1; i <= n; i++)
    {
        if (r[i]) sa--;
        if (c[i]) sb--;
    }
    P[sa][sb] = 1;
    E[sa][sb] = 0;
    for (int i = sa; i >= 0; i --)
    {
        for (int j = sb; j >= 0; j--)
        {
            if ( i == sa && j == sb) continue;
            P[i][j] =
             P[i+1][j] * ((i + 1 + 0.0) * (n - j) / (n * n))
            +P[i][j+1] * ((n - i + 0.0) * (j + 1) / (n * n))
            +P[i+1][j+1]*((i + 1 + 0.0) * (j + 1) / (n * n));
            double t = ( 1- (n - i + 0.0) * (n - j) / (n * n));
            if (i == 0 && j == 0) t = 1;
            P[i][j] = P[i][j] / t;

            E[i][j] =
             E[i+1][j] * ((i + 1 + 0.0) * (n - j) / (n * n)) + P[i+1][j]
            +E[i][j+1] * ((n - i + 0.0) * (j + 1) / (n * n)) + P[i][j+1]
            +E[i+1][j+1]*((i + 1 + 0.0) * (j + 1) / (n * n)) + P[i+1][j+1]
            + (i != 0 || j != 0) * P[i][j];
            E[i][j] = E[i][j] / t;
            cout<<i<<' '<<j<<' '<<P[i][j]<<' '<<E[i][j]<<' '<<t<<endl;
        }
    }
    cout<<E[0][0]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

