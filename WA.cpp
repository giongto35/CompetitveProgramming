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
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;

double calc(double s)
{
    double l=0;
    double r=1;
    FOR(i,1,1000)
    {
        double mid=(l+r)/2;
        if (mid+(1/mid)<=s)
            r=mid;
        else
            l=mid;
    }
    return l;
}
int main()
{
    //freopen("WA.inp","r",stdin);
    //freopen("WA.out","w",stdout);
    double l=0;
    double r=1000000;
    FOR(i,1,1000)
    {
        double mid=(l+r)/2;
        double x= calc(mid*12*13);
        double y= calc(mid*5*13);
        double z= calc(mid*5*12);
        if (x*y+y*z+z*x<=1)
            r=mid;
        else
            l=mid;
    }
    //cout<<fixed<<setprecision(100)<<l<<endl;
    cout<<l<<endl;
        double x= calc(l*12*13);
        double y= calc(l*5*13);
        double z= calc(l*5*12);
    cout<<x<<' '<<y<<' '<<z<<endl;
    cout<<5*(x+1/x)<<' '<<12*(y+1/y)<<' '<<13*(z+1/z)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

//0.00641
//0.01539
//0.01667
//1/5
//2/3
//1
//1/625 + 16/81 + 1
//81/50625 + 10000/50625 + 50625
//60706
//50625
