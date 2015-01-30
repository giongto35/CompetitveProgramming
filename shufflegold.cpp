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
const int maxn = 1000000+10;
int n,m,q;
int vt;
int P[maxn];
int PT[maxn];

void process()
{
    int bd = vt;
    int idx = 1;
    if (vt + m > n)
    {
        idx = vt - (n - m);
        bd = n - m + 1;
    }
    while(true)
    {
        int nidx = PT[idx];
        int nvt = vt + nidx - idx;
        //cout<<vt<<' '<<bd<<' '<<idx<<' '<<nidx<<' '<<nvt<<endl;
        bd--;
        idx = nidx + 1;
        vt = nvt;
        if (bd == 0) break;
        if (vt > bd + m - 1||idx > m) break;
    }
    cout<<vt<<endl;
}

int main()
{
    freopen("shufflegold.in","r",stdin);
    freopen("shufflegold.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,m) scanf("%d",&P[i]),PT[P[i]] = i;
    FOR(i,1,q)
    {
        scanf("%d",&vt);
        vt = n - vt + 1;
        process();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
