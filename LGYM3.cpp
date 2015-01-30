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

const int maxn = 200+10;
struct train {
    int s;
    int e;
    int t;
};
int Turn,T;
int na,nb;
int h1,m1,h2,m2;
bool used[maxn];
train a[maxn];
int n;
int res[3];

bool mycmp(train u, train v)
{
    return u.s < v.s ;
}

int main()
{
    //freopen("LGYM3.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&T);
    for (int st = 1; st <= T; st++)
    {
        scanf("%d", &Turn);
        scanf("%d%d",&na,&nb);
        n = 0;
        for (int i = 1; i <= na; i++)
        {
            scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
            ++n;
            a[n].s = h1 * 60 + m1;
            a[n].e = h2 * 60 + m2;
            a[n].t = 1;
        }
        for (int i = 1; i <= nb; i++)
        {
            scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
            ++n;
            a[n].s = h1 * 60 + m1;
            a[n].e = h2 * 60 + m2;
            a[n].t = 2;
        }
        sort(a + 1, a + 1 + n, mycmp);
        memset(used, false, sizeof(used));
        memset(res, 0, sizeof(res));
        for (int i = 1; i <= n; i++)
        {
            bool found = false;
            for (int j = 1; j < i; j++)
            {
                //cout<<i<<' '<<a[i].t<<' '<<a[i].s<<' '<<a[i].e<<' '<<a[j].s<<' '<<a[j].e<<endl;
                if (used[j] == false && a[j].t + a[i].t == 3 && a[i].s >= a[j].e + Turn)
                {
                    used[j] = true;
                    found = true;
                    break;
                }
            }
            if (found == false) res[a[i].t]++;
        }
        printf("Case #%d: %d %d\n",st, res[1], res[2]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

