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
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const int maxn=100000+10;
int al[maxn],ar[maxn],a[maxn],sl,sr;
int lal[maxn],lar[maxn];
int sq;
int IT[maxn*4];
vector<int> q[maxn];
bool c[maxn];
int b[maxn];
int ans;
vector<int> listar[maxn];
int u,n,m;

int getmin(int node,int l,int r,int u,int v)
{
    if (v<l||u>r) return 0;
    if (u<=l&&r<=v)
        return IT[node];
    int mid=(l+r)/2;
    int s1=getmin(node*2,l,mid,u,v);
    int s2=getmin(node*2+1,mid+1,r,u,v);
    if (ar[s1]<ar[s2]) return s1;else return s2;
}

void build(int node,int l,int r)
{
    if (l>r) return ;
    if (l==r)
    {
        if (listar[l].empty())IT[node]=0;
        else
        IT[node]=listar[l].back();

        return;
    }
    int mid = (l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    if (ar[IT[node*2]]<ar[IT[node*2+1]]) IT[node]=IT[node*2];else IT[node]=IT[node*2+1];
}

void del(int node,int l,int r,int u)
{
    if (u<l||u>r) return ;
    if (u==l&&u==r)
    {
        if (listar[u].empty())IT[node]=0;
        else
        IT[node]=listar[u].back();
        return;
    }
    int mid = (l+r)/2;
    del(node*2,l,mid,u);
    del(node*2+1,mid+1,r,u);
    if (ar[IT[node*2]]<ar[IT[node*2+1]]) IT[node]=IT[node*2];else IT[node]=IT[node*2+1];
}

int getleft(int u)
{
    if (lal[u]==u) return u;
    lal[u]=getleft(lal[u]);
    return lal[u];
}

int getright(int u)
{
    if (lar[u]==u) return u;
    lar[u]=getright(lar[u]);
    return lar[u];
}

bool mycmp(int u,int v)
{
    return ar[u]>ar[v];
}

int main()
{
    //freopen("SEABALlarge.inp","r",stdin);
    //freopen("SEABAL.out","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    al[0]=1000000;
    ar[0]=1000000;
    FOR(i,1,m)
    {
        scanf("%d%d",&al[i],&ar[i]);
        listar[al[i]].push_back(i);
    }
    FOR(i,1,n) sort(listar[i].begin(),listar[i].end(),mycmp);
    build(1,1,n);
    a[0]=1000000000;
    a[n+1]=1000000000;
    FOR(i,1,n) lal[i]=i,lar[i]=i;
    //FOR(i ,1,n) if (listar[i].size()>0) cout<<i<<' '<<listar[i].back()<<endl;
    //return 0;
    scanf("%d",&sq);
    FOR(i,1,sq)
    {
        //cout<<i<<endl;
        scanf("%d",&u);
        u=u+ans;
        a[u]--;
        if (a[u]==0)
        {
            if (a[u-1]==0) lar[u-1]=u;
            if (a[u+1]==0) lar[u]=u+1;
            if (a[u+1]==0) lal[u+1]=u;
            if (a[u-1]==0) lal[u]=u-1;
            int pl=getleft(u);
            int pr=getright(u);
            while(true)
            {
                int u=getmin(1,1,n,pl,n);
                //cout<<ar[u]<<' '<<pr<<endl;
                if (u!=0&&ar[u]<=pr)
                {
                //cout<<u<<endl;
                    listar[al[u]].pop_back();//pop u
                    del(1,1,n,al[u]);
                    ans++;
                }
                else break;
            }
        }
        cout<<ans<<endl;
    }
    //FOR(i,1,m) cout<<c[i]<<endl;
    //cout<<sum2(1,n)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

