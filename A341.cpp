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
long long a[maxn];
long long s[maxn];
long long rest;
long long n;
long long resm;
int main()
{
    //freopen("A341.inp","r",stdin);
    //freopen("A341.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);

    FOR(i,1,n) s[i]=s[i-1]+a[i];

    rest=0;
    FOR(i,1,n)
    {
        rest=rest+2*((s[n]-s[i-1])-a[i]*(n-i+1));
        rest=rest+a[i];
    }
    //cout<<rest<<' '<<n<<endl;
    int resm=n;
    FOR(i,2,n)
    {
        while (rest%i==0&&resm%i==0)
        {
            rest/=i;
            resm/=i;
        }
    }
    cout<<rest<<' '<<resm<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

