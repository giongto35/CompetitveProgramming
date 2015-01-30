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

const int maxn = 3*100000+10;
int a[maxn];
int b[maxn];
map<int,int> cnt[maxn];
//set<int> c[maxn];
vector<int> c[maxn];
int S[maxn];
int u,v;
int tg,n,p;
int BIT[maxn];
long long res;

void update(int i,int gt)
{
    i++;
    //if (i <= 0) return;
    while (i<=n+1)
    {
        BIT[i]=BIT[i] + gt;
        i=i+(i & (-i));
    }
}

int get(int i)
{
    int gt=0;
    //if (i > n) i = n;
    i++;
    while (i>=1)
    {
        gt = gt + BIT[i];
        i=i-(i & (-i));
    }
    return gt;
}

int main()
{
    //freopen("C420.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",&u,&v);
        if (u > v)
        {
            tg = u;
            u = v;
            v = tg;
        }
        if (cnt[u][v] == 0)
        c[u].push_back(v);
        cnt[u][v] ++;
        S[u]++;
        S[v]++;
    }
    for (int i = 1; i <= n; i++)
        update(S[i],+1);
    for (int i = 1; i <= n; i++)
    {
        update(S[i],-1);
        FOREACH(it,c[i])
        {
            int u = (*it);
            //cout<<i<<' '<<u<<' '<<S[i] <<' '<<S[u]<<' '<<cnt[i][u]<<endl;
            if (S[i] + S[u] - cnt[i][u] >= p)
            res++;
            update(S[u],-1);
        }
        res = res + (long long)get(n) - (long long)get(p-S[i]-1);
        FOREACH(it,c[i])
        {
            int u = (*it);
            update(S[u],1);
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

