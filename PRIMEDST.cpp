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

const int maxn = 50000+10;
VI ke[maxn];
int n,u,v,cnt;
int RP[maxn],sprime;
bool prime[maxn];
bool used[maxn];
int p[maxn];
int d[maxn],In[maxn],Out[maxn];
map<int,int> F[maxn];
map<int,int>::iterator itr;
long long res;

int bnrsearch(int v)
{
    int l=1;
    int r=sprime;
    int res=sprime+1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (p[mid]>=v)
        {
            res=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return res;
}

void merge(int x,int y,int r)
{
    int u = RP[x];
    int v = RP[y];
    if (F[u].size()<F[v].size())
    {
        int tg=u;u=v;v=tg;
        RP[x]=RP[y];
    }
    else
        RP[y]=RP[x];

    FOREACH(it,F[v])
    {
        itr=F[u].begin();
        int bd=bnrsearch((*itr).first+(*it).first-d[r]*2 );
        //cout<<bd<<endl;
        FOR(j,bd,sprime)
        {
            int l=p[j]+d[r]*2-(*it).first;
            //p[j]+d[r]*2-(*it).first>=v
            //<=>p[j]>=v+(*it).first-d[r]*2;
            if (l>=(*itr).first)
            {

                if (F[u][l]==0) break;
                res=res+(long long)F[u][l]*((*it).second);
            }
        }
    }
    //push v to u
    FOREACH(it,F[v])
        F[u][(*it).first]+=(*it).second;

    F[v].clear();
}

void DFS(int u)
{
    cnt++;
    //In[u]=cnt;
    used[u]=true;
    RP[u]=u;
    F[u][d[u]]=1;
    FOR(i,0,ke[u].size()-1)
    {
        int v=ke[u][i];
        if (used[v]==false)
        {
            d[v]=d[u]+1;
            DFS(v);
            merge(u,v,u);
        }
    }
    //Out[u]=cnt;
}

void BruteForce()
{
    long long res=0;
    FOR(i,1,n)
    FOR(j,i+1,n)
    {
        int par=1;
        FOR(k,1,n)
        if (In[k]<=In[i]&&Out[k]>=Out[i]&&In[k]<=In[j]&&Out[k]>=Out[j])
        {
            if (d[k]>d[par]) par=k;
        }
        //cout<<i<<' '<<j<<' '<<par<<endl;
        if (prime[d[i]+d[j]-d[par]*2]) res++;
    }
    cout<<res<<endl;
}

void primelisting(int n)
{
    memset(prime,true,sizeof(prime));
    int i=2;
    while (i*i<=n)
    {
        int j=i*i;
        while (j<=n)
        {
            prime[j]=false;
            j+=i;
        }
        i++;
    }
    sprime=0;
    prime[1]=false;
    FOR(i,2,n)
    if (prime[i]) p[++sprime]=i;
}

int main()
{
    //freopen("PRIMEDST.inp","r",stdin);
    //freopen("PRIMEDST.out","w",stdout);
    scanf("%d",&n);
    primelisting(n);
    FOR(i,1,n-1)
    {
        scanf("%d%d",&u,&v);
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    DFS(1);
    //cout<<res<<endl;
    long long mau=(long long)n*(n-1)/2;
    cout<<fixed<<setprecision(6)<<(res+0.0)/mau<<endl;
    //BruteForce();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

