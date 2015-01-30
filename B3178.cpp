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
vector<int> ke[maxn];
vector<int> a[maxn];
bool open[maxn];
int par[maxn][20];
int top;
int st[maxn];
int num[maxn];
int cnt;
int cc,n,d[maxn],m;
int tpar[maxn];
int low[maxn],lab[maxn],u,v,q;

void DFS(int u,int pr)
{
    st[++top]=u;
    num[u]=++cnt;
    low[u]=num[u];
    FOR(i,0,ke[u].size()-1)
    {
        int v=ke[u][i];

        if (pr!=v)
        {
            if (num[v]>0)
                    low[u]=min(low[u],num[v]);
                else
                {
                    pr=u;
                    DFS(v,u);
                    low[u]=min(low[u],low[v]);
                    //if (v==7) cout<<u<<' '<<low[v]<<' '<<low[u]<<endl;
                }
        }
    }
    //cout<<low[4]<<endl;
    if (low[u]==num[u])
    {
        cc++;
        int v;
        do{
            v=st[top--];
            lab[v]=cc;
            open[v]=false;
        }
        while(v!=u);
    }
}

void build()
{
    FOR(i,1,n)
    FOR(j,0,ke[i].size()-1)
    {
        if (lab[i]!=lab[ke[i][j]])
        {
            int u=lab[i];
            int v=lab[ke[i][j]];
            a[u].push_back(v);
            a[v].push_back(u);
        }
    }
}

void rec(int u)
{
    open[u]=false;
    FOR(i,0,a[u].size()-1)
    {
        int v=a[u][i];
        if (open[v]==true)
        {
            d[v]=d[u]+1;
            par[v][0]=u;
            FOR(j,1,(int)log2(d[v]))
            {
                par[v][j]=par[par[v][j-1]][j-1];
            }
            rec(v);
        }

    }
}

void buildLCA()
{
    memset(open,true,sizeof(open));
    rec(1);

}

void balance(int &u,int &v)
{
    if (d[u]<d[v]) {int tg=u;u=v;v=tg;}
    while (d[u]>d[v])
    {
        int delta=log2(d[u]-d[v]);
        u=par[u][delta];
    }
}



int minpath(int u,int v)
{
    int res=d[u]+d[v];
    balance(u,v);
    DOW(i,log2(d[u]),0)
    {
        if (par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];

        }
    }
    if (u!=v) u=par[u][0],v=par[v][0];
    //cout<<res<<' '<<u<<' '<<d[u]*2<<endl;
    return res-d[u]*2;
}

int main()
{
    //freopen("B3178.inp","r",stdin);
    //freopen("B3178.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,m)
    {
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    DFS(1,0);
    //FOR(i,1,n) cout<<i<<' '<<num[i]<<' '<<low[i]<<' '<<lab[i]<<endl;
    build();
    buildLCA();
    //FOR(i,1,n) cout<<d[i]<<endl;
    cin>>q;
    int s,t;
    FOR(i,1,q)
    {
        cin>>s>>t;
        cout<<minpath(lab[s],lab[t])<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

