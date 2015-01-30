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

long long l,r,mid,m,k;
long long res;

long long C(long long n, long long k)
{
    if (k > n) return 0;
    if (k > n / 2) k = n - k;
    long long res = 1;
    for (int i = 1; i <= k; i++)
        res = res * (n + 1 - i) / i;
    return res;
}

long long count(long long v)
{
    bool ok = false;
    long long cnt = 0;
    long long res = 0;
    for (long long j = 62; j >= 0; j--)
    {
        long long b = ((v >> j) & 1);
        if (b==1)
        {
            long long left = k - cnt ;
            if (left < 0) break;
            res = res + C(j,left);
        }
        if (b == 1) cnt++;
    }
    return res;
}

int main()
{
    //freopen("D431.inp","r",stdin);
    //freopen("D431.out","w",stdout);
    cin>>m>>k;
    l = 1;
    r = 1000000000000000000ll;
    res = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (count(mid * 2) - count(mid) >= m)
        {
            res = mid;
            r = mid-1;
        }
        else
            l = mid+1;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

