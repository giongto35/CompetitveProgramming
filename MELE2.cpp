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
const int maxn=100000+10;
const long long oo=1100000000000000000LL;
long long h;
int a[3];
int pos[maxn];
long long res;
int nheap;
long long d[maxn];
int heap[maxn];

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
    FOR(i,0,a[0]-1) d[i]=oo;
    d[1%a[0]]=1;
    update(1%a[0]);

    while (nheap>0)
    {
        int u=pop();
        FOR(i,0,2)
        {
            if (d[(u+a[i])%a[0]]>d[u]+a[i])
            {
                d[(u+a[i])%a[0]]=d[u]+a[i];
                update((u+a[i])%a[0]);
            }
        }
    }
}

int main()
{
    //freopen("MELE2.inp","r",stdin);
    //freopen("MELE2.out","w",stdout);
    cin>>h;
    cin>>a[0]>>a[1]>>a[2];
    dijkstra();
    FOR(i,0,a[0]-1)
    {
        if (h>=d[i])
        {
            //cout<<i<<' '<<d[i]<<endl;
            res=res+((h-d[i])/a[0]+1);
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

