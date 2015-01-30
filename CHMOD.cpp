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
const int maxn = 100000+10;
const int maxp = 30;
int p[maxn];
int a[maxn];
int c[maxn][maxp];
int sp,q,m,l,r,n;

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
    //freopen("CHMOD.inp","r",stdin);
    //freopen("CHMOD.out","w",stdout);
    FOR(i,2,100)
        {
            p[++sp]=i;
            FOR(j,2,sqrt(i))
                if (i%j==0) {
                    sp--;
                    break;
                }
        }
        //cout<<sp;
    //FOR(i,1,sp) cout<<p[i]<<' ';
    cin>>n;
    FOR(i,1,n)
    {
        scanf("%d",&a[i]);
        FOR(j,1,sp)
        {
            while (a[i]%p[j]==0)
            {

                c[i][j]++;
                a[i]/=p[j];
            }
        }
        FOR(j,1,sp)
            c[i][j]=c[i-1][j]+c[i][j];
    }
    scanf("%d",&q);
    FOR(i,1,q)
    {
        scanf("%d%d%d",&l,&r,&m);
        long long res=1;
        FOR(j,1,sp)
        res=(res*modpow(p[j],c[r][j]-c[l-1][j],m))%m;
        printf("%d\n",res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

