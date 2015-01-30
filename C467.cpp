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

const int maxn = 5000+10;
long long F[maxn][maxn];
long long s[maxn];
int a[maxn];
int n,m,k;
long long res;
int main()
{
    //freopen("C467.inp","r",stdin);
    //freopen("C467.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    F[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i >= m && j >= 1)
                F[i][j] = max(F[i][j], F[i - m][j - 1] + s[i] - s[i - m]);
            F[i][j] = max(F[i][j], F[i - 1][j]);
            res = max(res,F[i][j]);
        }
    }

    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

