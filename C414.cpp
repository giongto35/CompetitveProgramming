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

const int maxn = 1058576;
long long F[30][2];
int cur[30];
int a[maxn];
int n,m,q,sn;
int BIT[maxn];
int maxso;
int u;
long long res;
void update(int i,int gt)
{
    if (i == 0) return ;
    while (i<=maxso)
    {
        BIT[i]=BIT[i] + gt;
        i=i+(i & (-i));
    }
}

long long get(int i)
{
    long long gt=0;
    while (i>=1)
    {
        gt = gt + BIT[i];
        i=i-(i & (-i));
    }
    return gt;
}

void roirachoa()
{
    vector<int> b(a+1,a+sn+1);
    sort(b.begin(),b.end());
    vector<int>::iterator it = unique(b.begin(),b.end());
    b.resize(distance(b.begin(),it));
    maxso = b.size();
    for (int i = 1; i <= sn; i++)
        a[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin() + 1;
}
int main()
{
    //freopen("C414.inp","r",stdin);
    //freopen("C414.out","w",stdout);
    scanf("%d",&n);
    sn = (1 << n);
    for (int i = 1; i <= sn; i ++) scanf("%d",&a[i]);
    roirachoa();
    memset(BIT,0,sizeof(BIT));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sn; j+= (1 << i))
        {
            for (int k = j; k <= j + (1 << (i-1)) - 1; k++)
                update(a[k],1);
            for (int k = j + (1 << (i-1)); k <= j + (1 << i) - 1; k++)
                F[i][0] += get(a[k] - 1);
            for (int k = j; k <= j + (1 << (i-1)) - 1; k++)
                update(a[k],-1);
            for (int k = j + (1 << (i-1)); k <= j + (1 << i) - 1; k++)
                update(a[k],1);
            for (int k = j; k <= j + (1 << (i-1)) - 1; k++)
                F[i][1] += get(a[k] - 1);
            for (int k = j + (1 << (i-1)); k <= j + (1 << i) - 1; k++)
                update(a[k],-1);
        }
    }
    scanf("%d",&q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d",&u);
        for(int i = u; i >= 1; i--) cur[i] = 1-cur[i];
        res = 0;
        for(int i = 1; i <= n; i++)
            res = res + F[i][1-cur[i]];
        //cout<<res<<endl;
        printf("%I64d\n",res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
