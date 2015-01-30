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

const int maxn = 10000+10;
vector<pair<int,int > > ke[maxn];
int cnt[maxn];
long long s[maxn];
long long res;
int T,n,u,v,l;
bool vis[maxn];
pair<int,int> par[maxn];
long long G[maxn];

void DFS(int u)
{
    vis[u] = true;
    cnt[u] = 1;
    //cout<<u<<' '<<sum<<endl;
    for (int i = 0; i < ke[u].size(); i++)
    {
        if (vis[ke[u][i].first] == false)
        {
            //cout<<"ABC "<<ke[u][i].second<<endl;
            par[ke[u][i].first] = make_pair(u, ke[u][i].second);
            DFS(ke[u][i].first);
            //suml+=ke[u][i].second;
            s[u] = s[u] + s[ke[u][i].first] + ke[u][i].second * cnt[ke[u][i].first];
            cnt[u] = cnt[u] + cnt[ke[u][i].first];
        }
    }
    res = res + s[u];
}

void DFS2(int u )
{
    if (par[u].first != -1)
    {
        //if (u==3)
            //cout<<"ABC "<<s[par[u].first]<<' '<<s[u]<<' '<<par[u].second<<' '<<s[par[u].first] - s[u] - par[u].second<<' '<<cnt[u]<<' '<<par[u].second<<endl;
        G[u] = G[par[u].first] + (s[par[u].first] - s[u] - par[u].second * cnt[u]) + (n - cnt[u]) * par[u].second;
    }
    //cout<<u<<' '<<G[u]<<endl;
    res = res + G[u];
    for (int i = 0; i < ke[u].size(); i++)
    {
        if (ke[u][i].first != par[u].first)
            DFS2(ke[u][i].first);
    }
}

int main()
{
    //freopen("AGYM6.inp","r",stdin);
    //freopen("AGYM6.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i = 0; i <= n; i++) ke[i].clear();
        memset(s,0,sizeof(s));
        memset(G,0,sizeof(G));
        memset(cnt,0,sizeof(cnt));
        memset(vis,false,sizeof(vis));
        memset(par,0,sizeof(par));
        res = 0;
        par[0].first = -1;
        for (int i = 1; i <= n - 1; i ++)
        {
            scanf("%d%d%d",&u,&v,&l);
            ke[u].push_back(make_pair(v,l));
            ke[v].push_back(make_pair(u,l));

        }
        DFS(0);
        DFS2(0);
        long long d = ((double) n * (n - 1));
        //cout<<res<<' '<<d<<endl;
        printf("%0.6f\n", (res + 0.0)/ d );
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

