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
int a[maxn];
int G[maxn];
int F[maxn];
int gtres;
int res[maxn];
int n;
vector<int> len[maxn];
int BIT[maxn];

void update(int i,int gt)//change long long
{
    if (i == 0) return;
    while (i<=100000)
    {
        BIT[i]=max(BIT[i], gt);
        i=i+(i & (-i));
    }
}


int get(int i)//change long long
{
    int gt=0;//change long long
    while (i>=1)
    {
        gt=max(BIT[i],gt);
        i=i-(i & (-i));
    }
    return gt;
}

int main()
{
    //freopen("E486.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        res[i] = 2;
        F[i] = get(a[i] - 1) + 1;
        gtres = max(gtres, F[i]);
        update(a[i], F[i]);
    }

    memset(BIT, 0, sizeof(BIT));
    for (int i = n; i >= 1; i--){
        scanf("%d",&a[i]);
        G[i] = get(100001 - (a[i] + 1)) + 1;
        if (F[i] + G[i] - 1 != gtres) res[i] = 1;
        update(100001 - a[i], G[i]);
    }

    for (int i = 1; i <= n; i++){
        if (res[i] != 1) {
            len[F[i]].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (len[i].size() == 1) {
                res[len[i][0]] = 3;
                continue;
        }
    }
    for (int i = 1; i <= n; i++)
    printf("%d", res[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

