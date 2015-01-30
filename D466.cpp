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

const int cmod = 1000000007;
const int maxn = 2000 + 10;
int a[maxn];
int j;
int m,n,h;
long long F[maxn][maxn];

int main()
{
    //freopen("D466.inp","r",stdin);
    //freopen("D466.out","w",stdout);
    scanf("%d%d",&n,&h);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        a[i] = h - a[i];
        m = max(m, a[i]);
    }
    F[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            if (a[i + 1] == j)
            {
                F[i + 1][a[i + 1]] = (F[i + 1][a[i + 1]] + F[i][j]) % cmod;
                F[i + 1][a[i + 1]] = (F[i + 1][a[i + 1]] + F[i][j] * j) % cmod;
            }
            if (a[i + 1] == j - 1)
            {
                F[i + 1][a[i + 1]] = (F[i+1][a[i + 1]] + F[i][j] * j) % cmod;
            }
            if (a[i + 1] == j + 1)
            {
                F[i + 1][a[i + 1]] = (F[i+1][a[i + 1]] + F[i][j]) % cmod;
            }
        }
    }
    cout<<F[n][1] + F[n][0]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

