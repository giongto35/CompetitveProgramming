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
int x,y,n;
double r,k;

double power(double x, int n)
{
    if (n == 0) return 1;
    if (n % 2 == 1) return x * power(x,n-1);
    else
    {
        double b = power(x, n / 2);
        return b * b;
    }
}
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("FGYMCTU.out","w",stdout);
    while (scanf("%d%d%d%lf",&x,&y,&n,&r) == 4)
    //while (cin >> x >> y >> n >> r)
    {
        //cout<<x<<' '<<y<<' '<<n<<' '<<r<<endl;
        if (x == 0 && y == 0 && n == 0) break;
        if (r <= eps)
        {
            if (x <= (long long)y * n * 12)
                printf("YES\n");
            else //cout<<"NO"<<endl;
                printf("NO\n");
        }
        else
        {
            double need = 0;
            r = r / 12.0;
            /*for (int i = 1; i <= n * 12; i++)
            {
                need = need + y;
                need = need * 100 / (100 + r);
            }*/
            k = 100 / (100 + r);
            double need2 = (double)y * (pow(k,n*12 + 1) - k) / (k - 1);
            //cout<<x<<' '<<need<<' '<<need2<<endl;
            if (x <= need2) //cout<<"YES"<<endl;
                printf("YES\n");
            else //cout<<"NO"<<endl;
                printf("NO\n");
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

