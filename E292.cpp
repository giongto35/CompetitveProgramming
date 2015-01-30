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
int IT[maxn*4];

int n,m;
int a[maxn],b[maxn];
int x,y,k,com;
int res;

void extract(int &node,int l,int r)
{
    if (IT[node]!=0)
    {
        IT[node*2]=IT[node];
        l=(r-l+1);
        IT[node*2+1]=IT[node]+(l+1)/2;
        IT[node]=0;
    }
}

void update(int node,int l,int r,int u,int v,int &gt)
{
    if (r<u||l>v) return;
    if (u<=l&&r<=v)
    {
        IT[node]=gt+l-u;
        return;
    }
    int mid = (l+r)>>1;
    extract(node,l,r);
    update(node<<1,l,mid,u,v,gt);
    update((node<<1) +1,mid+1,r,u,v,gt);
}

void get(int node,int l,int r,int &u)
{
    if (u<l||u>r) return;
    if (l==r)
    {
        res=IT[node];
        return;
    }
    int mid =(l+r)>>1;
    extract(node,l,r);
    get((node<<1),l,mid,u);
    get((node<<1)+1,mid+1,r,u);
}

int main()
{
    //freopen("E292.inp","r",stdin);
    //freopen("E292.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) cin>>b[i];
    FOR(i,1,m)
    {
        cin>>com;
        if (com==1)
        {
            cin>>x>>y>>k;
            update(1,1,n,y,y+k-1,x);
        }
        else
        {
            cin>>x;
            res=0;
            get(1,1,n,x);
            if (res==0) cout<<b[x]<<endl;
            else cout<<a[res]<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

