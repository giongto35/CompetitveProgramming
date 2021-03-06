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
int a[maxn];
int S[maxn];
int S2[maxn];
int res,n;

int main()
{
    //freopen("A446.inp","r",stdin);
    //freopen("A446.out","w",stdout);
    scanf("%d",&n);
    a[0] = 2e9;
    a[n+1] =  -2e9;
    for (int i =1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        if (a[i] > a[i-1]) S[i] = S[i-1] + 1;
        else S[i] = 1;
        res = max(res,S[i]);
        if (i < n) res = max(res,S[i]+1);
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] < a[i+1]) S2[i] = S2[i+1] + 1;
        else S2[i] = 1;
        res = max(res, S2[i]);
        if (i > 1) res = max(res, S2[i]+1);
    }
    a[0] = -2e9;
    a[n+1] =  2e9;
	for (int i = 1; i < n; i++)
		if (a[i+2] > a[i]+1)
			res = max(res, S[i] + 1 + S2[i+2]);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


