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

	const int maxn  = 100000+10;
	int a[maxn];
	long long b[maxn];
	int n,k;

	void update(int i, int gt)
	{
		if (i == 0) return;
		while (i <= n)
		{
			b[i] += gt;
			i = i + (i & (-i));
		}
	}

	long long get(int i)
	{
		long long res = 0 ;
		while ( i >= 1)
		{
			res += b[i];
			i = i - (i & (-i));
		}
		return res;
	}

    void process()
	{
        while (scanf("%d%d",&n,&k) == 2){
		char com;
		int u,v;
        memset(b,0,sizeof(b));
		for (int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            if (a[i] == 0) update(i, n + 1); else
                if (a[i] < 0) update(i, 1);
        }
		for (int i = 1; i <= k; i++)
		{
			scanf("\n%c%d%d",&com,&u,&v);

			if (com == 'C')
			{
				if ( a[u] == 0) update(u, - (n + 1));else
				if ( a[u] < 0) update(u, -1);
				if ( v == 0) update(u, n + 1); else
				if ( v < 0) update(u, +1);
                a[u] = v;
			} else
			{
				long long s = get(v) - get(u-1);
				if ( s >=  n + 1) printf("0"); else
				if ( s % 2 == 0) printf("+"); else
				printf("-");
			}
		}
            printf("\n");
        }
    }

int main()
{
    //freopen("IntervalProduct.inp","r",stdin);
    //freopen("","w",stdout);
    process();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

