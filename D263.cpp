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
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn = 100000+10;
vector<int> a[maxn];
bool freex[maxn];
int d[maxn],k,n,m,u,v;
int tr[maxn];
bool kt;

void DFS(int u)
{
    freex[u]=false;
    FOR(i,0,a[u].size())
    {
        if (freex[a[u][i]])
        {
            d[a[u][i]]=d[u]+1;
            tr[a[u][i]]=u;
            DFS(a[u][i]);
        }
        else
        {
            if (d[u]-d[a[u][i]]+1>=k+1)
            {
                printf("%d\n",d[u]-d[a[u][i]]+1);
                int x= u;
                while (x!=a[u][i])
                {
                    cout<<x<<' ';
                    x=tr[x];
                }
                cout<<x;
                kt=true;
                return;
            }
        }
        if (kt) return;
    }
}

int main()
{
    //freopen("D263.inp","r",stdin);
    //freopen("D263.out","w",stdout);
    cin>>n>>m>>k;
    FOR(i,1,m)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    FOR(i,1,n)
        a[0].push_back(i);
    FOR(i,0,n) freex[i]=true;
    kt=false;
    DFS(0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

