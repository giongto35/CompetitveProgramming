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
const int maxn = 23;
const int oo=1000000000;
int C[maxn][maxn];
int F[maxn][maxn];
int tr[maxn];
int D[maxn],G[maxn],R[maxn];
int freex[maxn];
int tt;
int Q[maxn];
int ll;
int n,s,t,m,i,u,v,a,b;

bool FindPath()
{

    int i,u,v,fr,re;
    fr=0;re=1;
    Q[re]=s;
    freex[s]=tt;
    while (fr<=re)
    {
        fr++;
        u=Q[fr];
        //cout<<u<<endl;
        //getch();
        FOR(i,0,t)
        {
            if (freex[i]!=tt&&C[u][i]>0&&C[u][i]>F[u][i])
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
                //cout<<tr[v]<<' '<<v<<' '<<C[tr[v]][v]-F[tr[v]][v]<<endl;
                //getch();
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

int main()
{
    //freopen("Amini6.inp","r",stdin);
    //freopen("Amini6.out","w",stdout);
    while (true)
    {
        cin>>n>>a>>b;
        if (n==0) return 0;
        memset(C,0,sizeof(C));
        memset(F,0,sizeof(F));
        memset(freex,0,sizeof(freex));
        FOR(i,1,n)
        FOR(j,1,n) cin>>C[i][j];

        s=0;
        t=n+1;

        FOR(i,1,a)
        {
            cin>>D[i];
            D[i]++;
            C[D[i]][t]=oo;
        }
        int sum=0;
        FOR(i,1,b)
        {
            cin>>G[i]>>R[i];
            G[i]++;
            C[0][G[i]]=R[i];
            sum+=R[i];
        }
        //cout<<MaxFlow()<<endl;
/*
        bool kq=true;
        FOR(i,1,b)
        if (C[0][G[i]]!=0)
        {
            kq=false;
            break;
        }*/
        if (MaxFlow()==sum) cout<<"SAFE"<<endl;
        else
            cout<<"FLOOD!!!"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
