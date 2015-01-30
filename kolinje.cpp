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

const int maxn  = 1000+10;
int a[maxn];
double b[maxn];
double sum;
double gtmin,gtmax;
int n;

int main()
{
    //freopen("kolinje.inp","r",stdin);
    //freopen("kolinje.out","w",stdout);
    cin>>n;
    sum = 0;
    FOR(i,1,n)
    {
    	scanf("%d%d",&a[i],&b[i]);
    	sum += b[i];
    }
    FOR(i,1,n) b[i] = b[i] / sum;
    gtmin = 0;
    gtmax = oo;
    FOR(i,1,n)
    FOR(j,i+1,n)
    {
    	if (a[i] < a[j])
    	{
    		if (b[i] <= b[j])
    		{
    			cout<<-1;
    			return 0;
    		}
    		else
    		{
    			gtmin = max(gtmin, (a[j] - a[i] + 0.0)/(b[i] - b[j]));
    		}
    	}
    	else
    	{
    		if (b[i] >= b[j]) continue;
    		gtmax = min(gtmax, (a[i] - a[j] + 0.0)/(b[j] - b[i]));
    	}
    }
    if (gtmin <= gtmax + 0.0000000001) printf("%0.12f",gtmin); else cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
