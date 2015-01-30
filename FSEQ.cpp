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

const int maxn = 30000+10;
int n;
int a[maxn];
int F[maxn]; // F[i] la day fibonaci dai nhat ket thuc tai i
int res; // res la ket qua
int main()
{
    freopen("FSEQ.inp","r",stdin);
    freopen("FSEQ.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
    F[1] = 1;
    F[2] = 2;
    res = 2;
    for (int i = 3; i <= n; i++)
    {
        if (a[i-1] + a[i-2] == a[i]) F[i] = F[i-1] + 1; // neu ma tai i thoa man day fibonaci thi F[i] = day dai nhat tai vi tri (i-1) + 1
        else F[i] = 2; // neu ko thoa thi day con dai nhat tai i = 2
        res = max(res,F[i]);
    }
    printf("%d\n",res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

