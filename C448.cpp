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

const int maxn = 5000+10;
int a[maxn];
int c[maxn][maxn],d[maxn][maxn];
int l[maxn*maxn],r[maxn*maxn];
int u,n,cnt;
int newn;
int res;
bool vis[maxn*maxn];

int rec(int u, int h = 0)
{
    if (vis[u] == false)
        vis[u] = true;
    else
        return 0;
    int s = 0;
    int s2 = 0;
    for (int i = l[u]; i <= r[u]; i++)
    {
        int v = d[h+1][i];
        if (v > 0)
        s2+= rec(v,h+1);
    }
    return min(r[u] - l[u] + 1, (u != cnt) + s2);
}


int main()
{
//    freopen("C448.inp","r",stdin);
//    freopen("","w",stdout);
    scanf("%d",&n);
    newn = 0;
    res = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&u);
        if (u <= n)
        {
            a[++newn] = u;
        }
        else res++;
    }
    n = newn;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= a[j]; i++)
        {
            c[i][j] = 1;
        }
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (c[i][j] != c[i][j-1] && c[i][j] == 1)
                {
                    d[i][j] = ++cnt;
                    l[d[i][j]] = j;
                    r[d[i][j]] = j;
                }
            if (c[i][j] == c[i][j-1] && c[i][j] == 1)
                {
                    d[i][j] = d[i][j-1];
                    r[d[i][j]] = j;
                }
        }
    }
    ++cnt;
    for (int j = 1; j <= n; j++)
    {
        d[0][j] = cnt;
    }
    r[cnt] = n;
    l[cnt] = 1;
    cout<<res+rec(cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

