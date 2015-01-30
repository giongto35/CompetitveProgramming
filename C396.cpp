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
const int cmod = 1000000007 ;
const int maxn = 3*100000+10;
struct intervalNode
{
    int sum1;
    int sum2;
    int valsum1;
    int valsum2;
}IT[maxn * 4];
int p[maxn];
vector<int> a[maxn];
int cnt;
int com;
int h[maxn];
int S[maxn],E[maxn];
int pv,x,k;
int s1,s2;
int sq;
int n;
void DFS(int u)
{
    cnt++;
    S[u] = cnt;
    FOREACH(v,a[u])
    {
        h[*v] = h[u] + 1;
        DFS(*v);
    }
    E[u] = cnt;
}

void extract(int node)
{
    if (IT[node].valsum1 != 0)
    {
        IT[node * 2].valsum1 = (IT[node * 2].valsum1 + IT[node].valsum1) % cmod;
        IT[node * 2].sum1 = (IT[node * 2].sum1 + IT[node].valsum1) % cmod;
        IT[node * 2 + 1].valsum1 = (IT[node * 2 + 1].valsum1 + IT[node].valsum1) % cmod;
        IT[node * 2 + 1].sum1 = (IT[node * 2 + 1].sum1 + IT[node].valsum1) % cmod;
        IT[node].valsum1 = 0;
    }
    if (IT[node].valsum2 != 0)
    {
        IT[node * 2].valsum2 = (IT[node * 2].valsum2 + IT[node].valsum2) % cmod;
        IT[node * 2].sum2 = (IT[node * 2].sum2 + IT[node].valsum2) % cmod;
        IT[node * 2 + 1].valsum2 = (IT[node * 2 + 1].valsum2 + IT[node].valsum2) % cmod;
        IT[node * 2 + 1].sum2 = (IT[node * 2 + 1].sum2 + IT[node].valsum2) % cmod;
        IT[node].valsum2 = 0;
    }
}

void update(int node,int l,int r,int u,int v)
{
    if (r < u || l > v) return;
    if (u <= l && r <= v)
    {
        IT[node].sum1 = ((long long)IT[node].sum1 + x + (long long)h[pv] * k) % cmod;
        IT[node].valsum1 = ((long long)IT[node].valsum1 + x + (long long)h[pv] * k) % cmod;
        IT[node].sum2 = (IT[node].sum2 + k) % cmod;
        IT[node].valsum2 = (IT[node].valsum2 + k) % cmod;
        return ;
    }
    extract(node);
    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v);
    update(node * 2 + 1, mid + 1, r, u, v);
}

void get(int node, int l, int r, int u)
{
    if (r < u || l > u) return;
    if (l == u && r == u)
    {
        s1 = IT[node].sum1;
        s2 = IT[node].sum2;
        return ;
    }
    extract(node);
    int mid = (l + r) / 2;
    get(node * 2, l, mid, u);
    get(node * 2 + 1, mid + 1, r, u);
}

int main()
{
    //freopen("C396.inp","r",stdin);
    //freopen("C396.out","w",stdout);
    scanf("%d",&n);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d",&p[i]);
        a[p[i]].push_back(i);
    }
    DFS(1);
    scanf("%d",&sq);
    for (int i = 1; i <= sq; i++)
    {
        scanf("%d",&com);
        if (com == 1)
        {
            scanf("%d%d%d",&pv,&x,&k);
            update(1,1,n,S[pv],E[pv]);
        }
        else
        {
            scanf("%d",&pv);
            s1 = 0;
            s2 = 0;
            get(1,1,n,S[pv]);
            long long res = (s1 - (long long)h[pv] * s2) % cmod;
            printf("%d\n",(res + cmod) % cmod);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

