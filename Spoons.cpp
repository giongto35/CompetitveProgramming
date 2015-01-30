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
const int maxn = 100000;
#define oo 1000000000000000000LL;
int T;
long long n;
long long F[maxn];
int m;
int main()
{
    //freopen("Spoons.inp","r",stdin);
    //freopen("Spoons.out","w",stdout);
    scanf("%d",&T);
    F[0]=1;
    F[1]=1;
    int i=1;
    FOR(i,2,65)
    {
        if (i%2==0)
            F[i]=F[i-1]*(i/(i/2));
        else
            F[i]=F[i-1]/((i+1)/2)*i;
    }

    m=65;
    FOR(i,1,T)
    {
        cin>>n;
        int l=1;
        int r=m;
        int res=m+1;
        while (l<=r)
        {
            int mid = (l+r)/2;
            if (F[mid]>=n)
            {
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

