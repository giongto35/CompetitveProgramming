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
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int res,n,x1,yy1,x2,y2,x3,y3;
int dist(int x1,int yy1,int x2,int y2)
{
    return (x2-x1)*(x2-x1)+(y2-yy1)*(y2-yy1);
}
int main()
{
    //freopen("RIGHTRI.inp","r",stdin);
    //freopen("RIGHTRI.out","w",stdout);
    scanf("%d",&n);
    res=0;
    FOR(i,1,n)
    {
        scanf("%d%d%d%d%d%d",&x1,&yy1,&x2,&y2,&x3,&y3);
        if (dist(x1,yy1,x2,y2)+dist(x2,y2,x3,y3)==dist(x1,yy1,x3,y3)||
            dist(x1,yy1,x3,y3)+dist(x2,y2,x3,y3)==dist(x1,yy1,x2,y2)||
            dist(x2,y2,x1,yy1)+dist(x1,yy1,x3,y3)==dist(x2,y2,x3,y3))
                res++;
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

