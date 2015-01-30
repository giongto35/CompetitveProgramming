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
const int maxn = 3*100000+10;
const int maxgh = 1000000+10;
int a[maxn];
int rmost[maxgh+10];
int n,k;
int main()
{
    //freopen("C354.inp","r",stdin);
    //freopen("C354.out","w",stdout);
    cin>>n>>k;
    FOR(i,1,n) scanf("%d",&a[i]);
/*    n=200005;
    k=150000;
    int x=899998 ;
    FOR(i,1,n) {a[i]=x--;cout<<a[i]<<' ';}*/
    sort(a+1,a+1+n);
    int rm=1;
    FOR(i,1,a[n])
    {
        while (rm<=n&&a[rm]-k<=i)rm++;
        rmost[i]=rm;
    }
    DOW(i,a[1],1)
    {
        int x=1;
        for(int j=i;j<=a[n];j+=i)
        {
            if (a[x]-k<=j&&a[x]>=j) x=rmost[j];
            if (x==n+1)
            {
                cout<<i;
                return 0;
            }
            else
            if (a[x]<j)break;
        }
    }
    cout<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

