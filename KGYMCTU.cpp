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

const int maxn = 150+10;
int a[maxn][maxn];
vector<int> p;
bool par[maxn][maxn];
int n;
int main()
{
    //freopen("KGYMCTU.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        scanf("%d",&a[i][j]);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
        if (a[i][j] == i && i != j) par[i][j] = true;
        if (a[i][j] == j && i != j) par[j][i] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        p.clear();
        for (int j = 1; j <= n; j++)
        {
            if (par[j][i] && j != i) p.push_back(j);
        }
        int res = 0;
        for (int j = 0; j < p.size(); j++)
        {
            int u = p[j];
            bool ok = true;
            for (int k = 0; k < p.size(); k++)
            {
                int v = p[k];
                if (par[u][v]) ok = false;
            }
            if (ok) {
                res = u;
                break;
            }
        }
        cout<<res<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

