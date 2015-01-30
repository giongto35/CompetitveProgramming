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
const int maxm=20;
const int maxn = 1000001;
const int cmod = 1000000007;
const int maxb = 1 << maxm;
int a[maxn];
int sl;
int F[maxb][maxm];
int M2[maxn];
int n,m,i,j,v;
long long res;

void process()
{
    mb = (1 << m) - 1;
    M2[0] = 1;
    for (int i = 1; i <= n; i++)
        M2[i] = (M2[i-1] * 2) % cmod;
    for (int i = 0; i <=mb; i++)
    {
        dau = 0;
        for (int j = 0; j <= m - 1; j++)
        {
            if ((i >> j) & 1)
                F[i]
            F[i][j+1] = F[i][j+1] + F[i][j];
        }
    }
}

int main()
{
    freopen("D449.inp","r",stdin);
    freopen("D449.out","w",stdout);
    scanf("%d",&n);
    int m = 20;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&u);
        for (int j = 0; j < m; j++
        F[u][0]++;
    }
    process();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

