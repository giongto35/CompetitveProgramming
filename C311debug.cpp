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
const long long oo = 1100000000000000000LL;
const int maxk = 10000+10;
const int maxn = 100000+10;
const int maxm = 100000+10;
int c[maxn];
long long a[maxn];
long long d[maxk];
bool avai[maxn];
int pos[maxk];
int heap[maxk];
int nheap,n,m,com;
long long x,y;
long long h;

struct mycmp{
bool operator()(int a,int b)
{
    if (c[a]==c[b]) return a<b;
    else
        return c[a]>c[b];
}
};
set<int,mycmp> s;
set<int,mycmp>::iterator it;
int k;
int g[maxn];

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

void dijkstra(int x)
{
    memset(pos,0,sizeof(pos));
    nheap=0;
    FOR(i,0,k-1) if (d[i]<oo) update(i);
    while (nheap>0)
    {
        int u=pop();
        //cout<<"ABC"<<u<<' '<<(u+x)%k<<endl;
        if (d[(u+x)%k]>d[u]+x)
        {
            d[(u+x)%k]=d[u]+x;
            update((u+x)%k);
        }
    }
    s.clear();
    FOR(i,1,n)
        if (avai[i])
            if (a[i]>=d[a[i]%k])
                s.insert(i);
}

int main()
{
    //freopen("C311.inp","r",stdin);
    //freopen("C311.out","w",stdout);
    cin>>h>>n>>m>>k;
    FOR(i,1,n)
    {
        cin>>a[i]>>c[i];
        avai[i]=true;
        if (a[i]%k==1%k) s.insert(i);
    }
    FOR(i,0,k-1) d[i]=oo;
    d[1%k]=1;//ti sua cai doan nay xem thu
    int cnt=0;
    FOR(i,1,m)
    {
        cin>>com;
        if (com==1)
        {
            cin>>x;
            g[++g[0]]=x;
            dijkstra(x);
        }
        else
        if (com==2)
        {
            cin>>x>>y;
            s.erase(x);
            c[x]=c[x]-y;
            //if (c[x]>=d[a[x]%k])
            s.insert(x);
        }
        else
        if (com==3)
        {
            //if (h==1444 ) cout<<d[22]<<endl;
            cnt++;
            if (h==1444&&cnt==11)
            {
                FOR(i,1,n)
                cout<<' '<<avai[i]<<' '<<c[i]<<'/'<<a[i]<<' '; cout<<endl;
                FOR(i,1,g[0])
                cout<<g[i]<<' '; cout<<endl;
                cout<<"ABC "<<136%k<<' '<<d[136%k]<<endl;
                cout<<"ABC "<<s.size()<<endl;
                cout<<"ABC "<<avai[n]<<endl;
            }
            it=s.begin();
            if (it==s.end()) cout<<0<<endl; else
            {
                cout<<c[*it]<<endl;
                avai[*it]=false;
                s.erase(it);
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
