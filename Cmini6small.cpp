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
const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};
const int maxn = 5003;
const int maxs = 50+3;
const int oo=1000000000;
int F[maxn][maxn];
int C[maxn][maxn];
vector<int> D[maxn];
int tr[maxn];
int freex[maxn];
int tt;
int din[maxs][maxs],dout[maxs][maxs];
int Q[maxn];
int ll,ct;
int n,s,t,m,i,u,v,a,b,y,x;

bool FindPath()
{

    int i,u,v,fr,re;
    fr=0;re=1;
    Q[re]=s;
    freex[s]=tt;
    while (fr<re)
    {
        fr++;
        u=Q[fr];
        FOR(v,0,D[u].size()-1)
        {
            i=D[u][v];
            if (freex[i]!=tt&&C[u][i]>F[u][i])
            {
                Q[++re]=i;
                tr[i]=u;
                freex[i]=tt;
                if (i==t) return true;
            }
        }
    }
    return false;
}

int MaxFlow()
{
    int v,delta;
    int ret=0;
    memset(F,0,sizeof(F));
    memset(freex,0,sizeof(freex));
    tt=0;
    while(true)
    {
        tt++;
        if (FindPath())
        {
            delta=oo;
            v=t;
            while (v!=s)
            {
                delta=min(delta,C[tr[v]][v]-F[tr[v]][v]);
                v=tr[v];
            }
            v=t;
            while (v!=s)
            {
                F[tr[v]][v]+=delta;
                F[v][tr[v]]-=delta;
                v=tr[v];
            }
            ret+=delta;
        }
        else
            break;
    }
    return ret;
}

void addedge(int u,int v,int cap)
{
    if (C[u][v]==0&&C[v][u]==0)
    {
        D[u].push_back(v);
        D[v].push_back(u);
    }
    C[u][v]=cap;
}
int main()
{
    //freopen("Cmini6.inp","r",stdin);
    //freopen("Cmini6.out","w",stdout);
    int st;
    cin>>st;
    FOR(ct,1,st)
    {
        cin>>n>>m>>b;
        memset(C,0,sizeof(C));
        FOR(i,0,n*m*2+2)
        D[i].clear();

        s=0;
        t=0;
        FOR(i,1,n)
        FOR(j,1,m)
        {
            t++;
            din[i][j]=t;
        }
        FOR(i,1,n)
        FOR(j,1,m)
        {
            t++;
            dout[i][j]=t;
        }
        t++;
        FOR(i,1,b)
        {
            cin>>y>>x;
            addedge(s,din[y][x],1);
        }
        if (b>n*m)
        {
            cout<<"not possible"<<endl;
            continue;
        }
        FOR(i,1,n)
        FOR(j,1,m)
        {
            addedge(din[i][j],dout[i][j],1);
            FOR(k,0,3)
            {
                if (i+dy[k]>=1&&i+dy[k]<=n&&j+dx[k]>=1&&j+dx[k]<=m)
                    addedge(dout[i][j],din[i+dy[k]][j+dx[k]],1);
            }
        }
        FOR(i,1,n)
        {
            addedge(dout[i][1],t,oo);
            addedge(dout[i][m],t,oo);
        }
        FOR(i,1,m)
        {
            addedge(dout[1][i],t,oo);
            addedge(dout[n][i],t,oo);
        }
        //cout<<MaxFlow()<<' '<<b<<endl;
        if (MaxFlow()==b) cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

