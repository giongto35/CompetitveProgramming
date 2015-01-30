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

const int maxn = 40+10;
const long long  oo = 1000000000000000000ll;
long long F[maxn][5][5];
long long a[5][5];
int r[5][5];
int n,m;
int main()
{
    //freopen("B392.inp","r",stdin);
    //freopen("B392.out","w",stdout);
    FOR(i,1,3)
    FOR(j,1,3)
    {
        scanf("%d",&a[i][j]);
        F[1][i][j] = a[i][j];
    }
    scanf("%d",&n);
    r[1][2] = 3;
    r[1][3] = 2;
    r[2][1] = 3;
    r[2][3] = 1;
    r[3][1] = 2;
    r[3][2] = 1;
        FOR(j,1,3)
        FOR(k,1,3)
        {
            int t = r[j][k];
            F[1][j][k] = min(F[1][j][k],F[1][j][t] + F[1][t][k]);
        }

    FOR(i,1,n)
    {

        FOR(j,1,3)
        FOR(k,1,3)
        {
            int t = r[j][k];
            F[i-1][j][k] = min(F[i-1][j][k],F[i-1][j][t] + F[i-1][t][k]);
        }
        if(i>1)
        FOR(j,1,3)
        FOR(k,1,3)
        {
            if (j!=k)
            {
                F[i][j][k] = oo;
                int t = r[j][k];
                F[i][j][k] = min(F[i][j][k],F[i-1][j][t] + a[j][k] + F[i-1][t][k]);
                F[i][j][k] = min(F[i][j][k],F[i-1][j][k] + a[j][t] + F[i-1][k][j] + a[t][k] + F[i-1][j][k]);
                //cout<<i<<' '<<j<<' '<<k<<' '<<F[i-1][j][t] + F[1][j][k] + F[i-1][t][k]<<endl;
                //cout<<i<<' '<<j<<' '<<k<<' '<<F[i-1][j][k] + F[1][j][t] + F[i-1][k][j] + F[1][t][k] + F[i-1][j][k]<<endl;
                //cout<<i<<' '<<j<<' '<<k<<' '<<F[i][j][k]<<endl;
            }
        }
    }
    cout<<F[n][1][3]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

