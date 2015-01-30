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

const int maxn = 3*100000+10;
int n,w;
struct box
{
    int s1;
    int s2;
    int vt;
};

box a[maxn];
long long res;
long long sum;
vector<int> gt;
long long BIT[2][maxn * 2];
int ares[maxn];
int maxso;

bool mycmp(box u, box v)
{
    return u.s2 < v.s2;
}

void update(int i,int gt,int k)//change long long
{
    while (i<=maxso)
    {
        BIT[k][i]=BIT[k][i] + gt;
        i=i+(i & (-i));
    }
}


long long get(int i, int k)//change long long
{
    long long gt=0;//change long long
    while (i>=1)
    {
        gt=BIT[k][i] + gt;
        i=i-(i & (-i));
    }
    return gt;
}

void trace(int u)
{
    vector<pair<int,int> > v;
    v.clear();
    for (int i = 1; i <= u; i++)
        v.push_back(make_pair(gt[a[i].s2 - 1],i));
    for (int i = u + 1; i <= n; i++)
        v.push_back(make_pair(gt[a[i].s1 - 1],i));
    sort(v.begin(), v.end());
    for (int i = 1; i <= u; i++)
        ares[a[i].vt]++;
    for (int i = 1; i <= w - u; i++)
    {
        ares[a[v[i - 1].second].vt]++;
    }
    for (int i = 1; i <= n; i++)
        cout<<ares[i];
}

int main()
{
    //freopen("E436.inp","r",stdin);
    //freopen("E436.out","w",stdout);
    scanf("%d%d",&n,&w);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",&a[i].s1,&a[i].s2);
        a[i].vt = i;
    }
    sort(a+1,a+1+n,mycmp);
    for (int i = 1; i <= n; i++)
    {
        gt.push_back(a[i].s1);
        gt.push_back(a[i].s2 - a[i].s1);
    }
    //for (int i = 0; i < gt.size(); i++) cout<<gt[i]<<' ';cout<<endl;
    sort(gt.begin(),gt.end());
    gt.resize(distance(gt.begin(),unique(gt.begin(),gt.end())));
    maxso = gt.size();
    for (int i = 1; i <= n; i++)
    {
        //cout<<i<<' '<<a[i].s2 - a[i].s1<<' '<<a[i].s1<<endl;
        a[i].s2 = lower_bound(gt.begin(),gt.end(),a[i].s2 - a[i].s1) - gt.begin() + 1;
        a[i].s1 = lower_bound(gt.begin(),gt.end(),a[i].s1) - gt.begin() + 1;
    }
    res = 1000000000000000000ll;
    //for (int i = 1; i <= n; i++) cout<<a[i].s1<<' '<<a[i].s2<<' '<<gt[a[i].s1]<<' '<<gt[a[i].s2]<<endl;
    //cout<<endl;
    int vt;
    for (int i = 1; i <= min(w,n); i++)
    {
        update(a[i].s2, 1, 0);
        update(a[i].s2, gt[a[i].s2 - 1], 1);
        sum += gt[a[i].s1 - 1];
    }
    for (int i = w + 1; i <= n; i++)
    {
        update(a[i].s1, 1, 0);
        update(a[i].s1, gt[a[i].s1 - 1], 1);
    }
    for (int i = n; i >= 0; i--)
    {
        int need = w - i;
        if (need < 0 || need > n) continue;
        //cout<<i<<' '<<need<<endl;
        int l = 1;
        int r = maxso;
        int sr = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (get(mid,0) >= need)
            {
                sr = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        //cout<<i<<' '<<need<<' '<<sr<<' '<<sum<<endl;
        //cout<<get(sr,1)<<endl;
        if (res > sum + get(sr - 1,1) + (long long)gt[sr - 1] * (need - get(sr - 1,0)))
        {
            res = sum + get(sr - 1,1) + (long long)gt[sr - 1] * (need - get(sr - 1,0));
            vt = i;
        }
        //cout<<i<<' '<<sum + get(sr - 1,1) + gt[sr - 1] * (need - get(sr - 1,0))<<' '<<sum + get(sr,1)<<' '<<endl;
        if (i > 0) {
            update(a[i].s2, -1, 0);
            update(a[i].s2, -gt[a[i].s2 - 1], 1);

            update(a[i].s1, +1, 0);
            update(a[i].s1, +gt[a[i].s1 - 1], 1);
            sum -= gt[a[i].s1 - 1];
        }
    }
    cout<<res<<endl;
    trace(vt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

