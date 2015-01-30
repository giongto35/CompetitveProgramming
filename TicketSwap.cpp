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

struct event
{
    int t;
    int c;
    int i;
};
vector<event> e;
using namespace std;
const int maxn = 1000+10;
const int cmod = 1000002013;
int a[maxn],l[maxn],r[maxn],p[maxn];
vector<int> bd[maxn];
vector<int> kt[maxn];
event st[maxn];
int s,t;
int T,n,m,top;
long long res,res2;

event make_event(int t,int c,int i)
{
    event u;
    u.t=t;
    u.c=c;
    u.i=i;
    return u;
}

bool mycmp(event u,event v)
{
    if (u.i==v.i) return u.t<v.t;
    return u.i<v.i;
}

long long calc(long long u)
{
    return (u*(u+1)/2)%cmod;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("TicketSwap.out","w",stdout);
    cin>>T;
    FOR(ct,1,T)
    {
        cin>>n>>m;
        top=0;
        res=0;
        res2=0;

        e.clear();
        e.push_back(make_event(0,0,-123));
        FOR(i,1,m)
        {
            cin>>l[i]>>r[i]>>p[i];
            e.push_back(make_event(1,p[i],l[i]));
            e.push_back(make_event(2,p[i],r[i]));
            res2=(res2+(long long)p[i]*calc(r[i]-l[i]))%cmod;
            //cout<<l[i]<<' '<<r[i]<<' '<<p[i]<<endl;
        }
        e.push_back(make_event(0,0,1000000000+10));
        sort(e.begin(),e.end(),mycmp);
        //FOR(i,0,e.size()-1) cout<<e[i].t<<' '<<e[i].c<<' '<<e[i].i<<endl;
        top=0;
        FOR(i,1,e.size()-2)
        {
            if (e[i].i!=e[i-1].i) s=i;
            if (e[i].i!=e[i+1].i)
            {
                t=i;
                FOR(j,s,t)
                {
                    if (e[j].t==1)
                        st[++top]=e[j];
                    else
                    {
                        int sum=e[j].c;
                        //cout<<j<<endl;
                        while (sum>0)
                        {
                            long long tg=min(sum,st[top].c);
                            //cout<<sum<<endl;
                            sum-=tg;
                            st[top].c-=tg;
                            //cout<<tg<<' '<<st[top].i<<' '<<e[j].i<<' '<<calc(e[j].i-st[top].i)<<endl;
                            res=(res+(tg*calc(e[j].i-st[top].i))%cmod)%cmod;
                            if (st[top].c==0) top--;
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<ct<<": "<<(res-res2+cmod)%cmod<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

