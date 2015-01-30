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

long long a,b,w,x,c;
long long res;

bool check (long long v)
{
    long long nc = c - v;
    long long nb = b - x * v;
    long long na = a;
    if (nb >= 0) na; else
    {
        nb = abs(nb);
        if (nb % w == 0)
        na = na - nb / w;
        else
            na = na - (nb / w + 1);
    }
    return na >= nc;
}

int main()
{
    //freopen("C382.inp","r",stdin);
    //freopen("C382.out","w",stdout);
    //scanf("%d%d%d%d%d",&a,&b,&w,&x,&c);
    cin>>a>>b>>w>>x>>c;
    long long l = 0;
    long long r = c;
    res = 0;
    r = 1;
    while (check(r) == false) r *= 2;
    while (l<=r)
    {
        long long mid = (l + r) / 2;
        if (check(mid))
        {
            res = mid;
            r = mid - 1;
        } else l =  mid + 1;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

