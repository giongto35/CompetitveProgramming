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
int n,m,x,y,a,b,rx1,ry1,rx2,ry2;
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
    int g=GCD(a,b);
    a/=g;
    b/=g;
    int t=min(n/a,m/b);
    a=a*t;
    b=b*t;
    rx1=x-(a+1)/2;
    ry1=y-(b+1)/2;
    rx1=max(rx1,0);
    ry1=max(ry1,0);
    rx2=rx1+a;
    ry2=ry1+b;
    rx2=min(rx2,n);
    ry2=min(ry2,m);
    rx1=rx2-a;
    ry1=ry2-b;
    cout<<rx1<<' '<<ry1<<' '<<rx2<<' '<<ry2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

