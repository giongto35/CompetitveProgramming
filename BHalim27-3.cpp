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
unsigned long long p,q,n;

unsigned long long pow(unsigned long long x,unsigned long long n)
{
    if (n==0) return 1;
    if (n%2==0)
    {
        unsigned long long s=pow(x,n/2);
        return s*s;
    }
    else
        return pow(x,n-1)*x;
}
unsigned long long F(unsigned long long n)
{
    if (n==0) return 2;
    if (n==1) return p;
    if (n%2==0)
    {
        unsigned long long s=F(n/2);
        return s*s-2*pow(q,n/2);
    }
    else
        return F(n-1)*p-q*F(n-2);
}

int main()
{
    //freopen("Bhalim.inp","r",stdin);
    //freopen("Bhalim.out","w",stdout);
    while (true)
    {
        cin>>p>>q>>n;
        if (p==0&&q==0) break;
        cout<<F(n)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

