//gaussian elimination
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
int n;
const int maxn = 100+10;
long long a[maxn][maxn];
int TC,m,u,v;

int pow(int u, int n)
{
    if (n == 0) return 1;
    if (n % 2 == 1) return ((long long)u * pow(u,n-1)) % cmod;
    else
    {
        int v = pow(u,n / 2);
        return ((long long)v * v) % cmod;
    }
}

long long modinverse(int u)
{
    return pow(u,cmod - 2);
}

void gaussian_elimination()
{
    int i,j,k;
    long long res = 1;
    for (int i = 1; i <= n; i++){
       int k = i;
       for (int j=i+1; j <= n; ++j)
          if (abs (a[j][i]) > abs (a[k][i]))  k = j;
       res = (res * a[i][i]) % cmod;

       for (int j = n; j >= i; j--)
          a[i][j] = (a[i][j] * modinverse(a[i][i])) % cmod;
       for (int j=i+1; j<=n; ++j)
         for (int k=n; k>=1; --k)
           a[j][k] = (a[j][k] - (a[i][k] * a[j][i]) % cmod) % cmod;

    }
    cout<<(res % cmod + cmod ) % cmod<<endl;
}

int main()
{
    //freopen("C7.inp","r",stdin);
    //freopen("C7.out","w",stdout);
    scanf("%d",&TC);
    while (TC > 0)
    {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d",&u,&v);
            a[u][v]--;
            a[v][u]--;
            a[u][u]++;
            a[v][v]++;
        }
        TC--;
        n--;

        gaussian_elimination();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

