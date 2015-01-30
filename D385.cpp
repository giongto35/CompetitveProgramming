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
#define pi acos(-1.0)
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

struct light {
int x;
int y;
long double  a;
};
int n,l,r;
const long double  eps = 0.00000000001;
const int maxn = 22;
long double  F[1 << maxn];
light a[maxn];
int mb;
int x;
long double  res;

long double  calc(long double  v, int i)
{
    long double  aa = a[i].a;
    long double  ab = atan2(a[i].y-0,a[i].x-v);
    long double  ac = pi - a[i].a - atan2(a[i].y-0,a[i].x-v);
    if (ac < 0) return r;
    long double  ec = sqrt((a[i].x - v) * (a[i].x - v) + a[i].y * a[i].y);
    if (ec * sin(aa) > sin (ac) * (r - v)) return r;
    return min((long double )r,v + ec / sin(ac) * sin(aa));
}

long double  rec(int b)
{
    if (b == 0) return l;
    if (F[b] > -oo) return F[b];
    long double  x = l;
    FOR(i,0,n-1)
    {
        if ((b >> i)&1)
        {
            long double  v = rec(b ^ (1<<i));
            x = max(x, v);
            x = max(x, calc(v,i));
        }
    }
    F[b] = min(x,(long double )r);
    return F[b];
}
int main()
{
    //freopen("D385.inp","r",stdin);
    //freopen("D3852.out","w",stdout);
    cin>>n>>l>>r;
    FOR(i,0,n-1)
    {
        //scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].a);
        cin>>a[i].x>>a[i].y>>a[i].a;
        a[i].a = (a[i].a / 180) * pi;
    }
    mb = (1<<n) - 1;
    FOR(i,0,mb) F[i] = -oo;
    cout<<fixed<<setprecision(6)<<min((long double )r,rec(mb)) - l<<endl;
    //printf("%.6f",min((long double )r,res) - l);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

