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

const int cmod = 1000000007;
const int maxn = 5000 + 10;
int n,a,b,k;
long long F[maxn][maxn];
long long s[maxn];
int main()
{
    freopen("C480.inp","r",stdin);
    //freopen("C480.out","w",stdout);
    scanf("%d%d%d%d",&n,&a,&b,&k);
    F[0][a] = 1;
    for (int j = 1; j <= n; j++)
    {
        s[j] = (s[j-1] + F[0][j]) % cmod;
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j != b)
            {
                if (j < b)
                {
                    F[i][j] = (s[(b + j - 1) / 2] - F[i-1][j]) % cmod;
                }
                else
                {
                    F[i][j] = ((s[n]  - s[(b + j) / 2]) % cmod - F[i-1][j]) % cmod;
                }
            }
            //cout<<i<<' '<<j<<' '<<F[i][j]<<endl;
        }
        for (int j = 1; j <= n; j++)
        {
            s[j] = (s[j-1] + F[i][j]) % cmod;
        }
    }
    cout<<(s[n] % cmod + cmod ) % cmod<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

