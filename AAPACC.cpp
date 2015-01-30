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

const int maxn = 300+10;
const int dy[8] = {-1,-1,-1,0,1,1,1,0};
const int dx[8] = {-1,0,1,1,1,0,-1,-1};
bool vis[maxn][maxn];
int c[maxn][maxn];
char a[maxn][maxn];
int n,T,res;
string st;

void DFS(int i, int j)
{
    vis[i][j] = true;
    for (int k = 0; k <= 7; k++)
    {
        int y = i + dy[k];
        int x = j + dx[k];
        //cout<<i<<' '<<j<<' '<<y<<' '<<x<<endl;
        if (y >= 1 && y <= n && x >= 1 && x <= n && vis[y][x] == false && a[y][x] == '.')
        {
            if (c[y][x] == 0)
                DFS(y,x);
            else
            {
                vis[y][x] = true;
            }
        }
    }
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("AAPAC.out","w",stdout);
    scanf("%d",&T);
    for (int ste = 1; ste <= T; ste++)
    {
        scanf("%d",&n);
        res = 0;
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
        memset(vis,false,sizeof(vis));
        for (int i = 1; i <= n; i++)
        {
            cin>>st;
            for (int j = 0; j < n; j++)
                a[i][j + 1] = st[j];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == '.')
                for (int k = 0; k <= 7; k++)
                {
                    int y = i + dy[k];
                    int x = j + dx[k];
                    if (y >= 1 && y <= n && x >= 1 && x <= n)
                    {
                        if (a[y][x] == '*')
                        {
                            c[i][j] ++;
                        }
                    }
                }
            }
        }

        /*for (int i = 1; i <= n; i++)
            {for (int j = 1; j <= n; j++)
                cout<<c[i][j];
            cout<<endl;
    }*/
        memset(vis, false, sizeof(vis));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
        {
            if (c[i][j] == 0 && vis[i][j] == false && a[i][j] == '.') {
                res ++;

                DFS(i,j);
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            if (a[i][j] == '.' && c[i][j] != 0 && vis[i][j] == false) res++;

        cout<<"Case #"<<ste<<": "<<res<<endl;

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

