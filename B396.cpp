//prime testing
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

int T,n;

int pow (int x, int n, int mod) {
    if (n == 0) return 1;

    int p = pow (x, n / 2, mod);

    p = (long long) p * p % mod;
    if (n % 2) p = (long long) p * x % mod;

    return p;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    for (int rep = 1; rep <= 50; rep ++) {
        int x = rand() % (n - 2) + 2;
        int p = pow(x, n - 1, n);

        if (p != 1) return false;
    }

    return true;
}


int findu(int n)
{
    while (n >= 2)
        {
            if (isPrime(n) == 1) return n;
            n--;
        }
    return 2;
}

int findv(int n)
{
    while (true)
        {
            n++;
            if (isPrime(n) == 1) return n;
        }
}

void process()
{
    long long u = findu(n);
    long long v = findv(n);
    long long t = u + v - 1 - n;
    long long m = u * v;
    long long ugcd = __gcd(t,m);
    t /= ugcd;
    m /= ugcd;
    long long nt = m - 2 * t;
    long long nm = 2 * m;
    ugcd = __gcd(nt,nm);
    nt /= ugcd;
    nm /= ugcd;
    cout<<nt<<"/"<<nm<<endl;
}

int main()
{
    //freopen("B396.inp","r",stdin);
    //freopen("B396.out","w",stdout);
    scanf("%d",&T);
    for (int i = 1; i <= T; i++)
    {
        scanf("%d",&n);
        process();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

