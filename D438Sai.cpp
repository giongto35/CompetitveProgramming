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
int a[maxn];
struct s_compare{
    bool operator()(const int &u,const int &v)const{
        return (a[u] > a[v])||((a[u] == a[v]) && (u > v));
    }
};

set<int,s_compare> s;
long long BIT[maxn];
int n,m,t;
int u,v,x;

void update(int i,int gt)//change long long
{
    while (i<=n)
    {
        BIT[i]=BIT[i] + gt;
        i=i+(i & (-i));
    }
}


long long get(int i)
{
    long long gt=0;//change long long
    while (i>=1)
    {
        gt=BIT[i] + gt;
        i=i-(i & (-i));
    }
    return gt;
}

int main()
{
    freopen("D438.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        update(i,a[i]);
        s.insert(i);
    }

    for(int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++) cout<<a[j]<<' ';
        cout<<endl;
        scanf("%d",&t);
        if (t == 1)
        {
            scanf("%d%d",&u,&v);
            printf("%I64d\n",get(v) - get(u-1));
        }
        if (t == 2)
        {
            scanf("%d%d%d",&u,&v,&x);
            while(true)
            {
                int u = *s.begin();
                if (a[u] >= x)
                {
                    update(u,-a[u]);
                    s.erase(u);
                    a[u] %= x;
                    s.insert(u);
                    update(u,a[u]);
                }
                else break;
            }
        }
        if (t == 3)
        {
            scanf("%d%d",&u,&v);
            update(u,-a[u]);
            s.erase(u);
            a[u] = v;
            s.insert(u);
            update(u,a[u]);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

