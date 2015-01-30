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
const int maxn = 10000;
struct ITNode
{
    int first;
    int sum;
    int d;
}IT[maxn];
int u,v,d;
int hs[maxn];

void extract(int node,int l,int r)
{
    int m = (l+r)/2;
    if (IT[node].d>0)
    {
        if (l<=m)
        {
            IT[node*2].d+=IT[node].d;
            IT[node*2].first=IT[node].first;
            IT[node*2].sum+=hs[m-l+1]*(IT[node].d);
        }
        if (m+1<=r)
        {
            IT[node*2+1].d+=IT[node].d;
            IT[node*2+1].first+=It[node].d*(m-l+2);
            IT[node*2+1].sum+=(hs[r-l+1]-hs[m-l+1])*d;
        }
        IT[node].d=0;

    }
}

void update(int node,int l,int r,int &u,int &v,int d)
{
    if (r<u||l>v) return;
    if (u<=l&&r<=v)
    {
        IT[node].first+=(l-u+1)*d;
        IT[node].d+=d;
        IT[node].sum+=(hs[r-u+1]-hs[l-u])*d;
        return;
    }
    int m = (r+l)/2;
    extract(node,l,r);
    update(node*2  ,l,m,u,v,d);
    update(node*2+1,m+1,r,u,v,d);
    IT[node].sum=IT[node*2].sum+IT[node*2+1].sum;
    IT[node].first=IT[node*2].first;
}

int get(int node,int l,int r,int &u,int &v)
{
    if (r<u||l>v) return 0;
    if (u<=l&&r<=v)
    {
        return IT[node].sum;
    }
    int m = (r+l)/2;
    extract(node,l,r);
    return get(node*2,l,m)+get(node*2+1,m+1,r);
}

int main()
{
    freopen("Interval6COCI.inp","r",stdin);
    cin>>n>>m;
    FOR(i,1,n) hs[i]=hs[i-1]+i;
    FOR(i,1,m)
    {
        cin>>q;
        if (q==1)
        {
            cin>>u>>v>>d;
            update(1,1,n,u,v,d);
        }
        else
        if (q==2)
        {
            cin>>u;
            cout<<get(1,1,n,1,u)<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

