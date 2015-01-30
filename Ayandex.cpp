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

const int maxn = 500+10;
int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {-1,-1,-1,0,1,1,1,0};
int a[maxn][maxn];
double res;
int y,x,n,m;
int main()
{
    //freopen("AYandex.inp","r",stdin);
    //freopen("Ayandex.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        scanf("%d",&a[i][j]);
    }
    res = -1;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        double sum = (a[i][j] + 0.0) * 1/2;
        for (int k = 0; k < 8; k++)
            sum += (a[i+dy[k]][j+dx[k]] + 0.0) * 1/16;
        if (res < sum)
        {
            res = sum;
            y = i;
            x = j;
        }
    }
    cout<<y<<' '<<x<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

