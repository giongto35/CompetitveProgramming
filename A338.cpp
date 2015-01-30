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

const long long cmod = 1000000009;
long long n,m,k,s,res;


int modpow(int a,int n,int m)
{
    if (n==0) return 1;
    if (n%2==1)
        return ((long long)a*modpow(a,n-1,m))%m;
    else
    {
        long long x=modpow(a,n/2,m);
        return (x*x) %m;
    }
}
int main()
{
    //freopen("A338.inp","r",stdin);
    //freopen("A338.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    if (n-m>=n/k)
    {
        cout<<m<<endl;
        return 0;
    }
    long long s=n-m;
    long long left=n-s*k;
    long long sl=left/k;
    res=(((long long)modpow(2,sl+1,cmod)-2)*k)%cmod;
    //cout<<left%k<<' '<<s*(k-1)<<endl;
    res=((res+left%k)%cmod+s*(k-1))%cmod;
    cout<<(res%cmod+cmod)%cmod<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

