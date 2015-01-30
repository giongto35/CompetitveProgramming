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

const double eps = 0.0000000001;
double x,y,n;
double r;
int main()
{
    //freopen("FGYMCTU.inp","r",stdin);
    //freopen("FGYMCTU.out","w",stdout);
    //while (scanf("%f%d%d%f",&x,&y,&n,&r) == 4)
    while (cin >> x >> y >> n >> r)
    {
        //cout<<x<<' '<<y<<' '<<n<<' '<<r<<endl;
        if (x == 0 && y == 0 && n == 0) break;
        r = r / 12;
        for (int i = 1; i <= n * 12; i++)
        {
            x = x + x * r / 100;
            x -= y;
        }
        if (x <= 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

