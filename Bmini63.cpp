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
const int maxn = 1003;
const int oo=1000000000;
int C[maxn][maxn];
int F[maxn][maxn];
int D[maxn][maxn];
int tr[maxn];
int freex[maxn];
int tt;
int Q[maxn];
int ll,ct;
int n,s,t,m,i,u,v,a,b;

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
        //cout<<u<<endl;
        //getch();
        FOR(v,1,D[u][0])
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

int con(string c)
{
    if (c=="XXL") return 1;
    if (c=="XL") return 2;
    if (c=="L") return 3;
    if (c=="M") return 4;
    if (c=="S") return 5;
    if (c=="XS") return 6;
}

void addedge(int u,int v,int cap)
{
    if (C[u][v]==0&&C[v][u]==0)
    {
        D[u][++D[u][0]]=v;
        D[v][++D[v][0]]=u;
    }
    C[u][v]=cap;
}
int main()
{
    //freopen("Bmini6.inp","r",stdin);
    //freopen("Amini6.out","w",stdout);
    int st;
    cin>>st;
    FOR(ct,1,st)
    {
        cin>>n>>m;
        memset(C,0,sizeof(C));
        memset(F,0,sizeof(F));
        memset(D,0,sizeof(D));
        memset(freex,0,sizeof(freex));
        int sl=n/6;
        s=0;
        t=m+6+1;

        string s1,s2;
        FOR(i,1,m)
        {
            cin>>s1>>s2;
            //cout<<s1<<' '<<s2<<' '<<con(s1)<<' '<<con(s2)<<endl;

            addedge(i,m+con(s1),1);
            if (s2!=s1)
                addedge(i,m+con(s2),1);
            addedge(s,i,1);
        }
        FOR(i,m+1,m+6)
        {
            addedge(i,t,sl);
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
        //cout<<MaxFlow()<<' '<<m<<endl;
        if (MaxFlow()==m) cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

