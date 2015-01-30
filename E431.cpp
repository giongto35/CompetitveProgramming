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

const int maxn = 200000+10;
struct query
{
    int t;
    long long p;
    int x;
} q[maxn];
int n,m;
long long BIT[2][maxn];
int a[maxn];
int sz,u;
vector<int> rr;
void update(int i, int k, int gt)//change long long
{
    while (i<=sz)
    {
        BIT[k][i]=BIT[k][i] + gt;
        i=i+(i & (-i));
    }
}


long long get(int i, int k)
{
    long long gt=0;//change long long
    while (i>=1)
    {
        gt=BIT[k][i] + gt;
        i=i-(i & (-i));
    }
    return gt;
}

bool check(int vt,long long gt)
{
    if ((double)(get(vt - 1,0)) * rr[vt] - get(vt - 1,1) > gt)
        return true;
    else
        return false;
}

int main()
{
    //freopen("E431.inp","r",stdin);
    //freopen("E431.out","w",stdout);
    scanf("%d%d",&n,&m);
    rr.push_back(-1);

    rr.push_back(1000000001);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&u);
        a[i] = u;
        rr.push_back(u);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d",&q[i].t);
        if (q[i].t == 1)
        {
            scanf("%d%d",&q[i].p,&q[i].x);
            rr.push_back(q[i].x);
        }
        else scanf("%I64d",&q[i].p);
            //cin>>q[i].p;
    }
    sort(rr.begin(),rr.end());
    vector<int>::iterator it = unique(rr.begin(),rr.end());
    rr.resize(distance(rr.begin(),it));
    sz = rr.size()-1;
    for (int i = 1; i <= n; i++)
    {
        //cout<<a[i]<<endl;
        int vt = lower_bound(rr.begin(),rr.end(),a[i]) - rr.begin();
        update(vt,0,1);
        update(vt,1,a[i]);
    }
    update(sz,0,1);
    for (int i = 1; i <= m; i++)
    {
        if (q[i].t == 1)
        {
            int vt = lower_bound(rr.begin(),rr.end(),a[q[i].p]) - rr.begin();
            update(vt,0,-1);
            update(vt,1,-a[q[i].p]);
            int newvt = lower_bound(rr.begin(),rr.end(),q[i].x) - rr.begin();
            update(newvt,0,1);
            update(newvt,1,rr[newvt]);
            a[q[i].p] = q[i].x;
        }
        else{
            int l = 1;
            int r = rr.size()-1;
            int vt = sz;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (check(mid,q[i].p))
                {
                    vt = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            printf("%0.4f\n",((double)q[i].p + get(vt - 1,1) + 0.0) / get(vt - 1,0));
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

