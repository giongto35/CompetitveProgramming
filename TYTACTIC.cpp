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
const int maxn=200000+10;
vector<int> ke[maxn];
bool used[maxn];
int IT[maxn*4];
char ch;
int vt1[maxn],vt2[maxn],cnt,u,v,d[maxn],n,m;
int a[maxn];

void DFS(int u)
{
    used[u]=true;
    cnt++;
    vt1[u]=cnt;
    d[cnt]=u;
    FOR(i,0,ke[u].size()-1)
    {
        int v=ke[u][i];
        if (used[v]==false)
        DFS(v);
    }
    cnt++;
    d[cnt]=u;
    vt2[u]=cnt;
}

int get(int node,int l,int r,int u,int v)
{
    if (v<l||u>r) return 0;
    if (u<=l&&r<=v) return IT[node];
    int mid=(l+r)/2;
    return get(node*2,l,mid,u,v)+get(node*2+1,mid+1,r,u,v);
}

void update(int node,int l,int r,int u,int &gt)
{
    if (u>r||u<l) return;
    if (u==l&&u==r)
    {
        IT[node]=gt;
        return;
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,u,gt);
    update(node*2+1,mid+1,r,u,gt);
    IT[node]=IT[node*2]+IT[node*2+1];
}

int main()
{
    //freopen("TYTACTIC.inp","r",stdin);
    //freopen("TYTACTIC.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1)
    {
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    memset(used,false,sizeof(used));
    DFS(1);
    FOR(i,1,n) update(1,1,cnt,vt1[i],a[i]);
    FOR(i,1,m)
    {
        cin>>ch;
        if (ch=='Q') cin>>u,cout<<get(1,1,cnt,vt1[u],vt2[u])<<endl;
        else
            if (ch=='U') cin>>u>>v,update(1,1,cnt,vt1[u],v);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

