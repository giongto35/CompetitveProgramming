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

const int maxn = 100000;
int a[maxn];
int b[maxn];
map<int,bool> bad;
int vt,gcd,res,n,m;

int calc(int u)
{
    int res = 0;

    for (int i = 2; i  * i <= u; i++)
    {
        int hs;
        if (u % i == 0){
            if (bad[i]) hs = -1; else hs = 1;
            while (u % i == 0)
            {
                res += hs;
                u /= i;
            }
        }
    }
    if (u > 1)
    {
        if (bad[u]) res--; else res++;
    }
    return res;
}
int main()
{
    //freopen("B403.inp","r",stdin);
    //freopen("B403.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for (int i = 1; i <= m; i++) scanf("%d",&b[i]),bad[b[i]] = true;
    while(true)
    {
        int sgcd = a[1];
        int gtmin = calc(a[1]);
        int vt = 0;
        for (int i = 1 ; i <= n; i++)
        {
            sgcd = __gcd(sgcd,a[i]);
            int c = calc(sgcd);
            if (sgcd == 1) break;
            if (c < 0)
            {
                gtmin = c * i;
                gcd = sgcd;
                vt = i;
            }
        }
        if (gtmin >= 0 ||  vt == 0) break;
        for (int i = 1; i <= vt; i++) a[i] /= gcd;
    }
    res = 0;
    for (int i  =1 ; i<= n; i++)
        {
            res += calc(a[i]);
        }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

