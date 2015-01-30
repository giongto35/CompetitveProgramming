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
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const int maxn = 100000+10;
const int oo = 1000000000;
vector< ii > ke[maxn];
priority_queue<ii > q;
int d[maxn];
int s,t,T,n,m,u,v,c,cur_d;
int tr[maxn];
int main()
{
    //freopen("Dijkstra.inp","r",stdin);
    //freopen("DijkstraHeap.out","w",stdout);
    scanf("%d",&T);
    FOR(i,1,T)
    {
        scanf("%d%d",&n,&m);
        memset(ke,0,sizeof(ke));
        FOR(i,1,m)
        {
            scanf("%d%d%d",&u,&v,&c);
            ke[u].push_back(make_pair(v,c));
            ke[v].push_back(make_pair(u,c));
        }
        scanf("%d%d",&s,&t);
        FOR(i,1,n) d[i]=oo;
        d[s]=0;
        q.push(make_pair(d[s],s));
        while(!q.empty())
        {
            int u = q.top().second;cur_d=-q.top().first; q.pop();
            if (cur_d>d[u]) continue;
            FOR(i,0,ke[u].size()-1)
            {
                int v=ke[u][i].first,len=ke[u][i].second;
                if (d[u]+len<d[v])
                {
                    d[v]=d[u]+len;
                    tr[v]=u;
                    q.push(make_pair(-d[v],v));
                }
            }
        }
        if (d[t]==oo) cout<<"NO"<<endl;else cout<<d[t]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

