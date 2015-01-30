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

int l,r,mid;
int n,m,s;
int b[maxn],c[maxn];
pair<int,int> a[maxn];
pair<pair<int,int>,int > d[maxn];
int kq[maxn];
priority_queue<pair<int,int> > pq;
int res[maxn];
int rr;

bool check (int v)
{
    int j = n;
    long long sum = 0;
    pq = priority_queue<pair<int,int> >();
    for (int i = m; i >= 1; i -= v)
    {
        while ( j >= 1 && d[j].first.first >= a[i].first) pq.push(make_pair(- d[j].first.second, j)),j--;
        if (pq.empty()) return false;
            int x = pq.top().second;
            sum += d[x].first.second;
            kq[i] = d[x].second;
            pq.pop();
        if (sum > s) return false;
    }
    return true;
}

int main()
{
    //freopen("B377.inp","r",stdin);
    //freopen("B377.out","w",stdout);
    scanf("%d%d%d",&n,&m,&s);
    FOR(i,1,m) scanf("%d",&a[i].first),a[i].second = i;
    sort( a + 1, a + 1 + m);
    FOR(i,1,n) scanf("%d",&b[i]);
    FOR(i,1,n) scanf("%d",&c[i]),d[i] = make_pair(make_pair(b[i],c[i]), i);
    sort( d + 1 , d + 1 + n);
    l = 1;
    r = m;
    rr = -1;
    while (l<=r)
    {
        int mid = (l + r) / 2;
        if (check (mid))
        {
            rr = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    check(rr);
    if (rr == -1) cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        for (int i = m; i >= 1; i -= rr)
        {
            DOW(j,i,max(1,i-rr+1))
            {
                res[a[j].second] = kq[i];
            }
        }
        FOR(i,1,m) printf("%d ",res[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

