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

const int maxn = 200000+10;
int p[maxn];
int e[maxn];
int sum;
int point;
int res,n,k;
int main()
{
    //freopen("C391.inp","r",stdin);
    //freopen("C391.out","w",stdout);
    scanf("%d%d",&n,&k);
    FOR(i,0,n-1)
    {
        scanf("%d%d",&p[i],&e[i]);
    }
    res = 1000000000;
    FOR(b,0,(1<<n)-1)
    {
        sum = 0 ;
        point = 0;
        FOR(j,0,n-1)
        {
            if ((b >> j)& 1)
            {
                sum += e[j];
                point++;
            }
        }
        int rank = 0;
        FOR(j,0,n-1)
        {
            int np = p[j];
            if (((b >> j) & 1) == 0) np++;
            if (point > np) rank++; else
            if (point == np){
                if ((b >> j) & 1) rank++;
            }
        }
        if (rank >= (n + 1) - k) res = min(res,sum);
    }

    if (res == 1000000000) cout<<-1; else
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

