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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 1000000+10;
vector<int> ke[maxn];
int IT[maxn*4][2];
int VIT[maxn*4][2];
int cnt;
int l[maxn],r[maxn];
int n,u,v,sq;

void extract(int node,int x)
{
    if (VIT[node][x]!=0)
    {
        IT[node*2][x]=IT[node*2+1][x]=IT[node][x];
        VIT[node*2][x]=VIT[node*2+1][x]=VIT[node][x];
        VIT[node][x]=0;
    }
}

void DFS(int u,int p=0)
{
    l[u]=++cnt;
    FOR(i,0,ke[u].size()-1)
    {
        if (ke[u][i]!=p)
        DFS(ke[u][i],u);
    }
    r[u]=++cnt;
}

int get(int node,int l,int r,int u,int v,int x)
{
    if (v<l||u>r) return 0;
    if (u<=l&&r<=v)
    {
        return IT[node][x];
    }
    int mid = (l+r)/2;
    extract(node,x);
    int res=max(get(node*2,l,mid,u,v,x),get(node*2+1,mid+1,r,u,v,x));
    IT[node][x]=max(IT[node*2][x],IT[node*2+1][x]);
    return res;
}

void update(int node,int l,int r,int u,int v,const int gt,int x)
{
    if (v<l||u>r) return;
    if (u<=l&&r<=v)
    {
        IT[node][x]=max(IT[node][x],gt);
        VIT[node][x]=gt;
        return;
    }
    int mid = (l+r)/2;
    extract(node,x);
    update(node*2,l,mid,u,v,gt,x);
    update(node*2+1,mid+1,r,u,v,gt,x);
    IT[node][x]=max(IT[node*2][x],IT[node*2+1][x]);
}

int main()
{
    //freopen("D343.inp","r",stdin);
    //freopen("D343.out","w",stdout);
    cin>>n;
    FOR(i,1,n-1)
    {
        scanf("%d%d",&u,&v);
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    DFS(1);
    //cout<<cnt<<' '<<IT[1]<<endl;
    scanf("%d",&sq);
    FOR(i,1,sq)
    {
        scanf("%d%d",&u,&v);
        if (u==1) update(1,1,cnt,l[v],r[v],i,0);
        else
        if (u==2) update(1,1,cnt,l[v],l[v],i,1);
        else
        {
            int x=get(1,1,cnt,l[v],l[v],0);
            int y=get(1,1,cnt,l[v],r[v],1);
            //cout<<x<<' '<<y<<endl;
            if (x<=y) cout<<"0"<<endl; else cout<<"1"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

