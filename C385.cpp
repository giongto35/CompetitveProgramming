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

const int maxn = 1000000+10;
const int maxp = 10000000+10;
int a[maxn];
int p[maxp];
bool prime[maxp];
int co[maxp];
int s[maxp];
int n ;
int spt;
int q;

void sieve(int n)
{
    memset(prime,true,sizeof(prime));
    int i = 2;
    spt= 0 ;
    while ((i * i) <= n)
    {
        int j = i * i;
        while (j <= n)
        {
            prime[j] = false;
            j += i;
        }
        i++;
    }

    FOR(i,2,n)
        if (prime[i])
        {
            p[++spt] = i;
            for(int j = i; j <= n; j+=i)
                s[spt] += co[j];
        }
}

int calc(int u)
{
    int l = 1;
    int r = spt;
    int res = 0;
    while (l <= r)
    {
        int mid = (l + r) /2 ;
        if (p[mid] <= u )
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return s[res];
}

int main()
{
    //freopen("C385.inp","r",stdin);
    //freopen("C385.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) {scanf("%d",&a[i]);co[a[i]]++;}
    scanf("%d",&q);
    sieve(10000000);
    FOR(i,1,spt) s[i] = s[i-1] + s[i];
    int l,r;
    FOR(i,1,q)
    {

        scanf("%d%d",&l,&r);
        cout<<calc(r) - calc(l-1)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

