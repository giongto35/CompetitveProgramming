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

const int maxn = 2000000+20;
vector<int> ke[maxn];
vector<int> tin, tout;
vector < vector<int> > up;
int n;
int q;
int l;
int qu[maxn];
int s[maxn];
int d[maxn];
int u,v;
int timer;
int p;

void dfs (int v,int p = 1) {
	tin[v] = ++timer;

	up[v][0] = p;

	for (int i=1; i<=l; ++i)
    {
        up[v][i] = up[up[v][i-1]][i-1];
    }
	for (size_t i=0; i<ke[v].size(); ++i) {
		d[ke[v][i]] = d[v] + 1;
        dfs (ke[v][i],v);
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i=l; i>=0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

int dist(int u,int v)
{
    return d[u] + d[v] - 2 * d[lca(u,v)];
}

int main()
{
    //freopen("F379.inp","r",stdin);
    //freopen("F379.out","w",stdout);
    n = 4;
    ke[1].push_back(2);
    ke[1].push_back(3);
    ke[1].push_back(4);
    scanf("%d",&q);
    FOR(i,1,q)
    {
        scanf("%d",&qu[i]);
        ke[qu[i]].push_back(n+1);
        ke[qu[i]].push_back(n+2);
        s[i] = n + 1;
        n+=2;
    }
        tin.resize (n+1),  tout.resize (n+1),  up.resize (n+1);
        l = 1;
        while ((1<<l) <= n)  ++l;
        FOR(i,1,n) up[i].resize (l+1);
        up[1][0]=-1;
        dfs (1);
    u = 2;
    v = 3;
    FOR(i,1,q)
    {
        int d1 = dist(u,v);
        int d2 = dist(u,s[i]);
        int d3 = dist(v,s[i]);
        if (d1 < max(d2,d3))
        {
            if (d2 > d3)
                v = s[i];
            else
                u = s[i];
        }
        printf("%d\n",dist(u,v));
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}

