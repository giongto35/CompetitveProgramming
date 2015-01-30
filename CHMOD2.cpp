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
const int maxc=100+10;
int n,m,a[maxn],l,r;
long long res;
int cnt[maxn][maxc];

int modpow(const int a,const int n,const int m)
{
    if (n==0) return 1;
    if (n%2==1) return ((long long)modpow(a,n-1,m)*a)% m;
    else
    {
        long long s=modpow(a,n/2,m);
        return (s*s)%m;
    }
}

int main()
{
    freopen("CHMOD.inp","r",stdin);
    freopen("CHMOD.out","w",stdout);
    cin>>n;
    FOR(i,1,n)
    {
        scanf("%d",&a[i]);
        FOR(j,1,100)
        cnt[i][j]=cnt[i-1][j];
        cnt[i][a[i]]++;
    }
    scanf("%d",&m);
    FOR(i,1,m)
    {
        scanf("%d%d%d",&l,&r,&m);
        if (r-l<=100)
        {
            res=1%m;
            FOR(j,l,r) res=(res*a[j])%m;
        }
        else
        {
            res=1%m;
            FOR(j,1,100)
                res=(res*modpow(j,cnt[r][j]-cnt[l-1][j],m))%m;
        }
        printf("%d\n",res%m);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
