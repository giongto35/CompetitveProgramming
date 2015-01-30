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

const int maxn = 1000000;
long long a[maxn];
long long u;
int cnt[1<<11];
long long res;
int T,n;

int main()
{
    freopen("IITKWPCH.inp","r",stdin);
    //freopen("IITKWPCH.out","w",stdout);
    scanf("%d",&T);
    for (int st = 1; st <= T; st++)
    {
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld",&a[i]);
            u = a[i];
            int mask = 0;
            while (u > 0)
            {
                mask |= (1 << (u%10));
                u/=10;
            }
            cnt[mask]++;
        }
        res = 0;
        for (int i = 1; i < (1<<10); i++)
        {
            long long dem = 0;
            for (int j = 0; j < (1<<10); j++)
            {
                if ((j | i) == j) // j contains i
                {
                    dem += cnt[j];
                }
            }
            int numbit = __builtin_popcount(i);
            if (numbit % 2 == 0)
                res -= (long long)dem * (dem - 1) / 2;
            else
                res += (long long)dem * (dem - 1) / 2;

        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

