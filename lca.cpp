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
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn = 100000+10;
int n, l;
vector < pair<int,int> > ke[maxn];
vector<int> tin, tout;
int timer;
vector < vector<int> > up;
int u,v,c,q;

void dfs (int v, int p = 1,int len = 0) {
	tin[v] = ++timer;

	up[v][0] = p;

	for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

	for (size_t i=0; i<ke[v].size(); ++i) {
		int to = ke[v][i].first;
		if (to != p)
			dfs (to, v, ke[v][i].second);
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

int main() {
    freopen("lubenica.inp","r",stdin);
    //freopen("lubenica.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n-1)
    {
        scanf("%d%d%d",&u,&v,&c);
        ke[u].push_back(make_pair(v,c));
        ke[v].push_back(make_pair(u,c));
    }
	tin.resize (n+1),  tout.resize (n+1),  up.resize (n+1);
	l = 1;
	while ((1<<l) <= n)  ++l;
	FOR(i,1,n) up[i].resize (l+1);
	dfs (1);
    scanf("%d",&q);
    FOR(i,1,q)
    {
        scanf("%d%d",&u,&v);
        cout<<lca(u,v)<<endl;
    }
	return 0;
}
