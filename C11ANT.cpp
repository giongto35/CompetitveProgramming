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

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int oo=1000000000+10;
const int maxn=100000+10;
struct ant
{
    int s;
    int v;
} b[maxn],a[maxn];
struct event
{
    double t;
    int c;
    double v;
} e[maxn*4];
int next[maxn];
int prev[maxn];
int spt,se,n;
bool used[maxn];
double res;
struct cmp
{
    bool operator()( pair<int,double> a, pair<int,double> b)  {
        return a.second<=b.second;
    }
};

set<pair<int,double>,cmp > s;

void remove(int u)
{
    used[u]=true;
    next[prev[u]]=next[u];
    prev[next[u]]=prev[u];
}

double calc(int u,int v)
{
    if (a[v].v==a[u].v&&a[u].s==a[v].s) return oo;
    return (a[u].s-a[v].s+0.0)/(a[v].v-a[u].v);
}


void push(int u)
{
    s.insert(make_pair(u,calc(u,next[u]) ));
}

void LietKeLeft()
{
    set<pair<int,double>,cmp >::iterator it;
    int u;
    FOR(i,1,spt) next[i]=i+1,prev[i]=i-1;
    FOR(i,1,spt-1) push(i);
    memset(used,false,sizeof(used));
    while (s.size() > 0)
    {
        do
        {
            if (s.size()==0) return;
            it=s.begin();
            u=(*it).first;
            s.erase(it);
        } while (used[u]==true||used[next[u]]==true);
        //cout<<"ABC"<<u<<' '<<next[u]<<' '<<calc(u,next[u])<<endl;
        //cout<<calc(u,next[u])<<endl;
        remove(u);
        if (prev[u]!=0)
            push(prev[u]);
        else
        {
            e[++se].t=calc(u,next[u]);
            e[  se].c=1;
            e[  se].v=a[u].s+a[u].v*e[se].t;
            //cout<<"ABC"<<u<<' '<<next[u]<<' '<<e[se].t<<' '<<e[se].c<<' '<<e[se].v<<endl;
        }
    }
}

void LietKeRight()
{
    set<pair<int,double>,cmp >::iterator it;
    int u;
    s.clear();
    FOR(i,1,spt) next[i]=i+1,prev[i]=i-1;
    FOR(i,1,spt-1) push(i);
    memset(used,false,sizeof(used));
    while (s.size()>0)
    {
        do
        {
            if (s.size()==0) return;
            it=s.begin();
            u=(*it).first;
            s.erase(it);
        } while (used[u]==true||used[next[u]]==true);
        u=(*it).first;
        double tmp=calc(u,next[u]);
        //cout<<"ABC"<<' '<<u<<' '<<next[u]<<' '<<calc(u,next[u])<<endl;
        remove(next[u]);
        if (next[u]!=n+1)
            push(u);
        else
        {
            e[++se].t=tmp;
            e[  se].c=2;
            e[  se].v=a[u].s+a[u].v*e[se].t;
            //cout<<"ABC"<<u<<' '<<next[u]<<' '<<e[se].t<<' '<<e[se].c<<' '<<e[se].v<<endl;
        }
    }
}

bool mycmp(ant a,ant b)
{
    if (a.s==b.s) return a.v<b.v; else
    return a.s<b.s;
}

bool cmpe(event a,event b)
{
    if (a.t==b.t) return a.c<b.c;
    return a.t<b.t;
}

void process()
{
    double l=a[1].s;
    double r=a[spt].s;
    res=r-l;
    sort(e+1,e+1+se,cmpe);
    e[se+1].t=-1231232;
    FOR(i,1,se)
    {
        if (e[i].t<=0) continue;
        if (e[i].c==1) l=e[i].v;
        if (e[i].c==2) r=e[i].v;
        cout<<l<<' '<<r<<' '<<e[i].t<<endl;
        if (abs(e[i].t-e[i+1].t)>0.0000001)
        {
            //cout<<l<<' '<<r<<' '<<e[i].t<<endl;
            res=min(res,r-l);
        }
    }
}

int main()
{
    freopen("C11ANT.inp","r",stdin);
    //freopen("C11ANT.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>b[i].s;
    FOR(i,1,n) cin>>b[i].v;
    sort(b+1,b+1+n,mycmp);
    a[0].v=oo;
    spt=0;
    FOR(i,1,n)
    {
        if (!(b[i].s==b[i-1].s&&b[i].v==b[i-1].v))
        {
            spt++;
            a[spt].s=b[i].s;
            a[spt].v=b[i].v;
        }
    }
    //FOR(i,1,spt) cout<<a[i].s<<' '<<a[i].v<<endl;
    LietKeLeft();
    LietKeRight();
    process();
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

