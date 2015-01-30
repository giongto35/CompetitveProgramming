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

const int maxn = 100000+10;
const int cmod = 1000000007;
vector<int> a[maxn];
int c[maxn];
int u;
long long F[maxn][2];
long long fr[maxn];
long long re[maxn];
int n;

void DFS(int u)
{
    if (a[u].size() == 0)
    {
        if (c[u] == 1)
        {
            F[u][c[u]] = 1;
            F[u][0] = 1;
        }
        else
            F[u][0] = 1;
        return;
    }
    for (int i = 0; i < a[u].size(); i++)
    {
        DFS(a[u][i]);
    }
    if (c[u] == 1)
    {
        F[u][1] = 1;
        for (int i = 0; i < a[u].size(); i++)
        {
            F[u][1] = (F[u][1] * F[a[u][i]][0]) % cmod;
        }
        F[u][0] = F[u][1];
    }
    else
    {
        fr[0] = F[a[u][0]][0];
        int m = a[u].size();
        for (int i = 1; i < m; i++)
        {
            fr[i] = (fr[i-1] * F[a[u][i]][0]) % cmod;
        }
        re[m - 1] = F[a[u][m-1]][0];
        for (int i = m-2; i >= 0; i--)
        {
            re[i] = (re[i+1] * F[a[u][i]][0]) % cmod;
        }
        for (int i = 0; i < m; i++)
        {
            long long r = 1;
            if (i - 1 >= 0) r = (r * fr[i-1]) % cmod;
            if (i + 1 < m)  r = (r * re[i+1]) % cmod;
            F[u][1] = (F[u][1] + (r * F[a[u][i]][1]) % cmod) % cmod;
        }
        F[u][0] = (fr[m-1] + F[u][1]) % cmod;
    }
}
int main()
{
    //freopen("B461.inp","r",stdin);
    //freopen("B461.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n-1; i++)
    {
        scanf("%d",&u);
        a[u].push_back(i);
    }
    for (int i = 0; i <= n-1; i++)
        scanf("%d", &c[i]);
    memset(F,0,sizeof(F));
    DFS(0);
    //cout<<F[1][1]<<' '<<F[8][0]<<endl;
    //cout<<F[8][1]<<' '<<F[1][0]<<endl;
    cout<<F[0][1]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

