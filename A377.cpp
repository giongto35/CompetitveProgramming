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
string st;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,-1,0,1};
char a[maxn][maxn];
char b[maxn][maxn];
bool vis[maxn][maxn];
vector<pair<int,int> > p;
int numemp;
int n,m,k;

void DFS(int y,int x)
{
    p.push_back(make_pair(y,x));
    vis[y][x] = true;
    FOR(i,0,3)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny>=1&&ny<=n&&nx>=1&&nx<=m&&a[ny][nx]=='.'&&vis[ny][nx]==false)
        {
            DFS(ny,nx);
        }
    }
}

int main()
{
    //freopen("A377.inp","r",stdin);
    //freopen("A377.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    getline(cin,st);
    numemp = 0;

    FOR(i,1,n)
    {
        getline(cin,st);
        FOR(j,1,m)
        {
            a[i][j] = st[j-1];
            if (a[i][j] == '.') numemp++;
        }
    }
    memset(vis,false,sizeof(vis));
    FOR(i,1,n) FOR(j,1,m) if (a[i][j] == '#') b[i][j] = a[i][j]; else b[i][j] = 'X';
    FOR(i,1,n)
    FOR(j,1,m)
    {
        if (a[i][j] == '.'&& vis[i][j] == false)
        {
            p.clear();
            DFS(i,j);
            if (numemp - p.size() <= k)
            {
                k = k - (numemp - p.size());
                FOR(l, 0, (p.size() - k)-1)
                b[p[l].first][p[l].second] = '.';
                FOR(ii,1,n)
                {FOR(jj,1,m) cout<<b[ii][jj];cout<<endl;}
                return 0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

