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

long long n,a,b,ra,rb;
long long res;
void process(long long a, long long b, bool s)
{
    for (long long i = a; i <= a + 1000000; i++)
    {
        long long nb;
        if (n % i == 0) nb = n / i; else nb = n / i + 1;
        nb = max(nb, b);
        if (res == -1 || res > nb * i )
        {
            res = nb * i;
            if (s == false)
            {
                ra = i;
                rb = nb;
            }
            else
            {
                ra = nb;
                rb = i;
            }
        }
    }
}

int main()
{
    //freopen("B466.inp","r",stdin);
    //freopen("B466.out","w",stdout);
    cin>>n>>a>>b;
    n = 6 * n;
    res = -1;
    process(a,b,false);
    process(b,a,true);
    cout<<res<<endl;
    cout<<ra<<' '<<rb<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

