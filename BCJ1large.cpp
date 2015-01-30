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

const int maxn=10000+10;
pair<long long ,long long > heap[maxn];

long long  top;
long long v[maxn];
long long t,e,r,n;

void swap(pair<long long ,long long > &a,pair<long long ,long long > &b)
{
    pair<long long ,long long > tg=a;a=b;b=tg;
}
void up_heap(long long  i)
{
    if (i==1||heap[i].first<heap[i/2].first) return;
    swap(heap[i],heap[i/2]);
    up_heap(i/2);
}
void down_heap(long long  i)
{
    long long  j=i*2;
    if (j>top) return;
    if (j<top&&heap[j].first<heap[j+1].first) j=j+1;
    if (heap[i].first<heap[j].first) swap(heap[i],heap[j]);
    down_heap(j);
}
void push(long long  val,long long  sl)
{
    top++;
    heap[top]=make_pair(val,sl);
    up_heap(top);
}

void pop()
{
    heap[1]=heap[top];
    top--;
    down_heap(1);
}
long long  sl;
long long res;
int  main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("BCJ1large.out","w",stdout);
    cin>>t;
    FOR(st,1,t)
    {
        cin>>e>>r>>n;
        FOR(i,1,n) cin>>v[i];
        res=0;
        FOR(i,1,n)
        if (i==1)
            res=res+(long long)e*v[i];
        else
            res=res+(long long)r*v[i];
        DOW(i,n,1)
        {
            if (i==1) sl=e-1; else sl=r;
            while(top>0&&heap[1].first>v[i])
            {
                long long  x=min(e-heap[1].second,sl);
                sl-=x;
                heap[1].second+=x;
                res=res-x*v[i]+x*heap[1].first;
                //cout<<x<<' '<<v[i]<<"->"<<heap[1].first<<' '<<sl<<' '<<heap[1].second<<endl;
                if (heap[1].second==e)
                {
                    //cout<<heap[1].first<<endl;
                    //cout<<top<<endl;
                    pop();
                    //cout<<heap[1].first<<endl;
                    //cout<<"con"<<top<<" "<<heap[1].first<<endl;
                }
                if (sl==0) break;
            }
            push(v[i],sl);
            //cout<<i<<' '<<top<<endl;
        }
        cout<<"Case #"<<st<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

