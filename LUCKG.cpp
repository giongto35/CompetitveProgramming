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
bool used[maxn];
int cnt;
int sl;
vector<int> c[maxn];
vector<int> res,r[maxn];
int F[maxn];
int G[maxn];
int a[maxn];
int v[maxn];
int n,m;
int T;

bool check()
{
        for (int i = 1; i <= sl; i++)
        {
            int bd = res.size();
            for (int k = 0; k < m; k++)
            {
                for (int j = 0; j < c[i].size(); j++)
                {
                    res.push_back(c[i][(j + k) % c[i].size()]);
                }
            }
            for (int k = bd + c[i].size()-1; k + 1 < res.size(); k+=c[i].size())swap(res[k], res[k+1]);
        }
        memset(G,0,sizeof(G));
        memset(F,0,sizeof(F));
        for (int i = 0; i < n * m; i++)
        {
            G[res[i]] += F[a[res[i]]];
            F[res[i]] ++;
        }
        for (int i = 0; i < n; i++)
        {
            if (G[i] * 2 <= m * m) return false;
        }
        return true;
}


int main()
{
    //freopen("LUCKG.inp","r",stdin);
    //freopen("LUCKYG.out","w",stdout);
    scanf("%d",&T);

    for (; T > 0; T--)
    {
        scanf("%d %d",&n,&m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            r[i].clear();
        }

        memset(used,false,sizeof(used));
        res.clear();
        sl = 0;

        for (int i = 0; i < n; i++)
        {
            if (used[i] == false)
            {
                cnt = 0;
                int j = i;
                sl++;
                c[sl].clear();
                while (used[j] == false)
                {
                    used[j] = true;
                    c[sl].push_back(j);
                    cnt++;
                    v[j] = sl;
                    j = a[j];
                }
                reverse(c[sl].begin(),c[sl].end());
            }
        }
        if (check())
        {
            for (int i = 0; i < n * m; i++)
                r[res[i]].push_back(i);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m-1; j++)
                    printf("%d ",r[i][j] + 1);
                printf("%d\n",r[i][m-1] + 1);
            }
        }
        else
            printf("No Solution\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
