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

const int cmod = 1000000007;
const int maxn = 1000000 + 10;
int n;
int a[maxn];
int F[maxn];
long long res;
long long sum;
int b[2][maxn];
long long gt[maxn];
void preprocessing()
{
    F[0] = 0;
    gt[0] = 1;
    for (int i = 1; i<= n ; i++)
    {
        gt[i] = (gt[i-1] * i) % cmod;
        //cout<<i<<' '<<gt[i] * F[i-1]<<' '<<((long long)(i - 1) * (i) / 2)% cmod * gt[i-1]<<endl;
        F[i] = (F[i] + (long long)i * F[i-1] + ((long long)(i - 1) * (i) / 2)% cmod * gt[i-1] ) % cmod;
    }
    //for (int i = 1; i<=n; i++) cout<<F[i]<<' ';
    // cout<<endl;
}

int get(int k, int u)
{
    int res = 0;
    for (int i = u; i >= 1; i -= (i & (-i))) res =(res + b[k][i])% cmod;
    return res;
}

void update(int k, int u , int gt )
{
    if (u == 0) return ;
    for (int i = u; i <= n; i += (i & (-i))) b[k][i] = b[k][i] + gt;
}

void process()
{
    //1 : left
    //0 : right
    long long sum = 0;
    long long sfront = 0;
    res = 0;

    for (int i = 1; i <= n; i++) update(0,i,1);
    for (int i = 1; i <= n; i++)
    {
        long long sl = get(0,a[i]-1);
        res = (res + (long long)gt[n - i] * (((sl - 1) * sl / 2) % cmod)) % cmod;
        //cout<<gt[n - i] * (sl - 1) * sl / 2   <<' '<<sl * F[n-i]<<' '<<sl *(sfront + sum) * gt[n-i]<<endl;
        res = (res + (long long)sl * (((sfront + sum) * gt[n-i]) % cmod + F[n - i])) % cmod;
        sum = (sum - (get(1,n) - get(1, a[i]))) % cmod;
        sum = (sum + get(0, a[i] - 1)) % cmod;
        //cout<<i<<' '<<res<<' '<<sum<<' '<<sfront<<endl;
        update(1,a[i],1);
        update(0,a[i],-1);
        sfront = (sfront + (get(1,n) - get(1, a[i]))) % cmod;
    }
    res = (res + sfront) % cmod;
    cout<<(res+cmod)% cmod<<endl;
}

int main()
{
    //freopen("D396.inp","r",stdin);
    //freopen("D396.out","w",stdout);
    scanf("%d",&n);
    for (int i =1 ; i <= n; i++) scanf("%d",&a[i]);
    preprocessing();
    /*while(next_permutation(a+1,a+1+n))
    {
        memset(b,0,sizeof(b));*/
        process() ;
    //}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
