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

const int maxn = 1000000;
const long long oo = 1000000000000000000ll;
long long res;
int n,m,c;
int l;
int a[maxn];
int tr[maxn];

int main()
{
    freopen("B.inp","r",stdin);
    //freopen("B.out","w",stdout);
    while(true)
    {
        scanf("%d%d",&n,&c);
        if (n==0&&c==0) break;
        res=c;
        scanf("%d",&a[1]);
        l=1;
        FOR(i,2,n)
        {
            scanf("%d",&a[i]);
            if (c+(a[i]-a[l])*(a[i]-a[l]) >= c+(a[i-1]-a[l])*(a[i-1]-a[l])+c)
            {
                res=res+c+(a[i-1]-a[l])*(a[i-1]-a[l]);
                cout<<l<<' '<<i-1<<endl;
                l=i;
            }
        }
        res=res+c+(a[n]-a[l])*(a[n]-a[l]);
        cout<<res<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
