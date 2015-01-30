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
const int maxn = 1000+10;
int x11[maxn],y11[maxn],x12[maxn],y12[maxn];
int x21[maxn],y21[maxn],x22[maxn],y22[maxn];
int l;
int res,n,m;
int main()
{
    //freopen("D391.inp","r",stdin);
    //freopen("D391.out","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,n)
    {
        scanf("%d%d%d",&x11[i],&y11[i],&l);
        x12[i] = x11[i];
        y12[i] = y11[i] + l;
    }
    FOR(i,1,m)
    {
        scanf("%d%d%d",&x21[i],&y21[i],&l);
        x22[i] = x21[i] + l;
        y22[i] = y21[i];
    }
    res = 0;
    FOR(i,1,n)
    FOR(j,1,m)
    {
        int cx = x11[i];
        int cy = y21[j];
        res = max(res, min(min(cx - x21[j],x22[j] - cx),min(cy - y11[i], y12[i] - cy)));
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

