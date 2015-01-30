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

int L,W;
double l;
int n;
const int maxn = 2000+10;
double F[maxn][maxn];
int a[maxn];

double calc(double x, double y)
{
    return sqrt(x * x + y * y);
}
int main()
{
    //freopen("AGYM3.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    scanf("%d%d",&L,&W);
    for (int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    sort(a+1, a+1+n);

    l = (L + 0.0) / (n / 2 - 1);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) F[i][j] = 1000000000;
    F[0][0] = 0;
    //cout<<l<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= min(i, n/2); j++)
        {
            //push left
            int k = i - j;
            if (k > 0)
                F[i][j] = min(F[i][j], F[i-1][j] + calc(a[i] - (k - 1) * l, 0));
            //push right
            if (j > 0)
                F[i][j] = min(F[i][j], F[i-1][j-1] + calc(a[i] - (j - 1) * l,W));
        }
    }
    printf("%0.6f\n", F[n][n/2]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

