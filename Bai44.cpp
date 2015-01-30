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
#include <iomanip>
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
const double pi=atan(1)*2;
const double eps =0.0000001;
using namespace std;
double x1,x2,y11,y2,v1,v2,s1,s2,r1,r2,t;

bool EQ(double x ,double y)
{
    return abs(x-y)<=eps;
}
int main()
{
    freopen("6.in","r",stdin);
    freopen("6.out","w",stdout);
    cin>>x1>>y11>>v1;
    cin>>x2>>y2>>v2;
    //cout<<pi<<endl;
    r1=sqrt(x1*x1+y11*y11);
    r2=sqrt(x2*x2+y2*y2);
    s1=atan2(y11,x1);
    s2=atan2(y2,x2);
    v1=v1/r1;
    v2=v2/r2;
    //cout<<s1<<' '<<s2<<' '<<v1<<' '<<v2<<' '<<r1<<' '<<r2<<endl;
    if (EQ(s1,s2))
    {
        cout<<0;
        return 0;
    }
    if (EQ(v1,v2))
    {
        cout<<-1;
        return 0;
    }
    t=1000000000;
    FOR(i,-1,1)
    {
        double t2=(i*(2*pi)-(s1-s2))/(v1-v2);
        if (t2>=0) t=min(t,t2);
    }
    cout<<fixed<<setprecision(6)<<t<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

