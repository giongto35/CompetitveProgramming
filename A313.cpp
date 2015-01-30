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
int n;
bool rev;
int main()
{
    //freopen("A313.inp","r",stdin);
    //freopen("A313.out","w",stdout);
    cin>>n;
    if (n<0) rev=true;
    n=abs(n);
    int s1=n/10;
    int s2=(n/100)*10+n%10;
    if (rev)
    {
        s1=-s1;s2=-s2;n=-n;
    }
    cout<<max(s1,max(s2,n));
    fclose(stdin);
    fclose(stdout);
    return 0;
}

