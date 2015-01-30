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
int l[maxn],r[maxn];

int SIT[maxn*4];
int d[maxn];
int cnt;
int u,v,n,sq;
int sum;
void Extract(int node)
{
    if (SIT[node]==0)
    {
        SIT[node*2]=0;
        SIT[node*2+1]=0;
    }
}
void DFS(int u,int p=-1)
{
    l[u]=++cnt;
    d[cnt]=u;
    FOR(i,0,ke[u].size()-1)
    {
        if (ke[u][i]!=p)
        DFS(ke[u][i],u);
    }
    r[u]=++cnt;
    d[cnt]=u;
}

void build(int node,int l,int r)
{
    if (l>r) return ;
    if (l==r)
    {
        SIT[node]=1;
        return;
    }
    int mid = (l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    SIT[node]=SIT[node*2]+SIT[node*2+1];
}

void update1(int node,int l,int r,int u,int v)
{
    if (v<l||u>r) return;
    Extract(node);
    if (u<=l&&r<=v)
    {
        SIT[node]=0;
        return;
    }
    int mid = (l+r)/2;
    update1(node*2,l,mid,u,v);
    update1(node*2+1,mid+1,r,u,v);
    SIT[node]=SIT[node*2]+SIT[node*2+1];
}

void update2(int node,int l,int r,int u)
{

    if (u<l||u>r) return;
    Extract(node);
    if (l==u&&u==r)
    {
        //cout<<node<<' '<<l<<' '<<r<<' '<<SIT[node]<<endl;
        SIT[node]++;
        return;
    }
    int mid = (l+r)/2;
    update2(node*2,l,mid,u);
    update2(node*2+1,mid+1,r,u);
    SIT[node]=SIT[node*2]+SIT[node*2+1];
}

void get(int node,int l,int r,int u,int v)
{
    if (v<l||u>r) return;
    if (u<=l&&r<=v)
    {
        //cout<<l<<' '<<r<<' '<<u<<' '<<v<<endl;
        sum+=SIT[node];
        return;
    }
    int mid = (l+r)/2;
    Extract(node);
    get(node*2,l,mid,u,v);
    get(node*2+1,mid+1,r,u,v);
    SIT[node]=SIT[node*2]+SIT[node*2+1];
}


int main()
{
    freopen("D343.inp","r",stdin);
    freopen("D3432.out","w",stdout);
    cin>>n;
    FOR(i,1,n-1)
    {
        scanf("%d%d",&u,&v);
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    DFS(1);
    //FOR(i,1,n) cout<<l[i]<<' '<<r[i]<<endl;
    build(1,1,cnt);
    cin>>sq;
    FOR(i,1,sq)
    {
        scanf("%d%d",&u,&v);
        //cout<<"SIT[1] "<<SIT[1]<<endl;
        //cout<<u<<' '<<v<<endl;
        if (u==1)
            update1(1,1,cnt,l[v],r[v]);
        if (u==2)
            update2(1,1,cnt,l[v]);
        if (u==3)
        {
            sum=0;
            get(1,1,cnt,l[v],r[v]);
            //cout<<sum<<' '<<co<<endl;
            if (sum==0)
                cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
