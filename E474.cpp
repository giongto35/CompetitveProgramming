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
int F[maxn];
long long a[maxn];
vector<long long> b;
int n,maxso;
int tr[maxn];
int d;
int res;
int BIT[3][maxn];

void update(int i,int gt,int k)//change long long
{
    while (i<=maxso)
    {
        if (BIT[k][i] == 0 || F[BIT[k][i]] < F[gt])
            BIT[k][i] = gt;
        i=i+(i & (-i));
    }
}

int get(int i, int k)//change long long
{
    int gt=0;//change long long
    while (i>=1)
    {
        if (gt == 0 || F[gt] < F[BIT[k][i]])
            gt = BIT[k][i];
        i=i-(i & (-i));
    }
    return gt;
}

void trace(int u)
{
    if (u == 0) return;
    trace(tr[u]);
    printf("%d ", u);
}
void roirachoa()
{
    b.clear();
    for (int i = 1; i <= n; i ++) b.push_back(a[i]);
    sort(b.begin(),b.end());
    b.resize(distance(b.begin(),unique(b.begin(),b.end())));
    maxso = b.size();
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin() + 1;
}

int main()
{
    //freopen("E474.inp","r",stdin);
    //freopen("E474.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i = 1; i <= n; i++)
        scanf("%I64d",&a[i]);
    roirachoa();
    res = -1;
    for(int i = 1; i <= n; i++)
    {
        F[i] = 1;
        vector<long long>::iterator it = lower_bound(b.begin(), b.end(), b[a[i] - 1] + (long long)d);
        if (it != b.end())
        {
            int vt = it - b.begin() + 1;
            int temp = get(maxso - vt + 1, 2);
            if (F[i] < F[temp] + 1)
            {
                F[i] = F[temp] + 1;
                tr[i] = temp;
            }
        }
        it = upper_bound(b.begin(), b.end(), b[a[i] - 1] - (long long)d);
        if (it != b.begin())
        {
            it--;
            int vt = it - b.begin() + 1;
            int temp = get(vt, 1);
            if (F[i] < F[temp] + 1)
            {
                F[i] = F[temp] + 1;
                tr[i] = temp;
            }
        }
        update(a[i], i, 1);
        update(maxso - a[i] + 1, i, 2);
        if (res == -1 || F[i] > F[res])
            res = i;
    }
    printf("%d\n", F[res]);
    trace(res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

