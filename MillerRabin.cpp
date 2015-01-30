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
#define ll long long

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

bool isPrime( int n )
{
    if (n<2) return false;
    for(int i=2;i*i<=n;++i)
        if (n%i==0) return false;
    return true;
}

ll mulmod(ll a,ll b,ll c)
{
    ll x=0,y=a%c;
    while (b>0)
    {
        if (b%2==1) x=(x+y)%c;
        y=(y*2) % c;
        b/=2;
    }
    return x%c;
}

long long power(long long a,long long d,long long m)
{
    if (d==0) return 1%m;
    if (d%2==0)
    {
        long long x=power(a,d/2,m);
        return mulmod(x,x,m);
    }
    return mulmod(a,power(a,d-1,m),m);
}

long long random(long long n)
{
    return ((long long)rand()*rand())%n;
}

bool rabinMiller(long long n,long long k)
{
    if (n<=50) return isPrime(n);
    long long d=n-1,s=0;
    while (d%2==0){++s;d/=2;}
    FOR(i,1,k)
    {
        long long a=random(n-2)+2;
        long long x=power(a,d,n);
        if (x==1||x==n-1) continue;
        for(long long r=1;r<s;++r)
        {
            x=mulmod(x,x,n);
            if (x==1) return false;
            if (x==n-1) break;
        }
        if (x!=n-1) return false;
    }
    return true;
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    //FOR(i,1,100)
    //cout<<i<<' '<<rabinMiller(i,6)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

