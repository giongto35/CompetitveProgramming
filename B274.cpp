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
const int maxn=100000+10;
int u,v;
vector<int> a[maxn];
long long D[maxn];
long long stru[maxn];
long long scong[maxn];
bool vis[maxn];
int n;
long long res;

void DFS(int u)
{
    vis[u]=true;
    long long gtmax=0;
    long long gtmin=0;
    FOR(i,0,a[u].size()-1)
    {
        if (vis[a[u][i]]==false)
        {
            DFS(a[u][i]);
            gtmax=max(gtmax,stru[a[u][i]]);
            gtmin=min(gtmin,scong[a[u][i]]);
        }
    }
    D[u]=D[u]-gtmax-gtmin;
    stru[u]=gtmax;
    scong[u]=gtmin;
    if (D[u]>0) stru[u]+=D[u];
    if (D[u]<0) scong[u]+=D[u];
    //cout<<u<<' '<<D[u]<<' '<<stru[u]<<' '<<scong[u]<<endl;
}

int main()
{
    //freopen("B274.inp","r",stdin);
    //freopen("B274.out","w",stdout);
    cin>>n;
    FOR(i,1,n-1)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    FOR(i,1,n) cin>>D[i];
    memset(vis,false,sizeof(vis));
    res=0;
    DFS(1);
    cout<<abs(stru[1])+abs(scong[1])<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

