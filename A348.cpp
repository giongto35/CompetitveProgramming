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
long long a[maxn],b[maxn];
long long l,r,res,n;
bool check (long long s)
{
    long long u=n-1;//(s*(n-1))
    long long v=s;
    FOR(i,1,n) a[i]=b[i];
    FOR(i,1,n) if (s<a[i]) return false;
    FOR(i,1,n)
    {
        while (a[i]>0)
        {
            long long t=min(a[i],v);
            v=v-t;
            a[i]=a[i]-t;
            if (v==0) {v=s;u--;}
            if (u<0) return false;
        }
    }
    if (u>=1||(u==0&&v==s))
    return true; else return false;
}
int main()
{
    //freopen("A348.inp","r",stdin);
    //freopen("A348.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>b[i];
    l=1;
    r=1;
    while (check(r)==false) r*=2;
    int res=0;
    while (l<=r)
    {
        long long mid=(l+r)/2;
        if (check(mid))
        {
            res=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

