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

const int maxn = 50+10;
const int maxm = maxn * 100;
double F[maxn][maxm];
double G[maxn][maxn*2];
int n,k,c,u,v,T;
int cnt[maxn];
double res;
int main()
{
    //freopen("LEPAIN.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&T);
    for (; T>0; T--)
    {
        scanf("%d%d%d",&n,&c,&k);
        memset(cnt,0,sizeof(cnt));
        for (int i = 1; i <= k; i++)
        {
            scanf("%d%d",&u,&v);
            for (int j = u; j <= v; j++)
                cnt[j]++;
        }
        //for (int i = 1; i <= n; i++) cout<<cnt[i]<<' ';cout<<endl;
        memset(G,0,sizeof(G));
        memset(F,0,sizeof(F));
        G[0][1] = 1;
        for(int i = 0; i < k; i++)
            for (int j = 0; j <= c-1; j++)
        {
            if (G[i][j] > 0)
            {
                for (int l = 0; l <= c-1; l++)
                G[i+1][(j * l) % c] += G[i][j] * (0.5 / c);
                G[i+1][j] += G[i][j] * (0.5);
            }
        }
        F[0][0] = 1;
        for(int i = 0; i < n; i++)
            for (int j = 0; j <= (c-1) * i; j++)
        {
            if (F[i][j] > 0)
            {
                for (int l = 0; l <= (c-1); l++)
                F[i+1][j + l] += F[i][j] * G[cnt[i+1]][l];
            }
        }
        res = 0;
        for (int j = 1; j <= (c-1) * n; j++)
        {
            res += j * F[n][j];
            //cout<<j<<' '<<F[n][j]<<endl;
        }
        printf("%.6f\n",res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

