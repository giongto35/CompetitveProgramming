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
const int maxn = 1100;
const int oo = 1000000000;
vector<int> ke[maxn];
int d[maxn];
int pos[maxn];
int nheap;
int heap[maxn];
int k,n,u,v;

void update(int v)
{
    int parent,child;
    child=pos[v];
    if (child==0)
    {
        nheap++;
        child=nheap;
    }
    parent=child/2;
    while (parent>0&&d[heap[parent]]>d[v])
    {
        heap[child]=heap[parent];
        pos[heap[child]]=child;
        child=parent;
        parent=child/2;
    }
    heap[child]=v;
    pos[v]=child;
}

int pop()
{
    int res=heap[1];
    int v=heap[nheap];
    nheap--;
    int r=1;
    while (r*2<=nheap)
    {
        int c=r*2;
        if (c<nheap&&d[heap[c+1]]<d[heap[c]]) c++;
        if (d[v]<d[heap[c]]) break;
        heap[r]=heap[c];
        pos[heap[r]]=r;
        r=c;
    }
    heap[r]=v;
    pos[v]=r;
    return res;
}

void dijkstra()
{
    FOR(i,1,k) d[i]=oo;
    d[1]=0;
    update(1);
    while (nheap>0)
    {
        int u=pop();
        if (u==k) break;
        FOR(i,0,ke[u].size()-1)
        {
            int v=ke[u][i];
            int l=abs(u-v);
            int t=d[u];
            if (u>v) t=t-l;
            if (d[u]%(2*l)==0) t=d[u]/(2*l);else t=d[u]/(2*l)+1;
            t=t*(2*l)+l;
            if (d[v]>t)
            {
                d[v]=t;
                update(v);
            }
        }
    }
    cout<<d[k]*5;
}

int main()
{
    //freopen("MELE3.inp","r",stdin);
    //freopen("MELE3.out","w",stdout);
    cin>>k>>n;
    FOR(i,1,n)
    {
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    dijkstra();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

