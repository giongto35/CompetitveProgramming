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
const int maxso = 160000;
const int maxn = 400+10;
int a[maxn][maxn];
pair<int,int> pr[maxn][maxn];
pair<int,int> nx[maxn][maxn];
pair<int,int> pos[maxn*maxn];
int F[maxn][maxn];
int G[maxn][maxn];
int n,m,res;
pair<int,int> p0;

void link(const pair<int,int> &p1, const pair<int,int> &p2)
{
    nx[p1.first][p1.second] = p2;
    pr[p2.first][p2.second] = p1;
}

int main()
{
    //freopen("D407.inp","r",stdin);
    //freopen("D407.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1 ; i <= n; i++)
        for (int j = 1; j <= m; j++)
        scanf("%d",&a[i][j]);
    res = 0;


    for (int l = 1; l <= m; l++)
    {
        memset(pos,0,sizeof(pos));
        //memset(pr,0,sizeof(pr));
        //memset(nx,0,sizeof(nx));
        for (int i = 1; i <= n; i++)
            for (int j = l; j <=m; j++)
            {
                if (pos[a[i][j]].first == 0) 
                {
                    link(p0,make_pair(i,j));                    
                    link(make_pair(i,j),p0);
                }
                else
                    link(pos[a[i][j]], make_pair(i,j));
                pos[a[i][j]] = make_pair(i,j);
                nx[i][j] = p0;
            }
        for (int j = m; j >= l; j--)
        {
            for (int i = 1; i <= n; i++)
                G[i][j] = pr[i][j].first;
            for (int i = 1; i <= n; i++)
                link(pr[i][j],nx[i][j]);
        }

        memset(pos,0,sizeof(pos));
        //memset(pr,0,sizeof(pr));
        //memset(nx,0,sizeof(nx));
        for (int i = n; i >= 1; i--)
            for (int j = l; j <=m; j++)
            {
                if (pos[a[i][j]].first == 0) 
                {
                    link(p0,make_pair(i,j));                    
                    link(make_pair(i,j),p0);
                }
                else
                    link(pos[a[i][j]], make_pair(i,j));
                pos[a[i][j]] = make_pair(i,j);
                nx[i][j] = p0;
            }

        for (int j = m; j >= l; j--)
        {
            for (int i = 1; i <= n; i++)
                if (pr[i][j].first != 0)
                {
                    G[pr[i][j].first][j] = max(G[pr[i][j].first][j],i);
                }
            for (int i = 1; i <= n; i++)
                link(pr[i][j],nx[i][j]);
        }
        /*
        for (int i = 1; i <= n; i++)
        {
            for (int j = l; j <= m; j++)
            cout<<G[i][j]<<' ';        
            cout<<endl;
        }*/
        for (int i = 1; i <= n; i++)
        for (int j = l; j <= m; j++)
        {
            F[i][j] = G[i][j];
            if (i > 1) F[i][j] = max(F[i][j], F[i-1][j]);
            if (j > l) F[i][j] = max(F[i][j], F[i][j-1]);
            res = max(res,(i - F[i][j]) * (j - l + 1));
        }

    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
