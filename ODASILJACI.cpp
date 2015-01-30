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

const int maxn = 3 * 100000+10;
struct building
{
	int T;
	int X;
	int H;
} a[maxn],b[maxn];
int n,D;
int st[maxn];
int top;
double res;

double calc(int x,int y)
{
	return (double)a[y].H * (a[y].X - a[x].X) / (a[x].H - a[y].H);
}

int findright(int u)
{
	int res = 0;
	FOR (i,1,top-1)
	{
		if (a[st[i]].T == 0) continue;
		if (res==0 || (calc(st[i],u) < calc(res,u))) res = st[i];
	}
	return res;
}

void process()
{
    top = 0;
    FOR(i,1,n)
    {
    	//if (i==4) cout<<top<<' '<<st[top]<<' '<<a[st[top]].H<<' '<<a[i].H<<' '<<endl;
    	while (top > 0 && a[st[top]].H < a[i].H) top--;
    	st[++top] = i;
    	if (a[i].T == 0)
    	{
    		int u = findright(i);
	    	if (u!=0)
	    	{
	    		double r = a[i].X + calc(u,i);
	    		res += min(r, (double)a[i+1].X) - a[i].X;
	    	}
	    }
    }
}

int main()
{
    //freopen("ODASILJACI.inp","r",stdin);
    //freopen("ODASILJACI.out","w",stdout);
    scanf("%d%d",&n,&D);
    a[n+1].X = D;
    FOR(i,1,n)
    {
    	scanf("%d%d%d",&a[i].T,&a[i].X,&a[i].H);
    }
    res = 0;
   process();
    FOR(i,1,n)
    {
    	b[i]=a[i];
    	b[i].X = D-b[i].X;
    }
    FOR(i,1,n) a[i] = b[n-i+1];
    process();
    printf("%0.3f",D-res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
