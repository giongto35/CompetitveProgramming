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

int main()
{
    freopen("companys.inp","r",stdin);
    //freopen("companys.out","w",stdout);
    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        memset(sl,0,sizeof(sl));
        memset(C,false,sizeof(C));
        FOR(i,0,n-1) lab[i]=-1;
        FOR(i,1,m) scanf("%d%d%d%d",&E[i].u,&E[i].v,&E[i].c,&E[i].t);
        stest++;
        if (stest==11)
        {
            cout<<n<<' '<<m<<' '<<k<<endl;
            FOR(i,1,m) cout<<E[i].u<<' '<<E[i].v<<' '<<E[i].c<<' '<<E[i].t<<endl;
        }
        sort(E+1,E+1+m,mycmp);
        sres=1000000000;
        res=0;
        FOR(i,1,m)
        {
            int u=getroot(E[i].u);
            int v=getroot(E[i].v);
            if (u!=v)
            {
                res+=E[i].c;
                C[i]=true;
                sl[E[i].t]++;
                lab[u]=v;
            }
        }
        cout<<sl[0]<<' '<<sl[1]<<' '<<k<<endl;
        if (sl[0]<k)
        {
            res=0;
            FOR(i,0,n-1) lab[i]=-1;
            memset(sl,0,sizeof(sl));
            FOR(i,1,m) if (C[i]&&E[i].t==0) unite(i);
            /*
            FOR(i,1,m)
            {
                if (sl[0]==k) break;
                if (E[i].t==0) unite(i);
            }

            FOR(i,1,m) if (E[i].t==1) unite(i);*/
            FOR(i,1,m)
            {
                if (sl[1]==n-1-k) break;
                if (E[i].t==1) unite(i);
            }
            FOR(i,1,m) if (E[i].t==0) unite(i);
            cout<<sl[0]<<' '<<sl[1]<<' '<<k<<' '<<res<<endl;
        }
        else
        if (sl[1]<n-1-k)
        {
            res=0;
            FOR(i,0,n-1) lab[i]=-1;
            memset(sl,0,sizeof(sl));
            FOR(i,1,m) if (C[i]&&E[i].t==1) unite(i);
            FOR(i,1,m)
            {
                if (sl[1]==n-1-k) break;
                if (E[i].t==1) unite(i);
            }
            FOR(i,1,m) if (E[i].t==0) unite(i);
        }
        sres=min(sres,res);
        calc2();
        cout<<"Case "<<stest<<": "<<sres<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

