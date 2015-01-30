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

const int maxn = 2000+10;
struct
{
    int t;
    int h;
    int m;
} a[maxn];
bool used[maxn];
int cur;
int dem;
int res,n,x,t;
int main()
{
    //freopen("A436.inp","r",stdin);
    //freopen("A436.out","w",stdout);
    scanf("%d%d",&n,&x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d",&a[i].t,&a[i].h,&a[i].m);
    }
    for (int st = 0 ; st <= 1; st++)
    {
        t = st;
        cur = x;
        dem = 0;
        memset(used,false,sizeof(used));
        while(true)
        {
            int gtmax = -1;
            bool ok = false;
            for (int i = 1; i <= n; i++)
            {
                if (used[i] == false && a[i].t == t && a[i].h <= cur)
                if (gtmax == -1||a[gtmax].m<a[i].m)
                {
                    gtmax = i;
                    ok = true;
                }
            }
            if (ok==false) break;
            cur += a[gtmax].m;
            used[gtmax] = true;
            dem++;
            t = 1 - t;
        }
        res = max(res,dem);
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

