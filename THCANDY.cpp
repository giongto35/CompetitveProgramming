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
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn=50000+10;
const int oo=10000000;
const long double eps = 0.00000001;
struct point
{
    long double x;
    long double y;
} a[maxn];

struct range
{
    long double l;
    long double r;
} g[maxn];
long double res,kq;
int n;
long double l,r;
int st;

bool check(long double bk)
{
    //(x-x0)^2+y^2 = r^2
    l=-oo;
    r=oo;
    FOR(i,1,n)
    {
        long double xx0=bk*bk-a[i].y*a[i].y;
        if (xx0<0) return false;
        g[i].r=sqrt(xx0)+a[i].x;
        g[i].l=-sqrt(xx0)+a[i].x;
//        cout<<a[i].x<<' '<<g[i].l<<' '<<g[i].r<<endl;
        l=max(l,g[i].l);
        r=min(r,g[i].r);
        if (l>r+eps) return false;
    }
    //cout<<l<<' '<<r<<endl;
    kq=r;
    return true;
}

int main()
{
    //freopen("THCANDY.inp","r",stdin);
    //freopen("THCANDY.out","w",stdout);
    cin>>st;
    while (st>0)
    {

    cin>>n;
    FOR(i,1,n) cin>>a[i].x>>a[i].y;
    long double l=0;
    long double r=1;
    while (check(r)==false) r=r*2;
    FOR(j,1,100)
    {
        long double mid = (l+r)/2;
        if (check(mid))
        {
            res=mid;
            r=mid;
        } else  l=mid;
    }
    check(res);
    cout<<fixed<<setprecision(6)<<kq<<' '<<res<<endl;
    st--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

