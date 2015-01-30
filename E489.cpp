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

const int maxn = 1000 + 10;
int a[maxn];
int b[maxn];
int l;
double F[maxn];
int tr[maxn];
int n;

bool check(double val) {
    F[0] = 0;
    for (int i = 1; i <= n; i++) {
        F[i] = 1000000000000000000ll;
        for (int j = 0; j < i; j++) {
            if (F[i] > F[j] + sqrt(abs(a[i] - a[j] - l + 0.0)) - val * b[i]) {
                F[i] = F[j] + sqrt(abs(a[i] - a[j] - l + 0.0)) - val * b[i];
                tr[i] = j;
            }

        }
    }
    if (F[n] <= 0) return true; else return false;
}

int trace(int n) {
    if (n != 0)
    {
        trace(tr[n]);

        printf("%d ", n);
    }
}
int main()
{
    //freopen("E489.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&n,&l);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",&a[i],&b[i]);
    }


    double l = 0;
    double r = 1000000000;
    for (int i = 1; i <= 100; i++) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    check(l);
    //cout<<l<<endl;
    trace(n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

