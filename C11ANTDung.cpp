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
} b[maxn],a[maxn],ls,rs;
struct event
{
    double s;
    double t;
    int c;
    double v;
} e[maxn];
int next[maxn];
int prev[maxn];
int spt,se,n;
double l,r;
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
    return (a[u].s-a[v].s+0.0)/(a[v].v-a[u].v);
}


void push(int u)
{
    s.insert(make_pair(u,calc(u,next[u]) ));
}

bool mycmp(ant a,ant b)
{
    if (a.s==b.s) return a.v<b.v; else
    return a.s<b.s;
}

void LietKeLeft(int t)
{
    s.clear();
    sort(b+1,b+1+n,mycmp);
    a[0].v=oo;
    spt=0;
    FOR(i,1,n)
    {
        if (b[i].v<a[spt].v)
        {
            spt++;
            a[spt].s=b[i].s;
            a[spt].v=b[i].v;
        }
    }
    //FOR(i,1,spt) cout<<a[i].s<<' '<<a[i].v<<'/';cout<<endl;
    if (t==1) ls.s=a[1].s,ls.v=a[1].v;else rs.s=-a[1].s,rs.v=-a[1].v;
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
        remove(u);
        if (prev[u]!=0)
            push(prev[u]);
        else
        {
            se++;
            e[se].s=a[next[u]].s;
            e[se].v=a[next[u]].v;
            e[se].t=calc(u,next[u]);
            e[se].c=t;
            //e[  se].v=a[u].s+a[u].v*e[se].t;
            if (t==2)
            {
                e[se].v=-e[se].v;
                e[se].s=-e[se].s;
            }
        }
    }
}

bool mycmpgreater(ant a,ant b)
{
    if (a.s==b.s) return a.v>b.v; else
    return a.s>b.s;
}

bool cmpe(event a,event b)
{
    if (a.t==b.t) return a.c<b.c;
    return a.t<b.t;
}

void process()
{

    sort(e+1,e+1+se,cmpe);
    e[se+1].t=-1231232;
    //cout<<l<<' '<<r<<' '<<0<<endl;
    FOR(i,1,se)
    {
        if (e[i].c==1) ls.s=e[i].s,ls.v=e[i].v;
        if (e[i].c==2) rs.s=e[i].s,rs.v=e[i].v;
        //cout<<"abc "<<e[i].v<<' '<<e[i].t<<' '<<e[i].c<<endl;
        //cout<<"left/right : "<<ls.s<<' '<<rs.s<<' '<<e[i].t<<endl;
        if (abs(e[i].t-e[i+1].t)>0.0000001)
        {
            //cout<<l<<' '<<r<<' '<<e[i].t<<endl;
            res=min(res,(rs.s+rs.v*e[i].t)-(ls.s+ls.v*e[i].t));
        }
    }
}

int main()
{
    //freopen("C11ANT.inp","r",stdin);
    //freopen("C11ANT.out","w",stdout);
    cin>>n;
    l=oo;r=-oo;
    FOR(i,1,n)
    {
        cin>>b[i].s;
        if (l>b[i].s) l=b[i].s;
        if (r<b[i].s) r=b[i].s;
    }
    res=r-l;
    FOR(i,1,n) cin>>b[i].v;
    LietKeLeft(1);
    FOR(i,1,n) b[i].s=-b[i].s;
    FOR(i,1,n) b[i].v=-b[i].v;
    LietKeLeft(2);

    process();
    //cout<<res<<endl;
    printf("%0.3f",res/2);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

