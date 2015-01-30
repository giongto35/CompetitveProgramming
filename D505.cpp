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

int n,k;
long long s;
int BIT[100000];
int a[100000];
bool choosen[100000];

void update(int i,int gt)//change long long
{
    while (i<=n)
    {
        BIT[i]=BIT[i] + gt;
        i=i+(i & (-i));
    }
}


int get(int i)//change long long
{
    int gt=0;//change long long
    while (i>=1)
    {
        gt=BIT[i] + gt;
        i=i-(i & (-i));
    }
    return gt;
}

long long calc(int n,int m)
{
    return get(n) - 1 + (long long)(m-1) * (m-2) / 2;
}
int main()
{
    //freopen("D505.inp","r",stdin);
    //freopen("D505.out","w",stdout);
    scanf("%d",&k);
    for (n = 1; n <= 100000; n++)
    {
        s+= n-1;
        if (s >= k) break;
    }
    for (int i = 1; i <= n; i++) update(i,1);
    cout<<n<<endl;
    for (int i = 1; i <= n; i++)
    {
        int l = 1;
        int r = n;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (k <= calc(mid,n-i+1))
            {
                a[i] = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        k-=(get(a[i]) - 1);
        update(a[i],-1);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ",a[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

