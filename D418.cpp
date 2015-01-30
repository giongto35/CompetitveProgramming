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
#include <ctime>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#define FOREACH(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it ++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define DOW(i, b, a) for(int i = (b), _a = (a); i >= _a; i --)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define DEP(i, n) DOW(i, (n) - 1, 0)
#define all(a) (a).begin(), (a).end()
#define pb(a, b) (a).push_back((b))

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long int64;
template<class T> inline int size(const T&c)
{
	return c.size();
}

int n, q, lgn;
vector<int> a[100010], b1[100010], b2[100010]; // b1[u][i]: Trong so canh la con xa nhat cua U khong thuoc nhanh [u][i]
											// b2[u][i]: Trong so canh la gia tri l[v]-2*l[u] voi v khong thuoc nhanh [u][i]
int f[100010][20], f1[100010][30], f2[100010][30]; // f: Quy hoach dong LCA
												//f1: Quy hoach dong canh b1 theo LCA
												//f2: Quy hoach dong canh b2 theo LCA
int l[100010], fd[100010]; // l[u]: Do sau cua dinh u
						 // fd[u]: Con xa nhat cua dinh u

inline bool cmp(int a, int b)
{
	return fd[a] > fd[b];
}

void dfs(int u, int pr, int lv)
{
	l[u] = lv;
	fd[u] = lv;
	f[u][0] = pr;
	for(int i = 0; i < a[u].size(); i++)
	{
		while (a[u].size() > i && a[u][i] == pr)
		{
			a[u][i] = a[u][a[u].size()-1];
			a[u].pop_back();
			b1[u].pop_back();
			b2[u].pop_back();
		}
		if (i < a[u].size())
		{
			dfs(a[u][i], u, lv+1);
			fd[u] = max(fd[u], fd[a[u][i]]);
		}
	}

	if (a[u].size() == 0)
		return;
	if (a[u].size() == 1)
	{
		b1[u][0] = lv;
		b2[u][0] = -lv;
	}
	else
	{
		sort(a[u].begin(), a[u].end(), cmp);
		REP(i, a[u].size())
		{
			if (i == 0)
				b1[u][i] = fd[a[u][1]];
			else
				b1[u][i] = fd[a[u][0]];
			b2[u][i] = b1[u][i]-2*lv;
		}
	}
	REP(i, a[u].size())
	{
		f1[a[u][i]][0] = b1[u][i];
		f2[a[u][i]][0] = b2[u][i];
	}
}

inline void init()
{
	memset(f, 0, sizeof f);
	memset(f1, 0, sizeof f1);
	//lgn = 1+int(log(n)/log(2)+1e-8);
	lgn=19;
	FOR(j, 0, lgn)
		f2[0][j] = -1e9;
	dfs(1, 0, 1);
	FOR(j, 1, lgn)
		FOR(i, 1, n)
		{
			f[i][j] = f[f[i][j-1]][j-1];
			f1[i][j] = max(f1[i][j-1], f1[f[i][j-1]][j-1]);
			f2[i][j] = max(f2[i][j-1], f2[f[i][j-1]][j-1]);
		}
}

inline int getLCA(int u, int v)
{
	DOW(j, lgn, 0)
		if (f[v][j] != 0 && l[f[v][j]] >= l[u])
			v = f[v][j];
	if (u == v)
		return u;
	DOW(j, lgn, 0)
		if (f[u][j] != f[v][j] && f[u][j] != 0 && f[v][j] != 0)
		{
			u = f[u][j];
			v = f[v][j];
		}
	return f[u][0];
}

inline int getAncestor(int u, int lv)
{
	DOW(j, lgn, 0)
		if (f[u][j] != 0 && l[f[u][j]] >= lv)
			u = f[u][j];
	return u;
}

inline int getMax1(int u, int v) // U la cha cua V
{
	int ret = -1e9;
	DOW(i, lgn , 0)
		if (f[v][i] != 0 && l[f[v][i]] >= l[u])
		{
			ret = max(ret, f1[v][i]);
			v = f[v][i];
		}
	return ret;
}

inline int getMax2(int u, int v) // U la cha cua V
{
	int ret = -1e9;
	DOW(i, lgn , 0)
		if (f[v][i] != 0 && l[f[v][i]] >= l[u])
		{
			ret = max(ret, f2[v][i]);
			v = f[v][i];
		}
	return ret;
}

inline int getQuery(int u, int v)
{
	if (u == v)
	{
		return max(getMax2(1, u)+l[u], fd[u]-l[u]);
	}
	int lca = getLCA(u, v);
	int len = l[v]+l[u]-2*l[lca];
	int midpoint = getAncestor(v, l[v]-len/2);
	int ret = 0;
	if (lca != u)
	{
		int uu = getAncestor(u, l[lca]+1);
		int vv = getAncestor(v, l[lca]+1);
		if (midpoint == lca)
			ret = max(getMax2(uu, u)+l[u], getMax2(vv, v)+l[v]);
		else
		{
			ret = max(getMax2(uu, u)+l[u], getMax2(midpoint, v)+l[v]);
			ret = max(ret, getMax1(vv, midpoint)+l[u]-l[lca]*2);
		}
		ret = max(ret, max(fd[u]-l[u], fd[v]-l[v]));
		ret = max(ret, l[u]+getMax2(1, lca));
		REP(i, a[lca].size())
			if (a[lca][i] != uu && a[lca][i] != vv)
			{
				ret = max(ret, l[u]+fd[a[lca][i]]-2*l[lca]);
				break;
			}
	}
	else
	{
		ret = max(getMax2(1, u)+l[u], fd[v]-l[v]);
		ret = max(ret, max(getMax1(u, midpoint)-l[u], getMax2(midpoint, v)+l[v]));
	}
	return ret;
}

int main()
{
	//freopen("D418.inp", "r", stdin);
	//freopen("o.txt", "w", stdout);
	//
		scanf("%d", &n);
		FOR(i, 1, n)
		{
			a[i].clear();
			b1[i].clear();
			b2[i].clear();
		}
		FOR(i, 1, n-1)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			pb(a[u], v);
			pb(a[v], u);
			pb(b1[u], 0);
			pb(b1[v], 0);
			pb(b2[u], 0);
			pb(b2[v], 0);
		}
		//
		init();
		int q;
		scanf("%d", &q);
		FOR(i, 1, q)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			if (l[u] > l[v])
				swap(u, v);
			printf("%d\n", getQuery(u, v));
		}
	return 0;
}
