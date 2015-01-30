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
const int maxn = 100;
const long long oo = 10000000000000LL;
long long F[maxn][maxn];
long long s[maxn];
long long n,t,x,m;
long long res;

void calc(int vt,long long n,long long x)
{
    if (n==0) return;
    if (x==0) return;
    if (n<=2)
    {
        res+=(n==x);
        return;
    }
    if (n>s[vt-1])
    {
        res+=F[vt-1][x];
        calc(vt-1,n-s[vt-1],x-1);
    }
    else
    {
        calc(vt-1,n,x);
    }
}

void process()
{
    s[1]=2;
    m=1;
    while (s[m]*2<oo) s[++m]=s[m-1]*2;
    F[1][1]=1;
    F[1][2]=1;

    FOR(i,2,m)
    FOR(j,1,i+1)
    {
        F[i][j]=F[i-1][j]+F[i-1][j-1];
    }
    int vt=0;
    FOR (i,1,m) if (s[i]<=n) n-=s[i],res+=F[i][x],vt=i;
    //cout<<m<<endl;
    calc(vt+1,n,x);
    cout<<res;
}

int main()
{
    //freopen("C261.inp","r",stdin);
    //freopen("C2612.out","w",stdout);
    cin>>n>>t;
    x=1;
    while (t % 2 == 0) t/=2,x++;
    if (t!=1) cout<<0;
    else
        process();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
