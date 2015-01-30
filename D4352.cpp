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

const int maxn = 400+10;
int n,m;
string st;
int a[maxn][maxn];
int b[maxn][maxn];
int l[maxn][maxn];
int u[maxn][maxn];
int d1[maxn][maxn];
int d2[maxn][maxn];
long long res;

int calc(int n, int m)
{
    memset(l,0,sizeof(l));
    memset(u,0,sizeof(l));
    memset(d1,0,sizeof(l));
    memset(d2,0,sizeof(l));
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        l[i][j] = l[i][j-1] + (a[i][j]);
        u[i][j] = u[i-1][j] + (a[i][j]);
        d1[i][j] = d1[i-1][j-1] + (a[i][j]);
        d2[i][j] = d2[i-1][j+1] + (a[i][j]);
        for (int k = 1; k <= min(i - 1,j - 1); k++)
        {
            int tl = j - k;
            int tu = i - k;
            if (l[i][j] - l[i][tl-1] >= 1) break;
            if (u[i][j] - u[tu-1][j] >= 1) break;
            if (d2[i][tl] - d2[tu-1][j+1] == 0)
            {
                //cout<<i<<' '<<j<<' '<<k<<endl;
                res++;
            }
        }
        for (int k = 1; k <= min(min(i -1,j-1),m-j); k++)
        {
            int tl = j - k;
            int tr = j + k;
            int tu = i - k;
            if (d1[i][j] - d1[tu-1][tl-1] >= 1) break;
            if (d2[i][j] - d2[tu-1][tr+1] >= 1) break;
            if (l[tu][tr] - l[tu][tl-1] == 0)
            {
                //cout<<i<<' '<<j<<' '<<k<<endl;
                res++;
            }
        }
    }
}

void rotation(int &n, int &m)
{
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        b[j][n-i+1] = a[i][j];
    swap(n,m);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        a[i][j] = b[i][j];
}
int main()
{
    //freopen("D435.inp","r",stdin);
    //freopen("D435.out","w",stdout);
    scanf("%d%d",&n,&m);
    getline(cin,st);
    for (int i = 1; i <= n; i++)
    {
        getline(cin,st);
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = st[j-1] - '0';
        }

    }
    res += calc(n,m);
    rotation(n,m);
    res += calc(n,m);
    rotation(n,m);
    res += calc(n,m);
    rotation(n,m);
    res += calc(n,m);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
