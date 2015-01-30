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
long long h[maxn];
long long p[maxn];
long long r,l;
long long res;
int n,m;

bool check (long long v)
{
    int l=1;
    long long moveright;
    FOR(i,1,n)
    {
        if (p[l]<h[i]-v) return false;
        if (p[l]>h[i]+v) continue;
        if (p[l]==h[i]+v) moveright=h[i]+v;
        else
        moveright=h[i]+v-2*max(0LL,h[i]-p[l]);

        if (p[l]<h[i])
        {
            long long k=(v+p[l]-h[i])/2;
            moveright=max(moveright,h[i]+k);
        }
        while (l<=m&&p[l]<=moveright) l++;
        if (l==m+1) return true;
    }
    return false;
}

int main()
{
    //freopen("C343.in","r",stdin);
    //freopen("C343.out","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,n)
        cin>>h[i];
    FOR(i,1,m)
        cin>>p[i];
    sort(h+1,h+1+n);
    sort(p+1,p+1+m);
    r=1;
    while (check(r)==false) r=r*2;
    l=0;
    while (l<=r)
    {
        long long mid = (l+r)/2;
        if (check(mid))
        {
            res=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

