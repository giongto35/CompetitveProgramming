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

const int maxn = 1000+10;
int a[maxn][maxn];
int F[4][maxn][maxn][4];
int res,n,m;
int main()
{
    //freopen("B429.inp","r",stdin);
    //freopen("B429.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        scanf("%d",&a[i][j]);
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        F[0][i][j][0] = max(F[0][i][j][0],max(F[0][i][j-1][0],F[0][i][j-1][1]) + a[i][j]);
        F[0][i][j][1] = max(F[0][i][j][1],max(F[0][i-1][j][0],F[0][i-1][j][1]) + a[i][j]);
    }
    for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
    {
        F[1][i][j][2] = max(F[1][i][j][2],max(F[1][i][j+1][1],F[1][i][j+1][2]) + a[i][j]);
        F[1][i][j][1] = max(F[1][i][j][1],max(F[1][i-1][j][1],F[1][i-1][j][2]) + a[i][j]);
    }
    for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++)
    {
        F[2][i][j][0] = max(F[2][i][j][0],max(F[2][i][j-1][0],F[2][i][j-1][3]) + a[i][j]);
        F[2][i][j][3] = max(F[2][i][j][3],max(F[2][i+1][j][0],F[2][i+1][j][3]) + a[i][j]);
    }
    for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--)
    {
        F[3][i][j][2] = max(F[3][i][j][2],max(F[3][i][j+1][2],F[3][i][j+1][3]) + a[i][j]);
        F[3][i][j][3] = max(F[3][i][j][3],max(F[3][i+1][j][2],F[3][i+1][j][3]) + a[i][j]);
    }
    for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++)
    {
        //cout<<F[0][i][j][0]<<' '<<F[3][i][j][2]<<' '<<F[2][i][j][1]<<' '<<F[1][i][j][3]<<endl;
        res=max(res,F[0][i][j][0]+F[3][i][j][2]+F[2][i][j][3]+F[1][i][j][1] - 4 * a[i][j]);
        //if (i== 3&& j==4) cout<<F[0][i][j][1]<<' '<<F[3][i][j][3]<<' '<<F[2][i][j][0]<<' '<<F[1][i][j][2]<<endl;
        res=max(res,F[0][i][j][1]+F[3][i][j][3]+F[2][i][j][0]+F[1][i][j][2] - 4 * a[i][j]);
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

