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
const int maxn = 200+10;
long long C[maxn][maxn];
long long G[maxn][maxn];
int T,n,m;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    G[0][0] = 1;
    for (int i = 1; i <= 100; i++)
    {
        G[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            G[i][j] = (G[i-1][j-1] + G[i-1][j]) % cmod;
        }
    }

    C[0][0] = 1;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= i; k++)
                C[i][j] = (C[i][j] +  C[i - k][j - 1] * G[i][k]) % cmod;
        }
    }
    for (int st = 1; st <= T; st++)
    {
        scanf("%d%d",&m,&n);
        //cout<<n<<' '<<m<<' '<<C[0][0]<<endl;
        cout<<"Case #"<<st<<": "<<C[n][m]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
