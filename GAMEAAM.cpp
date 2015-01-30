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

const int maxn  = 1000;
pair<int,int> g[maxn];
int F[maxn][maxn];
int main()
{
    //freopen("GAMEAAM.inp","r",stdin);
    freopen("GAMEAAM.out","w",stdout);
    FOR(i,1,100){

    FOR(j,1,100)
    {
        if (i == j) { F[i][j] = 0; cout<<F[i][j]<<' '; continue;}
        FOR(k,1,100)
        {
            if ( (i - k * j) > 0 ) g[F[i - k * j][j]] = make_pair(i,j);
            if ( (j - k * i) > 0 ) g[F[i][j - k * i]] = make_pair(i,j);
        }
        int k = 0;
        while (g[k].first == i && g[k].second == j) k++;
        F[i][j] = k;
        cout<<F[i][j]<<' ';//<<'/'<<i<<'/'<<j<<'/'<<__gcd(i,j)<<"  ";
    }
    cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

