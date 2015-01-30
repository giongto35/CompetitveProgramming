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

int sT;
int T;
int W,H,B;
const int maxn = 1000+10;
int a[200][600];
int x1[maxn],y1[maxn],x2[maxn],y2[maxn];

void swap(int &u,int &v)
{
    int tg=u;u=v;v=tg;
}

bool findF() {
    //RESET(tra, 0);
    memset(tra,0,sizeof(tra));
    fir=0, las=0;
    q[0]=s; tra[s]=-1;
    while (fir<=las) {
        int u=q[fir]; fir++;
        FOREACH(i, ke[u])
        {
            if (tra[e[*i].y]==0 && cf(*i)>0) {
                tra[e[*i].y]=*i;
                las++, q[las]=e[*i].y;
                if (q[las]==t) return true;
            }
        }
    }
    return false;
}
void IncFlow() {
    int u=t, delta=oo, i;
    while (u!=s) {
        i=tra[u];
        delta=min(delta, cf(i));
        u=e[i].x;
    }
    res+=delta;
    u=t;
    while (u!=s) {
        i=tra[u];
        e[i].f+=delta;
        if (i<=m) e[i+m].f-=delta; else e[i-m].f-=delta;
        u=e[i].x;
    }
}

int main()
{
    freopen("CCJ2.inp","r",stdin);
    freopen("CCJ2.out","w",stdout);
    scanf("%d",&T);
    for (int sT = 1; sT <= T; sT++)
    {
        scanf("%d%d%d",&W,&H,&B);
        for (int i = 1; i <= B; i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
            {
                a[y][x] = 1;
            }
        }
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[y][x] == 0)
            {

            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

