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
bool dd[maxn];
bool used[maxn];
int F[maxn],G[maxn];
int par[maxn];
vector<int> ke[maxn];
vector<int> res;
int l[maxn],r[maxn],n,m,d,u,v;

void DFS1(int u)
{
    used[u]=true;
    if (dd[u]) F[u]=0;
    FOR(i,0,ke[u].size()-1)
    {
        int v=ke[u][i];
        if (used[v]==false)
        {
            par[v]=u;
            DFS1(v);
            F[u]=max(F[u],F[v]+1);
        }
    }
}

void DFS2(int u)
{
    FOR(i,0,ke[u].size()-1)
    {
        l[i]=-oo;
        r[i]=-oo;
    }
    FOR(i,0,ke[u].size()-1)
    {
        int v=ke[u][i];
        if (i>0) l[i]=l[i-1];
        if (v!=par[u])
            l[i]=max(l[i],F[v]);
    }
    DOW(i,ke[u].size()-1,0)
    {
        int v=ke[u][i];
        if (i<ke[u].size()-1) r[i]=r[i+1];
        if (v!=par[u])
            r[i]=max(r[i],F[v]);
    }
    FOR(i,0,ke[u].size()-1)
    {
        int v=ke[u][i];
        if (v!=par[u])
        {
            G[v]=max(G[v],G[u]+1);
            if (i>0) G[v]=max(G[v],l[i-1]+2);
            if (i<ke[u].size()-1) G[v]=max(G[v],r[i+1]+2);
        }
    }
    FOR(i,0,ke[u].size()-1)
    {
        int v=ke[u][i];
        if (v!=par[u])
        DFS2(v);

    }
}

int main()
{
    //freopen("B.in1","r",stdin);
    //freopen("B338.out","w",stdout);
    scanf("%d%d%d",&n,&m,&d);
    FOR(i,1,m)
    {
        scanf("%d",&u);
        dd[u]=true;
    }
    FOR(i,1,n) {F[i]=-oo,G[i]=-oo; if (dd[i]) G[i]=0;}
    FOR(i,1,n-1)
    {
        scanf("%d%d",&u,&v);
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    DFS1(1);
    DFS2(1);
    //FOR(i,1,n) cout<<F[i]<<' ';cout<<endl;
    //FOR(i,1,n) cout<<G[i]<<' ';cout<<endl;
    int cnt=0;
    FOR(i,1,n)
        if (F[i]<=d&&G[i]<=d) cnt++;//res.push_back(i);
    //cout<<res.size()<<endl;
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

