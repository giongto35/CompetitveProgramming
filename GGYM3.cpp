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

const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,-1,0,1};
const int maxn = 100+10;
char a[maxn][maxn];
bool vis[maxn][maxn];
int y,x;
int res,n,m;
string st;

void DFS(int y, int x)
{
    //cout<<y<<' '<<x<<endl;
    vis[y][x] = true;
    res = res + (a[y][x] == 'G');
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 1 && ny <= n && nx >= 1 && nx <= m && a[ny][nx] == 'T')
        {
            return;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 1 && ny <= n && nx >= 1 && nx <= m && a[ny][nx] != '#' && vis[ny][nx] == false)
        {
            DFS(ny, nx);
        }
    }
}

int main()
{
    //freopen("GGYM3.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d\n",&m,&n);
    for (int i = 1; i <= n; i++)
    {
        getline(cin,st);
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = st[j-1];
            if (a[i][j] == 'P')
            {
                if (i == 1 || i == n || j == 1 || j == m) a[i][j] = '#';
                else
                a[i][j] = '.';
                y = i;
                x = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    DFS(y,x);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

