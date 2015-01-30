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
vector<int> a[maxn];
int n,m,u,v;

struct cmp
{
    bool operator()(int u, int v)
    {
        return a[u].size() < a[v].size();
    }
};

set<int,cmp> root;
set<int,cmp> c[maxn];
struct triple
{
    int d1;
    int d2;
    int d3;
    triple(int u,int v,int c)
    {
        d1 =u;
        d2 = v;
        d3 = c;
    }
};
vector<triple> res;
int main()
{
    freopen("C406.inp","r",stdin);
    //freopen("C406.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        root.insert(i);
        for (int j = 0; j < (int )a[i].size(); j++)
            c[i].insert(a[i][j]);
    }
    while(root.size() > 0)
    {
        int u = *root.begin();
        root.erase(u);
        if (c[u].size() == 0) continue;
        set<int>::iterator it = c[u].begin();
        if (it != c[u].end())
        {
            int v = *it;
            c[v].erase(u);
            c[u].erase(v);
            set<int>::iterator it = c[v].begin();
            if (it != c[v].end())
            {
                int x = *it;
                c[x].erase(v);
                c[v].erase(x);
                printf("%d %d %d\n",u,v,x);
                res.push_back(triple(u,v,x));
            }
            else
            {
                cout<<"No solution"<<endl;
                return 0;
            }
        }
        else
        {
            cout<<"No solution"<<endl;
            return 0;
        }
        if (c[u].size() > 0) root.insert(u);
    }
    FOREACH(u,res)
    {
        printf("%d %d %d\n",(*u).d1,(*u).d2,(*u).d3);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

