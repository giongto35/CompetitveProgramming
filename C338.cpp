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

const int maxn = 10;
long long a[maxn],b[maxn];
long long d[maxn];
long long par[maxn];
long long res,n;
long long sp;
map<long long,int> F;
int sum;
int fact(long long u)
{
    long long so=u;
    if (F[so]>0) return F[so];
    long long i=2;
    long long res=0;
    while (i*i<=u)
    {
        while (u % i==0)
        {
            res++;
            u/=i;
        }
        i++;
    }
    if (u>1) res++;
    F[so]=res;
    return res;
}

void DFS(long long u)
{
    if (u==n+1)
    {
        long long sum=0;
        long long cnt=0;
        FOR(i,1,n) sum+=fact(a[i])+1,cnt=cnt+(par[i]==0);
        sum=sum+(cnt>1);
        res=min(res,sum-sp);
        return ;
    }
    FOR(i,0,u-1)
    if (i==0||a[i]%a[u]==0)
    {
        a[i]/=a[u];
        par[u]=i;
        DFS(u+1);
        par[u]=-1;
        a[i]*=a[u];
    }
}

int main()
{
    //freopen("C338.inp","r",stdin);
    //freopen("C338.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%I64d",&a[i]);
    sort(a+1,a+1+n,greater<long long>());
    FOR(i,1,n) b[i]=a[i];
    sp=n;

    FOR(i,1,n)
    {
        FOR(j,2,sqrt(a[i]))
        if (a[i]%j==0)
        {
            sp--;
            break;
        }
    }
    res=1000000;

    DFS(1);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

