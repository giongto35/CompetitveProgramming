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
const int cmod=1000000007;
long long GTT[maxn*2];
long long GTM[maxn*2];
long long n,m,g;

long long ModPow(long long a,long long n)
{
    if (n==0) return 1;
    if (n%2==1)
    {
        return ((long long)ModPow(a,n-1)*a)%cmod;
    }
    else
    {
        long long u=ModPow(a,n/2);
        return (u*u)%cmod;
    }
}

long long ModInverse(long long n)
{
    return ModPow(n,cmod-2);
}

long long C(long long n,long long u)
{
    if (u>n) return 0;
    return (((long long)GTT[n]*GTM[u])%cmod*GTM[n-u])%cmod;
}

long long calc(long long n,long long m)
{
    if (n<0||m<0) return 0;
    long long res=0;
    FOR(i,0,m/2)
    {
        long long cnt=i+n;
        long long u=m-i*2;
        //cout<<cnt<<' '<<n<<' '<<u<<endl;
        res=(res+(long long)C(cnt,n)*C(n,u)%cmod)%cmod;
    }
    return res;
}
int main()
{
    //freopen("D336.inp","r",stdin);
    //freopen("D336.out","w",stdout);
    cin>>m>>n>>g;
    if (m==0&&n==1&&g==1) cout<<1;
    else
    {

        GTT[0]=1;
        FOR(i,1,n+m+2) GTT[i]=((long long)GTT[i-1]*i)%cmod;
        FOR(i,0,n+m+2) GTM[i]=ModInverse(GTT[i]);
        m--;
        if (g==1) m--;
        cout<<(((long long)calc(n,m)+calc(n-1,m))%cmod+calc(n-2,m+1))%cmod;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
0 -> 10       n-1
     01-> 000 m-2
     11-> 100 n-1 m-1
1 -> 00

    xx01-> xx0
     0011 -> 000*/
//1 -> 00

//1 -> 00 -> 001 -> 0000
