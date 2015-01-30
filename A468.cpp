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

int n;
int main()
{
    //freopen("A468.inp","r",stdin);
    //freopen("A468.out","w",stdout);
    scanf("%d",&n);
    if (n < 4)
    {
        printf("NO\n");
    }
    else
    if (n == 4)
    {
        printf("YES\n");
        printf("1 * 2 = 2\n");
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
    }
    else
    if (n == 5)
    {
        printf("YES\n");
        printf("4 - 2 = 2\n");
        printf("5 - 1 = 4\n");
        printf("2 * 4 = 8\n");
        printf("8 * 3 = 24\n");
    }
    else
    {
        printf("YES\n");
        printf("2 * 3 = 6\n");
        printf("6 * 4 = 24\n");
        printf("6 - 5 = 1\n");
        printf("1 - 1 = 0\n");
        for (int i = 7; i <= n; i++)
            printf("0 * %d = 0\n",i);
        printf("24 + 0 = 24\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

