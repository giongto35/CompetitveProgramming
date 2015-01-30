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
const int maxn = 50;
int a[maxn][maxn];
int F[maxn][maxn][maxn][maxn];
int s[maxn][maxn];
string st;
int Y1,x1,y2,x2;
int n,m,q;

bool check(int Y1, int x1, int y2, int x2)
{
	return ((s[y2][x2] - s[Y1-1][x2] - s[y2][x1-1] + s[Y1-1][x1-1]) == 0);
}

int main()
{
    //freopen("B372.inp","r",stdin);
    //freopen("B372.out","w",stdout);
    cin>>n>>m>>q;
    getline(cin,st);
    FOR(i,1,n)
    {
    	getline(cin,st);
    	FOR(j,1,m)
	    {
	    	a[i][j] = st[j-1] - '0';
	    	s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + a[i][j];
	    }
	}

	DOW(i,n,1)
	DOW(j,m,1)
	FOR(k,i,n)
	FOR(l,j,m)
	{
		F[i][j][k][l] = F[i+1][j][k][l] + F[i][j+1][k][l] + F[i][j][k-1][l] + F[i][j][k][l-1]
					 - (F[i+1][j+1][k][l] + F[i+1][j][k-1][l] + F[i+1][j][k][l-1] + F[i][j+1][k-1][l] + F[i][j+1][k][l-1] + F[i][j][k-1][l-1])
					 + (F[i+1][j+1][k-1][l] + F[i+1][j+1][k][l-1] + F[i+1][j][k-1][l-1] + F[i][j+1][k-1][l-1])
					 - (F[i+1][j+1][k-1][l-1])
					 + check(i,j,k,l);
	}
	FOR(i,1,q)
	{
		scanf("%d%d%d%d",&Y1,&x1,&y2,&x2);
		printf("%d\n",F[Y1][x1][y2][x2]);
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
