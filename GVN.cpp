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

const int offset = 250;
const int maxn = 500;
int T,n;
char a[maxn][maxn];

int main()
{
    //freopen("GVN.inp","r",stdin);
    //freopen("GVN.out","w",stdout);
    cin>>T;
    for (int i = 0; i <= maxn - 1; i++)
        for (int j = 0; j <= maxn - 1; j++)
        a[i][j] = 'w';
    for (int i = 0; i >= -110 * 2; i-=3)
    {
        for (int x = i, y = 0; x <= 0; x++, y++)
        {
            a[y + offset][x + offset] = 'b';
        }
    }
    for (int i = 0; i <= 110* 2; i+=3)
    {
        for (int x = i, y = 0; x >= 0; x--, y++)
        {
            a[y + offset][x + offset] = 'b';
        }
    }

    for (int i = 0; i >= -110 * 2; i-=3)
    {
        for (int x = i, y = 0; x <= 0; x++, y--)
        {
            a[y + offset][x + offset] = 'b';
        }
    }

    for (int i = 0; i <= 110 * 2; i+=3)
    {
        for (int x = i, y = 0; x >= 0; x--, y--)
        {
            a[y + offset][x + offset] = 'b';
        }
    }
    while (T--)
    {
        scanf("%d",&n);
        for (int i = -n; i<= n; i++){
                for (int j = -n; j <= n; j++)
            {
                printf("%c", a[i + offset][j + offset]);
            }
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

