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

const int maxn = 40000+10;
int N,D;
long long res;
unsigned int IT[maxn*4][4];
int n,d,u,v;

void update(int node, int l, int r, const int vt, const int gt)
{
    if (vt < l || vt > r) return ;
    if (l == r && l == vt)
    {
        IT[node][0] = 0;
        IT[node][3] = gt;
        return ;
    }
    int mid = (l + r) >> 1;
    update(node << 1, l, mid, vt, gt);
    update((node << 1) + 1, mid + 1, r, vt, gt);
    FOR(i,0,1)
    FOR(j,0,1)
    {
        IT[node][(i << 1) + j] = 0;
        FOR(k,0,1)
        IT[node][(i << 1) + j] = max(IT[node][(i << 1) + j],IT[node << 1][(i << 1) + k] + IT[(node << 1) + 1][((1-k) << 1) + j]);
        IT[node][(i << 1) + j] = max(IT[node][(i << 1) + j],IT[node << 1][(i << 1)]     + IT[(node << 1) + 1][             + j]);
    }
}

int main()
{
    freopen("optmilk.in","r",stdin);
    freopen("optmilk.out","w",stdout);
    scanf("%d%d",&n,&d);
    FOR(i,1,n) scanf("%d",&u),update(1,1,n,i,u);
        //cout<<max(max(IT[1][0],IT[1][1]),max(IT[1][2],IT[1][3]))<<endl;
    res=0;
    FOR(i,1,d)
    {
        scanf("%d%d",&u,&v);
        update(1,1,n,u,v);
        //cout<<max(max(IT[1][0],IT[1][1]),max(IT[1][2],IT[1][3]))<<endl;
        res += max(max(IT[1][0],IT[1][1]),max(IT[1][2],IT[1][3]));
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

