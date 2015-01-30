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
const int maxp=100+10;
const int maxn=100000+10;
const long long oo=1000000000000000000;
long long F[maxp][maxn];
long long s[maxn];
long long n,m,p,h,t,bot,top;
long long d[maxn],a[maxn];
struct line
{
    long long a;
    long long b;
} G[maxn],l;

double Giao(line l1,line l2)
{
    return (l2.b-l1.b)/(l1.a-l2.a);
}

line ml(long long a,long long b)
{
    line x;
    x.a=a;
    x.b=b;
    return x;
}

int main()
{
    //freopen("B311.inp","r",stdin);
    //freopen("B3112.out","w",stdout);
    scanf("%d%d%d",&n,&m,&p);
    FOR(i,2,n) scanf("%d",&d[i]);
    FOR(i,2,n) d[i]=d[i-1]+d[i];
    FOR(i,1,m)
    {
        scanf("%d%d",&h,&t);
        a[i]=t-d[h];
    }
    sort(a+1,a+1+m);
    FOR(i,1,m) s[i]=s[i-1]+a[i];
    //FOR(i,1,m) cout<<a[i]<<' '<<s[i]<<endl;
    FOR(i,0,p) FOR(j,0,m) F[i][j]=oo;
    FOR(i,0,p) F[i][0]=0;
    FOR(i,1,p)
    {
        FOR(j,0,m)
        {
            FOR(k,0,j-1)
            {
                //cout<<i<<' '<<j<<' '<<a[j]*(j-k)<<' '<<s[j]-s[k]<<endl;
                F[i][j]=min(F[i][j],F[i-1][k]+a[j]*(j-k)-(s[j]-s[k]));
            }
        }
    }
    //FOR(k,1,p){ FOR(i,1,m) cout<<F[k][i]<<' '; cout<<endl;}
    cout<<F[p][m]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}




