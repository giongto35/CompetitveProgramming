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
const int maxn = 40000+10;
struct ITT
{
    int gtmin;
    int slmin;
    int val;
} IT[maxn*4];

struct point
{
    int x;
    int y;
} a[1000000+10];
const int oo=1000000000;
vector<int> v[maxn*4];
int T,n,W,H,P,Q,N,X,Y,ha,hb,hc,hd;
long long res;

void extract(int node)
{
    if (IT[node].val!=0)
    {
        IT[node*2].val    +=IT[node].val;
        IT[node*2].gtmin  +=IT[node].val;
        IT[node*2+1].val  +=IT[node].val;
        IT[node*2+1].gtmin+=IT[node].val;
        IT[node].val=0;
    }
}

void update(int node,int l,int r,int u,int &v,int gt)
{
    if (r<u||l>v) return ;
    if (u<=l&&r<=v)
    {
        IT[node].gtmin+=gt;
        IT[node].val+=gt;
        return ;
    }
    int m=(l+r)/2;
    extract(node);
    update(node*2  ,l,m,u,v,gt);
    update(node*2+1,m+1,r,u,v,gt);
    IT[node].gtmin=oo;
    if (l<=m)
    IT[node].gtmin=min(IT[node].gtmin,IT[node*2].gtmin);
    if (m+1<=r)
    IT[node].gtmin=min(IT[node].gtmin,IT[node*2+1].gtmin);
    IT[node].slmin=0;
    if (l<=m&&IT[node].gtmin==IT[node*2  ].gtmin) IT[node].slmin+=IT[node*2  ].slmin;
    if (m+1<=r&&IT[node].gtmin==IT[node*2+1].gtmin) IT[node].slmin+=IT[node*2+1].slmin;
}

void build(int node,int l,int r)
{
    if (l>r) return ;
    IT[node].gtmin=0;
    IT[node].val=0;
    IT[node].slmin=(r-l+1);
    if (l==r) return ;
    int m=(l+r)/2;
    build(node*2  ,l,m);
    build(node*2+1,m+1,r);
}

int main()
{
    freopen("dead_pixels.txt","r",stdin);
    freopen("deadpixel.out","w",stdout);
    cin>>T;
    FOR(ct,1,T)
    {
        cin>>W>>H>>P>>Q>>n>>X>>Y>>ha>>hb>>hc>>hd;
        FOR(i,0,H-1) v[i].clear();
        a[0].x=X;
        a[0].y=Y;
        v[a[0].y].push_back(a[0].x);
        FOR(i,1,n-1)
        {
            a[i].x=((long long)a[i-1].x*ha+(long long)a[i-1].y*hb+1)%W;
            a[i].y=((long long)a[i-1].x*hc+(long long)a[i-1].y*hd+1)%H;
            v[a[i].y].push_back(a[i].x);
        }
        //FOR(i,1,4*n) IT[i].gtmin=oo;
        W=W-P;
        build(1,0,W);
        FOR(i,0,Q-2)
        {
            FOR(j,0,v[i].size()-1)
            {
                update(1,0,W,max(0,v[i][j]-P+1),v[i][j],1);
//                            cout<<"add"<<i<<' '<<v[i][j]<<endl;
            }
        }
        res=0;
        FOR(i,Q-1,H-1)
        {
            FOR(j,0,v[i].size()-1)
                {
                    update(1,0,W,max(0,v[i][j]-P+1),v[i][j],1);
//                    cout<<"add"<<i<<' '<<v[i][j]<<endl;
                }
            if (i>=Q)
            FOR(j,0,v[i-Q].size()-1)
                {
                    update(1,0,W,max(0,v[i-Q][j]-P+1),v[i-Q][j],-1);
                    //cout<<"remove"<<i-Q<<' '<<v[i-Q][j]<<' '<<IT[1].slmin<<endl;
                }
            //cout<<i<<' '<<IT[1].gtmin<<endl;
            if (IT[1].gtmin==0) res+=IT[1].slmin;
        }
        //cout<<IT[1].gtmin<<endl;
        cout<<"Case #"<<ct<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

