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
const long long oo=100000000000000000ll;
const int maxn = 100000+10;
vector<int> ke[maxn];
long long w[maxn];
bool used[maxn];
long long F[maxn];
long long sum;
bool kt;
bool leaf[maxn];
long long gtmin;
int n,u,v;

long long GCD(long long a,long long b)
{
    if (b==0) return a; else return GCD(b,a%b);
}

long long LCM(long long a,long long b)
{
    return a*b/GCD(a,b);
}

void DFS(int u,int p)
{
    if (ke[u].size()==1) {leaf[u]=true;F[u]=1;return;}
    F[u]=1;
    FOR(i,0,ke[u].size()-1)
    {
        int v=ke[u][i];
        if (v!=p)
        {
            DFS(v,u);
            if (kt) return;
            w[u]=w[u]+w[v];
        }
    }

    FOR(i,0,ke[u].size()-1)
    {
        int v=ke[u][i];
        if (v!=p)
        {
            F[u]=LCM(F[u],F[v]);
            if (F[u]>w[u])
            {
                kt=true;
                return;
            }
        }
    }

    F[u]=F[u]*(ke[u].size()-1);
        if (F[u]>w[u])
            {
                //cout<<u<<' '<<F[u]<<' '<<w[u]<<endl;
                kt=true;
                return;
            }
    if (kt) return;
}

void DFS2(int u,int p)
{
    gtmin=min(gtmin,w[u]/F[u]);
    FOR(i,0,ke[u].size()-1)
    {
        int v=ke[u][i];
        if (v!=p)
        {
            F[v]=F[u]/(ke[u].size()-1);
            DFS2(v,u);
        }
    }
}

int main()
{
    freopen("B348.inp","r",stdin);
    //freopen("B348.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) {scanf("%d",&w[i]),sum+=w[i];}
    FOR(i,1,n-1)
    {
        scanf("%d%d",&u,&v);
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    ke[1].push_back(0);
    kt=false;
    DFS(1,0);
    //FOR(i,1,n) cout<<i<<' '<<F[i]<<endl;
    if (kt) {cout<<sum;return 0;}
    gtmin=oo;
    DFS2(1,0);
    //FOR(i,1,n) cout<<i<<' '<<F[i]<<endl;
    long long res=0;
    FOR(i,1,n) if (leaf[i]) res=res+w[i]-F[i]*gtmin;
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

