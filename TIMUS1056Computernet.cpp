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
const int maxn = 10000+10;
vector<int> ke[maxn];
int cnt[maxn];
bool vis[maxn];
int d[maxn];
int n,u,fr,re;
int q[maxn];

void BFS()
{

    fr=0;re=0;
    memset(vis,false,sizeof(vis));
    FOR(i,1,n) if (ke[i].size()==1)
    q[++re]=i,d[i]=1,vis[i]=true;
    //cout<<re<<' '<<q[1]<<' '<<q[2]<<' '<<d[1]<<' '<<d[2]<<endl;
    while (fr<re)
    {
        fr++;
        int u=q[fr];
        FOR(i,0,ke[u].size()-1)
        {
            int v=ke[u][i];
            cnt[v]--;
            if (vis[v]==false)
            {

                if (cnt[v]==1)
                {
                    q[++re]=v;
                    d[v]=d[u]+1;
                    vis[v]=true;
                    if (re==n) return ;
                }
            }
        }
    }
    //cout<<re<<endl;
    //cout<<q[re]<<endl;
}
int main()
{
    //freopen("computernet.inp","r",stdin);
    //freopen("computernet.out","w",stdout);
    scanf("%d",&n);
    FOR(i,2,n)
    {
        scanf("%d",&u);
        ke[i].push_back(u);
        ke[u].push_back(i);
        cnt[u]++;
        cnt[i]++;
    }
    BFS();
    //FOR(i,1,n) cout<<d[i]<<' '<<d[q[re]]<<endl;
    FOR(i,1,n)
    if (d[i]==d[q[re]]) cout<<i<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

