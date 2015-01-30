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
const int oo = 1000000000+10;
const int maxn = 20000+10;
const int maxk = 200+10;
int n,m,k,q,u,v,c;
vector<pair<int,int> > a[maxn],b[maxn];
int h[maxn];
long long sum;
int cnt;
int d1[maxk][maxn],d2[maxk][maxn];
priority_queue<pair<int,int> > pq;

void dijkstra(int (&d)[maxn],vector<pair<int,int> > a[maxn],int S)
{
    FOR(i,1,n) d[i] = oo;
    d[S] = 0;
    pq.push(make_pair(-d[S],S));
    while (!pq.empty())
    {
        pair<int,int> u = pq.top();pq.pop();
        if (-  u.first > d[u.second]) continue;
        int x = u.second;
        FOR(i,0,a[x].size()-1)
        {
            int v =  a[x][i].first;
            if (d[v] > d[x] + a[x][i].second)
            {
                d[v] = d[x] + a[x][i].second;
                pq.push(make_pair(-d[v],v));
            }
        }
    }
}
int main()
{
    freopen("vacationgold.in","r",stdin);
    freopen("vacationgold.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&q);
    FOR(i,1,m)
    {
        scanf("%d%d%d",&u,&v,&c);
        a[u].push_back(make_pair(v,c));
        b[v].push_back(make_pair(u,c));
    }
    FOR(i,1,k)
    {
        scanf("%d",&h[i]);
        dijkstra(d1[i],a,h[i]);
        dijkstra(d2[i],b,h[i]);
    }
    sum = 0;
    cnt = 0;
    FOR(i,1,q)
    {
        scanf("%d%d",&u,&v);
        int res = oo;
        FOR(j,1,k)
        {
            res = min(res,(d2[j][u] + d1[j][v]));
        }
        if (res == oo) ;
        else sum += res,cnt++;
    }
    cout<<cnt<<endl;
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

