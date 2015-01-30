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
long long BIT[maxn];
int n,q;
char c;
int l,r,u;
void update(int i,int gt)
{
    i++;
    while (i<=n)
    {
        BIT[i]=BIT[i]+gt;
        i=i+(i & (-i));
    }
}


long long get(int i)
{
    long long gt=0;
    i++;
    while (i>=1)
    {
        gt=BIT[i]+gt;
        i=i-(i & (-i));
    }
    return gt;
}


int main()
{
    //freopen("MARBLEGF.inp","r",stdin);
    //freopen("MARBLEGF.out","w",stdout);
    //scanf("%d%d",&n,&q);
    cin>>n>>q;
    FOR(i,0,n-1) scanf("%d",&u),update(i,u);
    FOR(i,1,q)
    {
    	//scanf(" %c%d%d",&c,&l,&r);
    	cin>>c>>l>>r;
    	if (c == 'S')
    	{
    		printf("%d\n",get(r)-get(l-1));
    	}
    	else
    	if (c == 'G')
    	{
    		update(l,r);
    	}
    	else
    		update(l,-r);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

