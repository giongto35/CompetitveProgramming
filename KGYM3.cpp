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

const int maxn = 30000+10;
char a[maxn];
int l,r,n,ll,rr;
int cnt;
int main()
{
    //freopen("KGYM3.inp","r",stdin);
    //freopen("KGYM3.out","w",stdout);
    scanf("%d\n",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%c\n",&a[i]);
    }
    l = 1; r = n;
    while (l <= r)
    {
        ll = l;
        rr = r;
        while (a[ll] == a[rr] && ll < rr)
        {
            ll++;
            rr--;
        }
        if (ll >= rr || a[ll] < a[rr])
        {
            printf("%c",a[l]);
            l++;
        }
        else
        {
            printf("%c",a[r]);
            r--;
        }
        cnt++;
        if (cnt % 80 == 0) printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

