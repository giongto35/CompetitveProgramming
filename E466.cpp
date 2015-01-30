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
struct query
{
    int t;
    int x;
    int y;
} q[maxn];
int n,m;
int cnt;
int in[maxn];
int out[maxn];
int par[maxn];
vector<int> ke[maxn];
int lab[maxn];
vector<pair<int,int> > pack;

int getroot(int u)
{
    if (lab[u] == -1) return u;
    lab[u] = getroot(lab[u]);
    return lab[u];
}

void DFS(int u)
{
    cnt++;
    in[u] = cnt;
    for (int i = 0; i < ke[u].size(); i++)
    {
        DFS(ke[u][i]);
    }
    cnt++;
    out[u] = cnt;
}

int main()
{
    //freopen("E466.inp","r",stdin);
    //freopen("E466.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d",&q[i].t);
        if (q[i].t == 1 || q[i].t == 3)
        {
            scanf("%d%d",&q[i].x,&q[i].y);
            if (q[i].t == 1)
            {
                par[q[i].x] = q[i].y;
                ke[q[i].y].push_back(q[i].x);
            }
        }
        if (q[i].t == 2) scanf("%d",&q[i].x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == 0)
        {
            DFS(i);
        }
    }
    for (int i = 1; i <= n; i++) lab[i] = -1;
    for (int i = 1; i <= m; i++)
    {
        if (q[i].t == 1)
        {
            lab[q[i].x] = q[i].y;
        }
        if (q[i].t == 2)
        {
            pack.push_back(make_pair(q[i].x, getroot(q[i].x)));
        }
        if (q[i].t == 3)
        {
            int u = q[i].x;
            int c = pack[q[i].y - 1].first;
            int p = pack[q[i].y - 1].second;
            //cout<<p<<' '<<c<<' '<<u<<' '<<in[p]<<' '<<in[u]<<' '<<in[c]<<' '<<out[p]<<' '<<out[u]<<' '<<out[c]<<endl;
            //cout<<p<<' '<<c<<' '<<u<<endl;
            if (in[p] <= in[u] && out[p] >= out[u] && in[c] >= in[u] && out[c] <= out[u])
            {
                printf("YES\n");
            }
            else
                printf("NO\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

