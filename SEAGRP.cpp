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

const int maxn = 100+10;
set<int> ke[maxn];
set<int> r;
int n,m;
int u,v,T;
bool vis[maxn];
int cnt;

void DFS(int u)
{
	vis[u] = true;
	cnt ++;
	FOREACH(it,ke[u])
	{
		if (vis[*it]==false)
		DFS(*it);
	}
}

bool process()
{
	if (n % 2 == 1) return false;
	while (true)
	{
	    bool ok = false;
		FOREACH(it2,r)
		{
			int i = (*it2);
			if (ke[i].size() == 1)
			{
                ok = true;
				int u = i;
				FOREACH(it,ke[u])
				{
					int v = (*it);
					ke[v].erase(u);
				}
				r.erase(u);

				u = *ke[i].begin();
				FOREACH(it,ke[u])
				{
					int v = (*it);
					ke[v].erase(u);
				}
				r.erase(u);
				break;
			}
		}
		if (ok== false) break;
	}
	if (r.size() % 2 == 1) return false;
	memset(vis,false,sizeof(vis));
	FOREACH(it,r)
	{
		int u = (*it);

		if (vis[u])
		{
			cnt = 0;
			DFS(u);
			if (cnt % 2 != 0) return false;
		}

	}
	return true;

}

int main()
{
    freopen("SEAGRP.inp","r",stdin);
    //freopen("SEAGRP.out","w",stdout);
    scanf("%d",&T);
    FOR(sT,1,T)
    {
    	scanf("%d%d",&n,&m);
    	r.clear();
    	FOR(i,1,n) ke[i].clear(),r.insert(i);
    	FOR(i,1,m)
    	{
    		scanf("%d%d",&u,&v);
    		ke[u].insert(v);
    		ke[v].insert(u);
    	}
	    if (process() == true) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
