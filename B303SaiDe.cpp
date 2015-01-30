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
double ry1,rx1,ry2,rx2;
int GCD(int a,int b)
{
    if (b==0) return a;
    return GCD(b,a%b);
}
int main()
{
    //freopen("B303.inp","r",stdin);
    //freopen("B303.out","w",stdout);
    cin>>n>>m>>x>>y>>a>>b;
    int gg=GCD(a,b);
    a/=gg;
    b/=gg;
    //cout<<a<<' '<<b<<endl;
    if (x<(a+1)/2) x=(a+1)/2;
    if (y<(b+1)/2) y=(b+1)/2;
    double sa=(a+0.0)/2;
    double sb=(b+0.0)/2;
    double t=min(min((x+0.0)/sa,(n-x+0.0)/sa),min((y+0.0)/sb,(m-y+0.0)/sb));
    int c=(int)t;
    rx1=x-c*sa;
    ry1=y-c*sb;
    rx2=x+c*sa;
    ry2=y+c*sb;
    cout<<(int)rx1<<' '<<(int)ry1<<' '<<(int)rx2<<' '<<(int)ry2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
