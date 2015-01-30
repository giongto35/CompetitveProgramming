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
#define oo 9223372036854775807ll
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

const int maxn = 100+10;
string st;
unsigned long long P[maxn];
unsigned long long n;
int m;
unsigned long long sum;
int res[maxn];
int dd;
int T;

void process()
{
    m = st.length();
	P[0] = 1;
	FOR (i,1,100)
	{
		if (P[i-1] > n / m) P[i] = oo; else
		P[i] = P[i-1] * m;
	}
	dd = 1;
	while (n > P[dd])
	{
        n -= P[dd];
        dd++;
	}
	FOR(i,1,dd)
	{
		res[i] = 1;
		while (n > P[dd-i])
		{
			res[i]++;
			n -= P[dd-i];
		}
	}

	FOR(i,1,dd) cout<<st[res[i]-1];
	cout<<endl;
}

int main()
{
    freopen("labelmaker.txt","r",stdin);
    freopen("labelmarker.out","w",stdout);
    scanf("%d",&T);
    FOR(i,1,T)
    {
    	cin>>st>>n;
		cout<<"Case #"<<i<<": ";
    	process();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
