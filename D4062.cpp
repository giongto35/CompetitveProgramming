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

int n;
int x[maxn];
long long h[maxn];
int up[maxn][20];
vector<int> ke[maxn];
pair<long long,long long> a[maxn];
int st[maxn];
int top;
int tin[maxn],tout[maxn];
int timer;
int u,v,l,q;
int f[100010][21];
int level[100010];

void go(int u, int pr) {
 level[u] = level[pr]+1;
 f[u][0] = pr;
 for(int i = 1; i < 19; i++)
  f[u][i] = f[f[u][i-1]][i-1];
 for(int i = 0; i < ke[u].size(); i++) {
  int v = ke[u][i];
  if (v != pr) go(v, u);
 }
}

int lca(int u, int v) {
 if (level[u] > level[v]) swap(u, v);
 for(int i = 18; i >= 0; i--)
  if (level[f[v][i]] >= level[u])
   v = f[v][i];
 if (v == u) return v;
 for(int i = 18; i >= 0; i--)
  if (f[u][i] != f[v][i]) {
   u = f[u][i];
   v = f[v][i];
  }
 return f[u][0];
}

inline long long Cross(pair<long long, long long> p1, pair<long long, long long>  p2,pair<long long, long long>  p3) {
    long long a1 = p2.first-p1.first;
    long long b1 = p2.second-p1.second;
    long long a2 = p3.first-p2.first;
    long long b2 = p3.second-p2.second;
    return a1*b2 - a2*b1;
}

void preprocessing()
{
    //x[n+1] = x[n] + 1;
    //h[n+1] = 100000000100ll;
    top = 0;
    for (int i = n; i >= 1; i--)
    {
        //while (top >= 1 && h[st[top]] < h[i]) top --;
//        while (top >= 2 && Cross(make_pair(x[i],h[i]), make_pair(x[st[top-1]],h[st[top-1]]), make_pair(x[st[top]],h[st[top]])) < 0)
        while (top >= 2 && Cross(a[i], a[st[top-1]], a[st[top]]) < 0)
            top--;
        ke[st[top]].push_back(i);
        ke[i].push_back(st[top]);
        st[++top] = i;
    }
}


void dfs (int v, int p = 0) {
	tin[v] = ++timer;

	up[v][0] = p;

	for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

	for (size_t i=0; i<ke[v].size(); ++i) {
		int to = ke[v][i];
		if (to != p)
			dfs (to, v);
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

/*int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i=l; i>=0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}*/

int main()
{
    freopen("D406.inp","r",stdin);
    //freopen("D406.out","w",stdout);
    scanf("%d",&n);
    for (int i  = 1; i<= n; i++)
    {
        scanf("%I64d%I64d ",&a[i].first,&a[i].second);
    }
	l = 1;
	while ((1<<l) <= n)  ++l;
	FOR(i,1,n) ke[0].push_back(i);
    preprocessing();
	//dfs (0);
	go(0,0);
    scanf("%d",&q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d",&u,&v);

        printf("%d ",lca(u,v));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

