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

const int maxn = 2000+10;
int a[maxn][maxn];
int b[maxn][maxn];
int F[maxn][maxn];
int u[maxn][maxn];
int l[maxn][maxn];
int res;
int n,m;

void process1()
{
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            F[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        if (i > 1 && j > 1 && a[i][j] == a[i - 1][j] && a[i][j-1] == a[i-1][j-1])//a[i][j] - a[i][j-1] == a[i-1][j] - a[i-1][j-1])
            u[i][j] = u[i-1][j] + 1;
        else
            u[i][j] = 1;
        if (i > 1 && j > 2 && a[i][j] - a[i][j-1] == a[i][j-1] - a[i][j-2] && a[i][j] == a[i-1][j] && a[i][j-1] == a[i-1][j-1] && a[i][j-2] == a[i-1][j-2])
            l[i][j] = l[i][j-1] + 1;
        else
            l[i][j] = 2;
        F[i][j] = min(min(F[i-1][j-1] + 1, l[i][j]), u[i][j]);
        res = max(res,F[i][j]);
    }
}

void process2()
{
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            F[i][j] = 0;
    /*for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            cout<<a[i][j]<<' ';
            cout<<endl;
        }
*/
    for (int i = 1; i <= n; i++)
    {   for (int j = 1; j <= m; j++)
        {
            if (i > 1 && j > 1 && a[i - 1][j] == a[i][j - 1] && (a[i][j] - a[i - 1][j] == a[i - 1][j] - a[i - 1][j - 1])) u[i][j] = u[i - 1][j] + 1;
            else u[i][j] = 1;
            if (i > 1 && j > 1 && a[i][j - 1] == a[i - 1][j] && (a[i][j] - a[i][j - 1] == a[i][j - 1] - a[i - 1][j - 1])) l[i][j] = l[i][j - 1] + 1;
            else l[i][j] = 1;
            F[i][j] = min(min(F[i-1][j-1] + 1, l[i][j]), u[i][j]);
            res = max(res,F[i][j]);
            //cout<<u[i][j]<<' ';
        }
        //cout<<endl;
    }
}

void rot()
{
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        b[j][n - i + 1] = a[i][j];
    }
    swap(n,m);
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++) a[i][j] = -rand();

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    a[i][j] = b[i][j];
}

int main()
{
    //freopen("gradient.in","r",stdin);
    //freopen("DGYMCTU.out","w",stdout);
    while( scanf("%d%d",&n,&m) == 2){
        if (n== 0 && m == 0) break;
        res = 0;
        for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= m + 1; j++) a[i][j] = -rand();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
        {
            scanf("%d",&a[i][j]);
        }
        for (int i = 1; i <= 2; i++){
            process1();
            //cout<<i<<' '<<res<<endl;
            process2();
            //cout<<i<<' '<<res<<endl;
            if (i == 1)
            rot();
        }
        process2();
        printf("%d\n",res*res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

