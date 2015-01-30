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

const int maxn = 3000+10;
long long a[maxn];
long long F[maxn][maxn][2];
int n,k,l;
int main()
{
    //freopen("F391.inp","r",stdin);
    //freopen("F391.out","w",stdout);
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i];

    FOR(i,0,n)
    FOR(j,0,k)
    FOR(l,0,1)
    F[i][j][l] = -1000000000000000000ll;

    F[0][0][0] = 0;
    FOR(i,0,n)
    FOR(j,0,k)
    FOR(l,0,1)
    {
        if (F[i][j][l] > -1000000000000000000ll)
        {
            if (l == 1) //sell
            F[i+1][j][0] = max( F[i+1][j][0],F[i][j][l] + a[i+1]);
            if (l == 0)
            F[i+1][j+1][1] = max( F[i+1][j+1][1], F[i][j][l] - a[i+1]);
            F[i+1][j][l] = max(F[i+1][j][l], F[i][j][l]);
            F[i][j][l] = max(F[i][j][l], F[i][j-1][l]);
        }
    }
    cout<<F[n][k][0];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

