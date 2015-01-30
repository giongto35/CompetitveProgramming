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

long long suma,sumb,a,b,k;
long long res;
int rk,rk2;

void print(char c,
            int cnt)
{
    for (int i = 1; i <= cnt; i++) printf("%c",c);
}

long long sqr(long long a)
{
    return a * a;
}
int main()
{
    //freopen("A398.inp","r",stdin);
    //freopen("A398.out","w",stdout);
    scanf("%d%d",&a,&b);
    res = -10000000000000000ll;
    if (a == 0)
    {
        cout<<-sqr(b)<<endl;
        print('x',b);
        return 0;
    }
    if (b == 0)
    {
        cout<<sqr(a)<<endl;
        print('o',a);
        return 0;
    }
    for (long long k = 1; k <= a; k++)
    {
        //k group of a
        long long suma = (k-1) * sqr(1) + sqr( a - k + 1);
        for (long long k2 = max(1ll,k-1); k2 <= min(b, k+1); k2++ )
        {
            //k2 group of b
            long long s1 = b % k2;
            long long s2 = k2 - b % k2;
            long long sumb = sqr( b / k2 + 1) * s1 + sqr( b / k2 ) * s2;
            if ( res <= suma - sumb)
            {
                //cout<<suma<<' '<<sumb<<' '<<k<<' '<<k2<<endl;
                rk = k;
                rk2 =k2;
                res = suma - sumb;
            }
        }
    }
    cout<<res<<endl;
    if (rk2 <= rk)
    {
        int d = 0;
        for (int i = 1; i <= rk2 + rk; i++)
        {
            if ( i % 2 == 1)
            {
                if (i == 1) print('o', a - rk + 1); else
                print('o',1);
            }
            else
            {
                d++;
                if (d <= b % rk2)
                    print('x',b / rk2 + 1);
                else
                    print('x',b / rk2);
            }
        }
    }
    else
    {
        int d = 0;
        for (int i = 1; i <= rk2 + rk; i++)
        {
            if ( i % 2 == 1)
            {
                d++;
                if (d <= b % rk2)
                    print('x',b / rk2 + 1);
                else
                    print('x',b / rk2);
            }
            else
            {
                if (i == 2) print('o', a - rk + 1); else
                print('o',1);
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

