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
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int n,m,x,y,a,b;
double x1,x2,y3,y2;
int main()
{
    freopen("B303.inp","r",stdin);
    //freopen("B303.out","w",stdout);
    cin>>n>>m>>x>>y>>a>>b;
    double sa=(a+0.0)/2;
    double sb=(b+0.0)/2;
    double t=min(min((n-x+0.0)/sa,(x+0.0)/sa),min((m-y+0.0)/sb,(y+0.0)/sb));
    cout<<t<<endl;
    x1=x-t*sa;
    x2=x+t*sa;
    y3=y-t*sb;
    y2=y+t*sb;
    if (x1-(int)x1>0) x1-=0.5,x2-=0.5;
    if (y3-(int)y3>0) y3-=0.5,y2-=0.5;
    cout<<(int)x1<<' '<<(int)y3<<' '<<int(x2)<<' '<<(int)y2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

