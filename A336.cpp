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
bool bx,by;
int x1,x2,yy1,y2,x,y;
int main()
{
    //freopen("A336.inp","r",stdin);
    //freopen("A336.out","w",stdout);
    cin>>x>>y;
    if (x<0) bx=true;
    if (y<0) by=true;
    x=abs(x);
    y=abs(y);

    int yy;
    if (by==false)yy=(x+y);else yy=-(x+y);
    if (bx==false)
    {
        x1=0;
        x2=x+y;
        yy1=yy;
        y2=0;
    }
    else
    {
        x1=-(x+y);
        x2=0;
        yy1=0;
        y2=yy;
    }

    cout<<x1<<' '<<yy1<<' '<<x2<<' '<<y2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

