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

bool isPrime(int n)
{
    if (n<2) return false;
    for (int i=2;i*i<=n;++i)
        if (n%i==0) return false;
    return true;
}

bool rabinMiller(long long n,int k)
{
    if (n<=50) return isPrime(n);
    int d=n-1,s=0;
    while (d%2==0) {++s;d/=2;}
    FOR(i,1,k)
    {
        int a=rand()%(n-2)+2;
        int x=power(a,d,n);
        if (x==1||x==n-1) continue;
        for(int r=1;r<s;r++)
        {
            x=((long long) x* x) % n;
            if (x==1) return false;
            if (x==n-1) break;
        }
        if (x!=n-1) return false;
    }
    return true;
}
int main()
{
    freopen("Fhalim.inp","r",stdin);
    freopen("Fhalim.out","w",stdout);
    cin>>T;
    FOR(i,1,T)
    {
        cin>>n;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

