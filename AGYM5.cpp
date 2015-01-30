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

const int maxn = 100+10;
int n,m;
int a[maxn][maxn];
bool vis[maxn][maxn];
const int dy[4] = {0,1,0,-1};
const int dx[4] = {1,0,-1,0};
string st;
int y;
int x;
int d;
int res;
int main()
{
    ios :: sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>st;
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = st[j-1] - '0';
        }
    }
    cin>>st;
    y = 1;
    x = 1;
    d = 0;
    for (int i = 0; i < st.length(); i++)
    {
        if (st[i] == 'M')
        {
            //cout<<"abc"<<' '<<y<<' '<<x<<' '<<d<<' '<<a[y][x]<<' '<<endl;
            if (d == 0)
            {
                res = res + a[y][x] / (vis[y][x] == true ? 2 : 1);
                res = res + a[y - 1][x] / (vis[y - 1][x] == true ? 2 : 1);
                vis[y][x] = true;
                vis[y-1][x] = true;
            }
            if (d == 1)
            {
                res = res + a[y][x] / (vis[y][x] == true ? 2 : 1);
                res = res + a[y][x - 1] / (vis[y][x - 1] == true ? 2 : 1);
                vis[y][x] = true;
                vis[y][x-1]=true;
            }
            if (d == 2)
            {
                res = res + a[y - 1][x - 1] / (vis[y - 1][x - 1] == true ? 2 : 1);
                res = res + a[y][x - 1] / (vis[y][x-1] == true ? 2 : 1);
                vis[y-1][x-1] = true;
                vis[y][x-1] = true;
            }
            if (d == 3)
            {
                res = res + a[y - 1][x - 1] / (vis[y - 1][x - 1] == true ? 2 : 1);
                res = res + a[y - 1][x] / (vis[y - 1][x] == true ? 2 : 1);
                vis[y-1][x-1] = true;
                vis[y-1][x] = true;
            }
            y = y + dy[d];
            x = x + dx[d];
        }
        else
        if (st[i] == 'R')
        {
            d = (d + 1) % 4;
        }
        else
        {
            d = (d + 3) % 4;
        }
        //cout<<st[i]<<' '<<d<<endl;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
