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

const int maxn = 100200+10;
const int cmod = 1000000007;
int b[maxn];
long long C[maxn][110];
long long a[maxn][110];
int n,m,l,r,k;
int main()
{
    //freopen("C407.inp","r",stdin);
    //freopen("C407.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) scanf("%d",&b[i]);
    memset(C,0,sizeof(C));
    memset(a,0,sizeof(a));
    C[0][0] = 1;
    for (int i = 1; i <= 100200; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= 100; j++)
            C[i][j] = (C[i-1][j] + C[i-1][j-1])% cmod;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d",&l,&r,&k);
        a[l][k] = (a[l][k] + 1) % cmod;
        for (int j = 0; j <= k; j++)
            a[r+1][k - j] = (a[r+1][k - j] - C[r - l + j][j]) % cmod;
    }

    for (int j = 100; j >= 0; j--){
            for (int i = 1; i <= n; i++)
                {
                a[i][j] = ((a[i-1][j] + a[i][j+1]) % cmod + a[i][j]) % cmod;
                    //cout<<a[i][j];
                }
                //cout<<endl;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ",((a[i][0] + b[i])  % cmod + cmod ) % cmod);
    //1 1 1 1 -1
    //1 2 3 4
    //1 3 6 10
    fclose(stdin);
    fclose(stdout);
    return 0;
}

