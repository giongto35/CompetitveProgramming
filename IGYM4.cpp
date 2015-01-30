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

const int maxn = 300000+10;
const int maxtd = 100000+10;
struct kdl{
int x;
int y;
int v;
} a[maxn];
int F[maxn];
int tr[maxn];
int C[maxtd];
int R[maxtd];
int SX,SY,EX,EY;
int n,k;
vector<int> res;

bool mycmp(kdl a, kdl b)
{
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

void trace(int u)
{
    res.push_back(u);
    if (a[u].x == SX && a[u].y == SY) return;
    //cout<<u<<' '<<tr[u]<<endl;
    trace(tr[u]);
}

int main()
{
    //freopen("IGYM4.inp","r",stdin);
    //freopen("IGYM4.out","w",stdout);
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
    }
    SX = a[1].x;
    SY = a[1].y;
    EX = a[n].x;
    EY = a[n].y;
    sort(a+1,a+1+n,mycmp);
    for (int i = 1; i <= n; i++)
    {
        if (a[i].x == SX && a[i].y == SY)
        {
            F[i] = a[i].v;
            C[a[i].x] = i;
            R[a[i].y] = i;
            continue;
        }
        if (R[a[i].y] != 0 && F[R[a[i].y]] >= k)
        {
            if (F[i] < F[R[a[i].y]] - k + a[i].v)
            {
                F[i] = F[R[a[i].y]] - k + a[i].v;
                tr[i] = R[a[i].y];
            }
        }
        if (C[a[i].x] != 0 && F[C[a[i].x]] >= k)
        {
            if (F[i] < F[C[a[i].x]] - k + a[i].v)
            {
                F[i] = F[C[a[i].x]] - k + a[i].v;
                tr[i] = C[a[i].x];
            }
        }
        if (F[i] > 0)
        {
            if (R[a[i].y] == 0 || (R[a[i].y] != 0 && F[R[a[i].y]] < F[i])) R[a[i].y] = i;
            if (C[a[i].x] == 0 || (C[a[i].x] != 0 && F[C[a[i].x]] < F[i])) C[a[i].x] = i;
        }

        if (a[i].x == EX && a[i].y == EY)
        {
            //cout<<EX<<' '<<EY<<' '<<i<<endl;
            printf("%d\n", F[i]);
            trace(i);
            printf("%d\n", res.size());
            for (int k = res.size() - 1; k >= 0; k--)
            {
                printf("%d %d\n", a[res[k]].x, a[res[k]].y);
            }
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

