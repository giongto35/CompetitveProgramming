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
vector<int> a[maxn];
vector<int> b[maxn];
int spt;
int IT1[maxn],IT2[maxn];
int s;

void extract(int node,int &IT[maxn])
{
    if (IT[node]!=0)
    {
        IT[node*2]+=It[node];
        IT[node*2+1]+=IT[node];
    }
}

void update(int node,int l,int r,int u,int v,int &IT[maxn])
{
    if (v<l||u>r) return ;
    if (u<=l&&r<=v)
    {
        IT[node]+=x;
        return;
    }
    int m=(l+r)/2;
    extract(node,IT);
    update(node*2,l,m,u,v,x);
    update(node*2+1,m+1,r,u,v,x);
}

void get(int node,int l,int r,int u,int &IT[maxn])
{
    if (l>r) return 0;
    if (l==u&&u==r)
    {
        s=IT[node];
        break;
    }
    int m=(l+r)/2;
    extract(node,IT);
    get(node*2,l,m,u);
    get(node*2+1,m+1,r,u);
}

int main()
{
    freopen("E276.inp","r",stdin);
    freopen("E276.out","w",stdout);
    cin>>n>>q;
    FOR(i,1,n-1)
    {
        cin>>u>>v;
        a[u].push_back(v);
    }

    FOR(i,0,a[1].size()-1)
    {
        spt++;
        u=a[1][i];
        tr=1;
        while (u!=-1)
        {
            b[spt].push_back(u);
            u=-1;
            FOR(i,0,a[u].size()-1)
            if (a[u][i]!=tr)
            {
                u=a[u][i];
                break;
            }
        }
    }
    FOR(i,1,q)
    {
        cin>>com;
        if (com==0)
        {
            cin>>v>>x>>d;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

