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

int a[4000];
int t,n,u,v,v2,res;

int main()
{
    //freopen("B441.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&v);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",&u,&v2);
        a[u]+=v2;
    }
    t = 0;
    for (int i = 1; i <= 3011;i++)
    {
        if (t > 0)
        {
            if (t <= v)
            {
                res+=t;
                int gt = min(v-t,a[i]);
                res+=gt;
                t = a[i] - gt;
            }
            else
            {
                res += v;
                t = a[i];
            }
        }
        else
        {
            int gt = min(v,a[i]);
            res+= gt;
            t = a[i] - gt;
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

