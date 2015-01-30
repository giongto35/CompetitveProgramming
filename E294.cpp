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
const int maxn=5000+10;
const long long oo=1000000000000000000LL;
vector<int> a[maxn];
int l[maxn][maxn];
int D[maxn];
long long F[maxn],G[maxn],S[maxn],gtmin,res;
int par[maxn];
int mark[maxn];
int umin,n,u,v;
long long sum;
int Droot;

void DFS(int u)
{
    FOR(i,0,a[u].size()-1)
    {
        int v=a[u][i];
        if (par[v]==0)
        {
            par[v]=u;
            DFS(v);
        }
    }
}

void rec(int u,int avoid)
{
    mark[u]=true;
    D[u]=1;
    FOR(i,0,a[u].size()-1)
    {
        int v=a[u][i];
        if (mark[v]==false&&v!=avoid)
        {
            mark[v]=true;
            rec(v,avoid);
            D[u]=D[u]+D[v];
            S[u]=S[u]+S[v]+(long long)D[v]*l[u][v];
        }
    }
    //cout<<u<<' '<<D[u]<<' '<<S[u]<<endl;
}

void rec2(int u,int avoid)
{
    mark[u]=true;
    G[u]=S[u]+F[u];
    sum=sum+G[u];
    if (gtmin>G[u]) umin=u,gtmin=G[u];
    FOR(i,0,a[u].size()-1)
    {
        int v=a[u][i];
        if (mark[v]==false&&v!=avoid)
        {
            F[v]=F[u]+S[u]-S[v]-(long long)l[u][v]*D[v]+(long long)l[u][v]*(Droot-D[v]);
            rec2(v,avoid);
        }
    }
}


void process(int u,int v)
{
    memset(D,0,sizeof(D));
    memset(S,0,sizeof(S));
    memset(F,0,sizeof(F));
    memset(G,0,sizeof(G));

    memset(mark,false,sizeof(mark));
    rec(u,v);
    memset(mark,false,sizeof(mark));
    sum=0;
    gtmin=oo;
    Droot=D[u];
    rec2(u,v);
    int u1=umin;
    long long d1=Droot;
    long long g1=G[u1];

    memset(mark,false,sizeof(mark));
    rec(v,u);
    memset(mark,false,sizeof(mark));
    gtmin=oo;
    Droot=D[v];
    rec2(v,u);
    int u2=umin;
    long long d2=Droot;
    long long g2=G[u2];
    //cout<<u<<' '<<v<<' '<<g1<<' '<<d1<<' '<<g2<<' '<<d2<<' '<<' '<<sum/2+g1*d2+g2*d1+(long long)l[u][v]*d1*d2<<endl;
    res=min(res,sum/2+g1*d2+g2*d1+(long long)l[u][v]*d1*d2);
}

int main()
{
    //freopen("E294.inp","r",stdin);
    //freopen("E294.out","w",stdout);
    cin>>n;
    FOR(i,1,n-1)
    {
        int x;
        cin>>u>>v>>x;
        l[v][u]=l[u][v]=x;
        //cout<<u<<' '<<v<<' '<<l[u][v]<<' '<<l[v][u]<<endl;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    par[1]=-1;
    DFS(1);
    res=oo;
    //process(3,4);
    //cout<<res<<endl;
    //return 0;
    FOR(i,1,n)
        if (par[i]!=0&&par[i]!=-1)
            process(i,par[i]);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

