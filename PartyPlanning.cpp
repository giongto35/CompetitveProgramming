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
const int cmod = 1000000007 ;
int next[maxn];
int fr[maxn];
vector<int> ke[maxn];
int root[maxn];
bool croot[maxn];
int sroot,T;
bool cyc[maxn];
vector<int> c[maxn];
int top;
long long F[maxn][2],G[maxn][2];
long long res;
int n;

void DFS(int u)
{
    fr[u]=1;
    if (fr[next[u]]==2);else
    if (fr[next[u]]==1)
    {
        int v=u;
        top++;
        c[top].push_back(v);
        cyc[v]=true;
        while (next[v]!=u)
        {
            v=next[v];
            c[top].push_back(v);
            cyc[v]=true;
        }
    }
    else
    {
        DFS(next[u]);
    }
    fr[u]=2;
}

void rec(int u)
{
    F[u][0]=1;
    F[u][1]=1;
    FOR(i,0,ke[u].size()-1)
    {
        int v=ke[u][i];
        rec(v);
        F[u][0]=(F[u][0]*(F[v][1]+F[v][0]))%cmod;
        F[u][1]=(F[u][1]*F[v][0])%cmod;
    }
}

void process()
{
    memset(ke,0,sizeof(ke));
    memset(c,0,sizeof(c));
    FOR(i,1,n) ke[i].clear();
    FOR(i,1,top) c[top].clear();
    top=0;
    memset(cyc,false,sizeof(cyc));
    memset(fr,0,sizeof(fr));
    memset(root,0,sizeof(root));
    memset(croot,false,sizeof(croot));
    memset(F,0,sizeof(F));
    sroot=0;

    FOR(i,1,n)
    if (fr[i]==0)
        DFS(i);
    /*FOR(i,1,top)
{
    FOR(j,0,c[i].size()-1) cout<<c[i][j]<<' ';
    cout<<endl;
}*/
    sroot=0;
    FOR(i,1,n)
    {
        if (cyc[next[i]]==false) ke[next[i]].push_back(i);
        else
        {
            if (cyc[i]==false)
            {
                ke[next[i]].push_back(i);
            }
            if (croot[next[i]]==false)
            {
                croot[next[i]]=true;
                root[++sroot]=next[i];
            }
        }
    }
    //FOR(i,1,sroot) cout<<root[i]<<endl;
    FOR(i,1,sroot) rec(root[i]);
    res=1;
    //if (T==2) cout<<res<<' '<<top<<' '<<c[top].size()<<' '<<c[top][0]<<endl;
    memset(G,0,sizeof(G));
    FOR(i,1,top)
    {
        long long sum=0;
        FOR(j,0,1)
        {
            G[0][0]=(int)(j==0)*F[c[i][0]][0];
            G[0][1]=(int)(j==1)*F[c[i][0]][1];
            int m=c[i].size()-1;
            FOR(k,1,m)
            {
                int u=c[i][k];
                G[k][0]=(G[k-1][0]*F[u][0]+G[k-1][1]*F[u][0])%cmod;
                G[k][1]=(G[k-1][0]*F[u][1])%cmod;
            }
            //if (T==2) cout<<sum<<' '<<n<<' '<<G[n][0]<<' '<<G[n][1]<<endl;
            if (j==1) sum=(sum+G[m][0])%cmod;
            else sum=(sum+G[m][0]+G[m][1])%cmod;
        }
        res=(res*sum)%cmod;
    }
    cout<<res<<endl;
}

int main()
{
    //freopen("PartyPlanning.inp","r",stdin);
    //freopen("PartyPlanning.out","w",stdout);
    cin>>T;
    while (T>0)
    {
        cin>>n;
        memset(next,0,sizeof(next));
        FOR(i,1,n) scanf("%d",&next[i]);
        process();
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


