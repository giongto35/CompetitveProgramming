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

const int maxn = 1000+10;
int a[maxn][maxn];
long long sr[maxn];
long long sc[maxn];
long long res;
multiset<long long> r;
int n,m,k,p;
long long tr[1000000+10];
long long tc[1000000+10];
int main()
{
    //freopen("B446.inp","r",stdin);
    //freopen("B446.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&p);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d",&a[i][j]);
            sr[i] +=a[i][j];
            sc[j] +=a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) r.insert(-sr[i]);
    for (int i = 1; i <= k; i++)
    {
        tr[i] = tr[i-1] - *r.begin();
        long long temp = *r.begin();
        r.erase(r.begin());
        r.insert(temp + p * m);
    }

    r.clear();
    for (int i = 1; i <= m; i++) r.insert(-sc[i]);
    for (int i = 1; i <= k; i++)
    {
        tc[i] = tc[i-1] - *r.begin();
        long long temp = *r.begin();
        r.erase(r.begin());
        r.insert(temp + p * n);
    }


    res = -1000000000000000000;
    for (int nr = 0; nr <= k; nr++)
    {
        res = max(res, tr[nr] + tc[k - nr] - (long long) nr * (k - nr) * p);
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

