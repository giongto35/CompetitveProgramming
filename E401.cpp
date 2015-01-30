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
const double eps = 0.00001;
int a,b;
int l,r,p;
long long res;
long long spair;
int n,m;

long long calc(double v)
{
    int ml = sqrt((long long)n * n + (long long)m * m);
    for (int a = 1; a <= min(n,ml); a++)
    {
        for (int b = a*2; b <= min(m,ml); b+= a)
        {
            cout<<a * a<<' '<<b*b<<' '<<v*v<<endl;
            if ((long long) a * a + (long long) b * b <= v * v)
            {
                cout<<a<<' '<<b<<' '<<(n - a) * (m- b)<<endl;
                res = res + 2*(long long)(n - a) * (m- b);
            }
        }
    }
    res = res + (long long) n * (m - 2 + 1) * (m - 2) / 2;
    res = res + (long long) m * (n - 2 + 1) * (n - 2) / 2;
    spair = (long long)(n * m) * (n * m -1) / 2;
    cout<<spair<<endl;
    return spair - res;
}

int main()
{
    freopen("E401.inp","r",stdin);
    //freopen("","w",stdout);
    cin >>n >>m;
    n++;
    m++;
    cin>>l>>r>>p;
    cout<<calc(r)<<endl;
    //cout<<calc(r) - calc(l-eps)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

