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

const int maxn = 1000000+10;
int T;
int n;
int SN[1000+10];
int W[maxn];
int sl;
map<pair<int,int>, int> ma;
vector<pair<int,int> > a[maxn];
int d[maxn];
priority_queue<pair<int,int> > q;
int u,m1,s1,m2,s2;
int ttime[maxn],t;
int nTunnel;
int nQuery;

int get(int i, int j)
{
    if ( ma.count(make_pair(i,j)) == 0)
    {
        ma[make_pair(i,j)] = ++sl;
        a[sl].clear();
    }
    return ma[make_pair(i,j)];
}

int dijkstra(int s, int t)
{
    while (!q.empty()) q.pop();
    n = sl;
    for (int i = 1; i <= n; i++) d[i]=oo;
    d[s]=0;

    q.push(make_pair(d[s],s));
        while(!q.empty())
        {
            int u = q.top().second;
            int cur_d=-q.top().first;
            q.pop();
            if (cur_d>d[u]) continue;
            for (int i = 0; i < a[u].size(); i++)
            {
                int v=a[u][i].first,len=a[u][i].second;
                if (d[u]+len<d[v])
                {
                    d[v]=d[u]+len;
                    q.push(make_pair(-d[v],v));
                }
            }
        }
        if (d[t]==oo) return -1;
        else return d[t];

}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("BAPAC2.out","w",stdout);
    scanf("%d",&T);
    for (int ste = 1; ste <= T; ste++)
    {
        cerr<<ste<<endl;
        scanf("%d",&n);
        ma.clear();
        sl = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d",&SN[i], &W[i]);
            for (int j = 1; j < SN[i]; j++)
            {
                scanf("%d",&ttime[j]);
                //a[get(i,j)].push_back(make_pair(get(i,j+1),ttime + W[i]));
                //a[get(i,j+1)].push_back(make_pair(get(i,j),ttime + W[i]));
                //cout<<i<<' '<<j<<' '<<get(i,j)<<endl;
            }
            for (int j = 1; j < SN[i]; j++)
            {
                int sumTime = 0;
                for (int k = j + 1; k <= SN[i]; k++)
                {
                    sumTime += ttime[k - 1];
                    a[get(i,j)].push_back(make_pair(get(i,k),sumTime + W[i]));
                    a[get(i,k)].push_back(make_pair(get(i,j),sumTime + W[i]));
                }
            }
        }
        scanf("%d",&nTunnel);
        for (int i = 1; i <= nTunnel; i++)
        {
            scanf("%d%d%d%d%d", &m1, &s1, &m2, &s2, &t);
            a[get(m1,s1)].push_back(make_pair(get(m2,s2), t));
            a[get(m2,s2)].push_back(make_pair(get(m1,s1), t));
        }
        scanf("%d",&nQuery);
        cout<<"Case #"<<ste<<":"<<endl;
        for (int i = 1; i <= nQuery; i++)
        {
            scanf("%d%d%d%d",&m1, &s1, &m2, &s2);
            //cout<<get(m1,s1)<<' '<<get(m2,s2)<<endl;
            cout<<dijkstra(get(m1,s1), get(m2,s2))<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

