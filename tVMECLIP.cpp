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
long long x1,y11,v1,x2,y2,v2;
long long random(long long n)
{
    return ((long long)rand()*rand())%n;
}
int main()
{
    //freopen("VMECLIP.inp","r",stdin);
    freopen("8.in","w",stdout);
    while (true)
    {
        x1=random(2000000000)-1000000000;y11=random(2000000000)-1000000000; v1=random(1000000000);
        x2=random(2000000000)-1000000000;y2=random(2000000000)-1000000000; v2=random(1000000000);
        if (x1*x1+y11*y11<x2*x2+y2*y2) break;
    }
    cout<<x1<<' '<<y11<<' '<<v1<<endl;
    cout<<x2<<' '<<y2<<' '<<v2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

