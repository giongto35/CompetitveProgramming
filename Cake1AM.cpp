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

int T;
int x,y,x2,y2,x3,y3,x4,y4;
long long res;
int main()
{
    //freopen("Cake1AM.inp","r",stdin);
    //freopen("Cake1AM.out","w",stdout);
    scanf("%d",&T);
    FOR(i,1,T)
    {
        scanf("%d%d%d%d",&x,&y,&x2,&y2);
        scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
        cout<<(x2-x)*(y2-y) + (x4-x3)*(y4-y3) - max(0,min(x4,x2) - max(x,x3)) * max(0,min(y4,y2) - max(y,y3))<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

