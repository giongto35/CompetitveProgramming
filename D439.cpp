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

const int maxn = 100000+10;
int n,m;
int a[maxn];
int b[maxn];
vector<int> c;
long long s1[maxn];
long long s2[maxn];
long long res;


int main()
{
    //freopen("D439.inp","r",stdin);
    //freopen("D439.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        c.push_back(a[i]);

    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d",&b[i]);
        c.push_back(b[i]);

    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    for (int i = 1; i <= n; i++) s1[i] = s1[i-1] + a[i];
    for (int i = 1; i <= m; i++) s2[i] = s2[i-1] + b[i];
    sort(c.begin(), c.end());
    int vta = 0;
    int vtb = 0;
    res = 1000000000000000000ll;
    for (int i = 0; i < c.size(); i++)
    {
        int gt = c[i];
        while (vta + 1 <= n && a[vta + 1] <= gt) vta++;
        while (vtb + 1 <= m && b[vtb + 1] <= gt) vtb++;
        //cout<<gt<<' '<<vta<<' '<<vtb<<' '<<gt * vta - s1[vta]<<' '<<(s2[m] - s2[vtb]) - (long long)(m - vtb) * gt<<endl;
        res = min(res,(long long)gt * vta - s1[vta] + (s2[m] - s2[vtb]) - (long long)(m - vtb) * gt);
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

