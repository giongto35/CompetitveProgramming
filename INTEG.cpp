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
#define oo 1000000000000000000LL;
const int maxn=100000+10;
long long a[maxn];
long long n,x,m;
int u;
long long res;
long long sum;
long long s;
int main()
{
    //freopen("INTEG.inp","r",stdin);
    //freopen("INTEG.out","w",stdout);
    scanf("%d",&m);
    FOR(i,1,m) { scanf("%d",&u);if (u<0) a[++n]=u;}
    scanf("%d",&x);
    sort(a+1,a+1+n);
    a[n+1]=0;
    res=abs(a[1])*x;
    FOR(i,1,n)
    {
        s+=a[i];
        //cout<<i<<' '<<s<<endl;
        sum=(long long)(0-a[i+1])*x+(abs(s)-(abs(a[i+1])*i));
        res=min(res,sum);
        /*if (a[i]!=a[i+1])
        {
            sum=(0-a[i])*x;
        }*/
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

