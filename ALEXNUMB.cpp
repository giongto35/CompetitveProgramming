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

const int maxn = 100000+10;
int cnt;
int a[maxn];
int T,n;
long long res;

int main()
{
    //freopen("ALEXNUMB.inp","r",stdin);
    //freopen("ALEXNUMB.out","w",stdout);
    scanf("%d",&T);
    FOR(i,1,T)
    {
    	scanf("%d",&n);
    	FOR(i,1,n) scanf("%d",&a[i]);
    	sort(a+1,a+1+n);
    	cnt = 1;
    	a[n+1] = -123;
    	res = 0;
    	FOR(i,1,n)
    	{
    		if (a[i]==a[i+1]) cnt++; else { res = res + (long long) cnt * (cnt-1) /2; cnt = 1;}
    		//cout<<a[i]<<' '<<a[i+1]<<' '<<cnt<<' '<<res<<endl;
    	}
    	//cout<<res<<endl;
    	cout<<(long long)n * (n-1) / 2 - res <<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
