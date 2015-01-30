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
int a[maxn * 2];
int lab[maxn * 2];
int Q;
int com;
int u,T,n,v;

int getroot(int u)
{
    if (lab[u] == -1) return u;
    lab[u] = getroot(lab[u]);
    return lab[u];
}
int main()
{
    //freopen("DISHOWN.inp","r",stdin);
    //freopen("DISHOWN.out","w",stdout);
    scanf("%d",&T);
    for (;T>0;T--)
    {
        scanf("%d",&n);
        for (int i = 1; i <= 2 * n; i++)
            lab[i] = -1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i + n]);
            lab[i] = i + n;
        }
        scanf("%d",&Q);
        for (int i = 1; i <= Q; i++)
        {
            scanf("%d",&com);
            if (com == 0)
            {
                scanf("%d%d",&u,&v);
                int x = getroot(u);
                int y = getroot(v);
                if (x == y)
                    printf("Invalid query!\n");
                else
                if (a[x] < a[y])
                    lab[x] = y;
                else
                if (a[x] > a[y])
                    lab[y] = x;
            }
            else
            {
                scanf("%d",&u);
                printf("%d\n",getroot(u)-n);

            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

