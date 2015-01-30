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
const int maxn=50000+10;
int lab[maxn];
int sl[2];
bool C[maxn*2];
int res,n,m,k;
int stest;
int sres;
struct edge
{
    int c;
    int u;
    int v;
    int t;
} E[maxn*2];


bool mycmp(edge a,edge b)
{
    return a.c<b.c;
}

int getroot(int u)
{
    if (lab[u]==-1) return u;
    else
        return lab[u]=getroot(lab[u]);
}

void unite(int i)
{
    int u=getroot(E[i].u);
    int v=getroot(E[i].v);
    if (u!=v)
    {
        sl[E[i].t]++;
        res+=E[i].c;
        lab[u]=v;
    }
}

void calc2()
{
    res=0;
    memset(sl,0,sizeof(sl));
    FOR(i,0,n-1) lab[i]=-1;
    FOR(i,1,m)
    {
        if (sl[0]==k) break;
        if (E[i].t==0) unite(i);
    }
    FOR(i,1,m)
    {
        if (sl[1]==n-1-k) break;
        if (E[i].t==1) unite(i);
    }
    //if (stest==11) cout<<sl[0]<<' '<<sl[1]<<' '<<res<<endl;

    if (sl[0]+sl[1]==n-1)
    sres=min(sres,res);

    res=0;
    memset(sl,0,sizeof(sl));
    FOR(i,0,n-1) lab[i]=-1;
    FOR(i,1,m)
    {
        if (sl[1]==n-1-k) break;
        if (E[i].t==1) unite(i);
    }
    FOR(i,1,m)
    {
        if (sl[0]==k) break;
        if (E[i].t==0) unite(i);
    }
    if (sl[0]+sl[1]==n-1)
    sres=min(sres,res);
    //if (stest==11) cout<<sl[0]<<' '<<sl[1]<<' '<<res<<endl;
}

bool check(int u)
{
    FOR(i,0,n-1) lab[i]=-1;
    sl[0]=0;sl[1]=0;
    res=0;
    FOR(i,1,m) if (C[i]) unite(i);
    if (u!=0&&getroot(E[u].u)==getroot(E[u].v)) return false;
    if (u!=0) unite(u);
    FOR(i,1,m) if (E[i].t==1) unite(i);
    FOR(i,1,m) if (E[i].t==0) unite(i);
    //cout<<u<<' '<<sl[0]<<' '<<sl[1]<<endl;
    if (sl[0]<=k) return true; else return false;
}

bool check2(int u)
{
    FOR(i,0,n-1) lab[i]=-1;
    sl[0]=0;sl[1]=0;
    res=0;
    FOR(i,1,m) if (C[i]) unite(i);
    if (u!=0&&getroot(E[u].u)==getroot(E[u].v)) return false;
    if (u!=0) unite(u);
    FOR(i,1,m) if (E[i].t==0) unite(i);
    FOR(i,1,m) if (E[i].t==1) unite(i);
    //cout<<u<<' '<<sl[0]<<' '<<sl[1]<<endl;
    if (sl[1]<=n-1-k) return true; else return false;
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("companys.out","w",stdout);
    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        memset(sl,0,sizeof(sl));
        memset(C,false,sizeof(C));
        FOR(i,0,n-1) lab[i]=-1;
        FOR(i,1,m) scanf("%d%d%d%d",&E[i].u,&E[i].v,&E[i].c,&E[i].t);
        stest++;
        sort(E+1,E+1+m,mycmp);
        int sl0=0;
        FOR(i,1,m)
        {
            if (E[i].t==0&&sl0<k)
            {
                if (check(i))
                {
                    sl0++;
                    C[i]=true;
                }
            }
        }
        //cout<<sl0<<endl;
        check(0);
        //cout<<' '<<sl[0]<<' '<<sl[1]<<' '<<k<<' '<<n-1-k<<endl;
        //cout<<res<<endl;
        sres=res;

        memset(C,false,sizeof(C));
        int sl1=0;
        FOR(i,1,m)
        {
            if (E[i].t==1&&sl1<n-1-k)
            {
                if (check2(i))
                {
                    sl1++;
                    C[i]=true;
                }
            }
        }
        //cout<<sl1<<endl;
        check2(0);
        //cout<<' '<<sl[0]<<' '<<sl[1]<<' '<<k<<' '<<n-1-k<<endl;
        cout<<"Case "<<stest<<": "<<min(sres,res)<<endl;
        if (stest==85) break;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

