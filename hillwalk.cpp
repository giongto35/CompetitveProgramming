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
const int maxn=100000+10;
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
} l[maxn];
int heap[maxn];
int pos[maxn];
int cur;
int top;
int n;
int cvt;
int res;
struct event
{
    int t;
    int u;
    int x;
} e[maxn*2];
double calc(int i)
{
    return l[i].y1+(l[i].y2-l[i].y1+0.0)*(cvt-l[i].x1+0.0)/(l[i].x2-l[i].x1+0.0);
}
void doicho(int a,int b)
{
    int tg=heap[a];heap[a]=heap[b];heap[b]=tg;
    pos[heap[a]]=a;
    pos[heap[b]]=b;
}
void up_heap(int i)
{
    if ((i==1)||calc(heap[i])<calc(heap[i/2])) return;
    doicho(i,i/2);
    up_heap(i/2);
}
void down_heap(int i)
{
    int j=i*2;
    if (j>top) return;
    if (j<top&&calc(heap[j])<calc(heap[j+1])) j++;
    if (calc(heap[i])<calc(heap[j])) doicho(i,j);
    down_heap(j);
}
void push(int u)
{
    heap[++top]=u;
    pos[u]=top;
    up_heap(top);
}
int pop(int v)
{
    if (v==0) return 0;
    int ret=heap[v];
    heap[v]=heap[top];
    pos[heap[v]]=v;
    pos[heap[top]]=0;
    top--;
    up_heap(v);
    down_heap(v);
    return ret;
}

bool mycmp(event a,event b)
{
    return a.x<b.x;
}
int main()
{
    freopen("hillwalk.in","r",stdin);
    freopen("hillwalk.out","w",stdout);
    cin>>n;
    int spt=0;
    FOR(i,1,n)
    {
        cin>>l[i].x1>>l[i].y1>>l[i].x2>>l[i].y2;
        if (l[i].x1==0&&l[i].y1==0) cur=i;
        e[++spt].x=l[i].x1;
        e[spt].t=0;
        e[spt].u=i;
        e[++spt].x=l[i].x2;
        e[spt].t=1;
        e[spt].u=i;
    }
    sort(e+1,e+1+spt,mycmp);
    e[0].x=-12312;
    e[spt+1].x=12312;
    int bd,kt;
    res=1;
    FOR(i,1,spt)
    {
//        cout<<e[i].x<<' '<<e[i].t<<' '<<e[i].u<<endl;
        if (e[i].x!=e[i-1].x) bd=i;
        if (e[i].x!=e[i+1].x)
        {
            cvt=e[i].x;
            kt=i;
            bool dropped=false;
            FOR(j,bd,kt)
                if (e[j].t==1)
                {
                    pop(pos[e[j].u]);
                    if (e[j].u==cur) dropped=true;
                }
            FOR(j,bd,kt)
                if (e[j].t==0)
                    if (calc(cur)>calc(e[j].u)) push(e[j].u);
            if (dropped==true)
            {
                if (top>0)
                {
                    cur=pop(1);
                    res++;
                }
                else
                break;
            }
        }
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

