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
int l[maxn];
int r[maxn];
int q[maxn];
int sum[maxn];
int sum2[maxn];
int res[maxn];
int vt[maxn];
int n,m;

int main()
{
    //freopen("B482.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d",&l[i],&r[i],&q[i]);
    }
    for (int k = 0; k <= 29; k++)
    {
        memset(sum,0,sizeof(sum));
        for (int i = 1; i <= m; i++)
        {
            if (((q[i] >> k) & 1) == 1) {
                sum[l[i]]++;
                sum[r[i] + 1]--;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            sum[i] = sum[i-1] + sum[i];
            if (sum[i] == 0)
            {
                sum2[i] = sum2[i-1] + 1;
            } else sum2[i] = sum2[i-1];
        }
        for (int i = 1; i <= m; i++)
        {
            int b = ((q[i] >> k) & 1);
            if ((sum2[r[i]] - sum2[l[i]-1] == 0) != (b > 0)) {
                cout<<"NO";
                return 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (sum[i] > 0)
            {
                res[i] += (1 << k) ;
            }
        }
    }
    cout<<"YES"<<endl;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ",res[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

