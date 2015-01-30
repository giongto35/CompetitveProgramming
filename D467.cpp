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

const int maxn = 200000+10;
char* ch;
string a[maxn],x,y;
int m,n;
map<string, int> ma;
pair<int, int> gt[maxn];
int cnt;
long long resR;
long long resL;
int numComp;
vector<int> ke[maxn],ker[maxn];
pair<int,int> F[maxn];
vector<bool> used;
vector<int> order, comp;
pair<int,int> mincomp[maxn];
vector<int> g[maxn];

int countR(const string &s)
{
    int res = 0;
    for (int i = 0; i < s.length(); i++)
        res += (s[i] == 'r');
    return res;
}

void dfs1 (int v) {
   used[v] = true;
   for (size_t i=0; i<ke[v].size(); ++i) {
      int to = ke[v][i];
      if (!used[to])
         dfs1 (to);
      }
      order.push_back (v);
}

void dfs2 (int v, int cl) {
   comp[v] = cl;
   mincomp[cl] = min(mincomp[cl], gt[v]);
   for (size_t i=0; i<ker[v].size(); ++i) {
      int to = ker[v][i];
      if (comp[to] == -1)
         dfs2 (to, cl);
      }
}

void rec(int u)
{
    used[u] = true;
    for (int i = 0; i < g[u].size(); i++)
    {
        if (used[g[u][i]] == false)
        {
            rec(g[u][i]);
        }
        mincomp[u] = min(mincomp[u], mincomp[g[u][i]]);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    //freopen("D467.inp","r",stdin);
    //freopen("D467.out","w",stdout);
    cin>>m;
    for (int i = 1; i <= m; i++)
    {
        cin>>a[i];
        std::transform(a[i].begin(), a[i].end(), a[i].begin(), ::tolower);
        /*if (ma.count(a[i]) == 0)
        {
            ma[a[i]] = ++cnt;
            gt[cnt] = make_pair(countR(a[i]), a[i].length());
        }*/
    }
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>x>>y;
        std::transform(x.begin(), x.end(), x.begin(), ::tolower);
        std::transform(y.begin(), y.end(), y.begin(), ::tolower);
        if (x == y) continue;
        if (ma.count(x) == 0)
        {
            ma[x] = ++cnt;
            gt[cnt] = make_pair(countR(x), x.length());
        }
        if (ma.count(y) == 0)
        {
            ma[y] = ++cnt;
            gt[cnt] = make_pair(countR(y), y.length());
        }
        ke[ma[x]].push_back(ma[y]);
        ker[ma[y]].push_back(ma[x]);
    }

    used.assign (cnt + 1, false);
    order.push_back(-1);
    for (int i = 1; i <= cnt; i++)
      if (!used[i])   dfs1 (i);
    comp.assign (cnt + 1, -1);
    numComp = 0;
    for (int i = 1; i <= cnt; ++i) {
      int v = order[cnt-i+1];
      if (comp[v] == -1)
      {
          ++numComp;
          mincomp[numComp] = make_pair(1000000000, 1000000000);
          dfs2 (v, numComp);
      }
    }
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 0; j < ke[i].size(); j++)
        {
            g[comp[i]].push_back(comp[ke[i][j]]);
        }
    }
    used.assign (numComp, false);
    for (int i = 1; i <= numComp; i++)
    {
        if (used[i] == false)
        rec(i);
    }
    for (int i = 1; i <= m; i++)
    {
        //cout<<a[i]<<' '<<ma[a[i]]<<' '<<comp[ma[a[i]]]<<endl;
        if (ma.count(a[i]) == 0)
        {
            resR += countR(a[i]);
            resL += a[i].length();
        }
        else
        {
            resR += mincomp[comp[ma[a[i]]]].first;
            resL += mincomp[comp[ma[a[i]]]].second;
        }
    }
    cout<<resR<<' '<<resL<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
