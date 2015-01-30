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

const int maxn = 2000+10;
int a[maxn][maxn];
bool vis[maxn];
int n;
vector<int> sortednode;

void dfs1(int x)
{
	vis[x] = true;
	for (int u = 1; u <= n; u++)
		if (!vis[u] && a[x][u] == 1) dfs1(u);
	sortednode.push_back(x);
}

void dfs2(int x, int c)
{
	vis[x] = false;
	for (int u = 1; u <= n; u++)
		if (vis[u] && a[u][x] == 1) dfs2(u,c);
}

int main()
{
    //freopen("C403.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= n; j++)
    		{
    			scanf("%d",&a[i][j]);
    			a[i][j] = (a[i][j] > 0);
    		}
    for (int i = 1; i <= n; i++)
    	if (!vis[i]) dfs1(i);
    int c = 0;
    for (int i = (int)sortednode.size() - 1; i >= 0; i--)
    {
    	if (vis[sortednode[i]])
    		dfs2(sortednode[i],++c);
    }
    if (c > 1)
    	cout<<"NO";
   	else
   		cout<<"YES";

    fclose(stdin);
    fclose(stdout);
    return 0;
}
