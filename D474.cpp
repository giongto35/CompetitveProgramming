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

const int maxn = 100000 + 10;
const int cmod = 1000000007;
long long F[maxn],S[maxn];
int t,a,b,k;

int main()
{
    //freopen("D474.inp","r",stdin);
    //freopen("D474.out","w",stdout);
    scanf("%d %d",&t,&k);
    F[0] = 1;
    for (int i = 1; i <= 100000; i++)
    {
        F[i] = (F[i] + F[i - 1]) % cmod;
        if (i >= k)
        F[i] = (F[i] + F[i - k]) % cmod;
        S[i] = (S[i - 1] + F[i]) % cmod;
        //cout<<i<<' '<<F[i]<<endl;
    }
    for (int i = 1; i <= t; i++)
    {
        scanf("%d%d",&a, &b);
        printf("%d\n",((long long)S[b] - S[a-1] + cmod) % cmod);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

