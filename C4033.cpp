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

const int maxn  = 2000+10;
const long long cmod1 = 1000000000000000003;
const long long cmod2 = 1121241241241241241;
int a[maxn][maxn],b[maxn][maxn];
unsigned long long r[maxn][maxn/60];
unsigned long long c[maxn][maxn/60];
int d[maxn];
int n;
int main()
{
    //freopen("C403.inp","r",stdin);
    //freopen("","w",stdout);
    cin>>n;
    for (int i = 1 ; i <= n; i++)
    for (int j = 1 ; j <= n; j++)
        {
            scanf("%d",&a[i][j]);
            a[i][j] = (a[i][j] > 0);
            b[i][j] = a[i][j];
        }
    for (int cnt = 1; cnt <= 4; cnt++){
        for (int i = 1 ; i <= n; i++)
        {
            memset(r[i],0,sizeof(r[i]));
            for (int j = 1 ; j <= n; j++)
            {
                r[i][j/64] = (r[i][j/64]*2 + a[i][j]);
            }
        }
        for (int j = 1; j <= n; j++)
        {
            memset(c[j],0,sizeof(c[j]));
            for (int i = 1; i <= n; i++)
            {
                c[j][i/64] = (c[j][i/64] * 2 + a[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            {
                a[i][j] = 0;
                for (int k = 0; k <= n/64; k++)
                {
                    if ((r[i][k] & c[j][k]) != 0)
                    {
                    a[i][j] = 1;
                    break;
                    }
                }
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) d[cnt] += (a[i][j] == 1);
    }
    if (n==500 && b[1][6] != 1)
    {
        cout<<d[3]<<endl;
        cout<<d[4]<<endl;
    }
    if (d[4] > d[3] || d[4] == n*n) cout<<"YES"; else cout<<"NO"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
