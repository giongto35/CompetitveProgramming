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

const int maxn = 10000+10;
int n,m,sa,k,u,v;
vector<pair<int,int> > ke[maxn];
priority_queue<pair<int,int> > q;
int d[maxn];
int cnt,l;
bool die[maxn];

void process(int s)
{
        d[s]=0;
        q.push(make_pair(d[s],s));
        while(!q.empty())
        {
            int u = q.top().second;
            int cur_d=-q.top().first; q.pop();
            if (cur_d > d[u]) continue;
            if (cur_d >= k) break;
            if (die[u] == false)
            {
                cnt++;
                die[u] = true;
            }
            for (int i = 0; i < ke[u].size(); i++)
            {
                int v=ke[u][i].first,len=ke[u][i].second;
                if (d[u]+len<d[v])
                {
                    d[v]=d[u]+len;
                    q.push(make_pair(-d[v],v));
                }
            }
        }
}

int main()
{
    //freopen("EGYMCTU.inp","r",stdin);
    //freopen("EGYMCTU.out","w",stdout);
    while(scanf("%d%d%d%d",&n,&m,&sa,&k) == 4){

        if (n == 0 && m == 0 && sa == 0 && k == 0) break;
        for (int i = 1; i <= n; i++) ke[i].clear();
        while(!q.empty()) q.pop();
        memset(die,false,sizeof(die));
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&u,&v,&l);
            ke[u].push_back(make_pair(v,l));
            ke[v].push_back(make_pair(u,l));
        }
        for (int i = 1; i <= n; i++) d[i] = oo;
        cnt = 0;
        for (int i = 1; i <= sa; i++)
        {
            scanf("%d",&u);
            process(u);
            printf("%d\n", n - cnt);
        }
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

