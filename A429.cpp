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
vector<int> res,a[maxn];
bool freex[maxn];
int init[maxn],n,u,v;
int goal[maxn];

void DFS(int u,int d0,int d1,int depth)
{
    int c = 0;
    freex[u] = true;
    int bit = init[u];
    if (depth % 2 == 0) bit = bit ^ d0;
    if (depth % 2 == 1) bit = bit ^ d1;
    if (bit != goal[u])
    {
        if (depth % 2 == 0) d0 = d0 ^ 1;
        if (depth % 2 == 1) d1 = d1 ^ 1;
        res.push_back(u);
    }
    FOREACH(it,a[u])
    {
        int v = (*it);
        if (freex[v] == false)
            DFS(v,d0,d1,depth + 1);
    }
}

int main()
{
    //freopen("A429.inp","r",stdin);
    //freopen("A429.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n -1; i++)
    {
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) scanf("%d",&init[i]);
    for (int i = 1; i <= n; i++) scanf("%d",&goal[i]);
    memset(freex,false,sizeof(freex));
    DFS(1,0,0,0);
    sort(res.begin(),res.end());
    printf("%d\n",res.size());
    for (int i = 0; i < res.size(); i++)
        printf("%d\n",res[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

