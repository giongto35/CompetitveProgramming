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

const int maxn = 100000+10;
const long long oo = 1100000000000000010ll;
long long u,v,l,n,m,k;
long long cur_d;
vector<pair<long long,long long> > ke[maxn];
priority_queue< pair<long long,long long> > q;
pair<long long,long long> trail[maxn];
long long d[maxn];
long long F[maxn];
long long res;
int main()
{
    //freopen("B449.inp","r",stdin);
    //freopen("B449.out","w",stdout);
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    for (long long i = 1; i <= m; i++)
    {
        scanf("%I64d%I64d%I64d",&u,&v,&l);
        ke[u].push_back(make_pair(v,l));
        ke[v].push_back(make_pair(u,l));
    }
    for (long long i = 1; i <= k; i++)
    {
        scanf("%I64d%I64d",&u,&l);
        ke[1].push_back(make_pair(u,l));
        ke[u].push_back(make_pair(1,l));
        trail[i] = make_pair(u,l);
    }

    for (long long i = 1; i <= n; i++) d[i] = oo;
    FOR(i,1,n) d[i]=oo;
    d[1]=0;
    F[1]=1;
    q.push(make_pair(-d[1],1));
    while(!q.empty())
    {
        long long u = q.top().second;
        long long cur_d=-q.top().first;q.pop();
        if (cur_d>d[u]) continue;
        FOR(i,0,ke[u].size()-1)
        {
            long long v=ke[u][i].first;
            long long len=ke[u][i].second;
            if (d[u]+len<d[v])
            {
                d[v]=d[u]+len;
                F[v]=F[u];
                q.push(make_pair(-d[v],v));
            }
            else
            if (d[u]+len==d[v])
            {
                F[v] = min((long long)1000000,F[v] + F[u]);
            }
            //cout<<u<<' '<<v<<' '<<len<<' '<<F[3]<<endl;
        }
    }
    for (long long i = 1; i <= k; i++)
    {
        long long u = trail[i].first;
        //cout<<trail[i].first<<' '<<trail[i].second<<' '<<d[u]<<' '<<F[trail[i].first] <<endl;
        if (trail[i].second > d[u])
        {
            res++;
        }
        else
        if (trail[i].second == d[u] && F[trail[i].first] > 1)
        {
            F[trail[i].first]--;
            res++;
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

