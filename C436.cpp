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

int n,m,k,w;
string a[1100][12];
struct edge
{
    int u;
    int v;
    int c;
} e[1100000];
int ne;
int res;
bool used[1100];
int lab[1100];
vector<int> ke[1100];

int getroot(int u)
{
    if (lab[u] == 0) return u;
    lab[u] = getroot(lab[u]);
    return lab[u];
}

bool mycmp(edge u, edge v)
{
    return u.c < v.c;
}

void DFS(int u)
{
    used[u] = true;
    for (int i = 0; i < ke[u].size(); i++)
    {
        if (used[ke[u][i]] == false){
        if (u == k+1)
        printf("%d %d\n",ke[u][i],0);
        else
        printf("%d %d\n",ke[u][i],u);
        DFS(ke[u][i]);
        }
    }
}

int main()
{
    //freopen("C436.inp","r",stdin);
    //freopen("C436.out","w",stdout);
    scanf("%d%d%d%d\n",&n,&m,&k,&w);
    for (int x = 1; x <= k; x++){
        for (int i = 0; i < n; i++)
        {
            getline(cin,a[x][i]);
        }
        ne++;
        e[ne].u = k+1;
        e[ne].v = x;
        e[ne].c = n * m;
    }
    for (int i = 1; i <= k; i++)
    for (int j = i+1; j <= k; j++)
    {
        int cnt = 0;
        for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            if (a[i][y][x] != a[j][y][x]) cnt += w;
        }
        ++ne;
        e[ne].u = i;
        e[ne].v = j;
        e[ne].c = cnt;
    }
    sort(e+1,e+1+ne,mycmp);
    res = 0;
    for (int i = 1; i <= ne; i++)
    {
        int u = e[i].u;
        int v = e[i].v;
        int r1 = getroot(u);
        int r2 = getroot(v);
        if (r1!=r2)
        {
            res+=e[i].c;
            lab[r1] = r2;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
    }
    cout<<res<<endl;
    DFS(k+1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

