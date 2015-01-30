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

struct movetype
{
    int x;
    int y;
    int d;
};
const int maxn = 2000000;
const int maxs = 600 + 10;
movetype q[maxn];
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,-1,0,1};
int d[maxs][maxs][4];
int a[maxs][maxs];
pair<int, int> kq;
int res;
int n;
void BFS()
{
    int fr = 0;
    int re = 1;
    q[re].y = n + 1;
    q[re].x = n + 1;
    q[re].d = 0;
    d[n+1][n+1][0] = 1;
    d[n+1][n+1][1] = 1;
    d[n+1][n+1][2] = 1;
    d[n+1][n+1][3] = 1;
    res = -1;
    while (fr < re)
    {
        fr++;
        if (res != -1)
            if (d[q[fr].y][q[fr].x][q[fr].d] > res) break;
        if (q[fr].x == 1 || q[fr].x == (2 * n + 1) || q[fr].y == 1 || q[fr].y == 2 * n + 1)
        {
            res = d[q[fr].y][q[fr].x][q[fr].d] - 1;
            if (kq.first == 0)
                kq = make_pair(q[fr].y,q[fr].x);
            else
                kq = min(kq, make_pair(q[fr].y, q[fr].x));
            //printf("%d\n",d[q[fr].y][q[fr].x][q[fr].d] - 1);
            //printf("%d %d\n",q[fr].y, q[fr].x);
        }
        for (int i = 0; i < 4; i++)
        {
            int y = q[fr].y + dy[i];
            int x = q[fr].x + dx[i];
            if (y >= 1 && y <= 2 * n + 1 && x >= 1 && x <= 2 * n + 1 && d[y][x][i] == 0 )
            {
                int prevy = q[fr].y + dy[(2 + q[fr].d) % 4];
                int prevx = q[fr].x + dx[(2 + q[fr].d) % 4];
                if (a[y][x] <= a[q[fr].y][q[fr].x]){
                if ((q[fr].y == n + 1 && q[fr].x == n + 1) || ((!(q[fr].y == n + 1 && q[fr].x == n + 1)) && a[q[fr].y][q[fr].x] - a[y][x] <= a[prevy][prevx] - a[q[fr].y][q[fr].x]))
                {
                    //cout<<q[fr].y<<' '<<q[fr].x<<' '<<y<<' '<<x<<' '<<a[y][x]<<' '<<a[q[fr].y][q[fr].x]<<endl;
                    d[y][x][i] = d[q[fr].y][q[fr].x][q[fr].d] + 1;
                    ++re;
                    q[re].y = y;
                    q[re].x = x;
                    q[re].d = i;
                }
                }
            }
        }
    }
    if (res == -1)
    printf("IMPOSSIBLE");
    else
    {
        printf("%d\n",res);
        printf("%d %d\n",kq.first,kq.second);
    }
}

int main()
{
    freopen("CGYM4.inp","r",stdin);
    //freopen("CGYM4.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        for (int j = 1; j <= 2 * n + 1; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    BFS();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

