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
const int cmod=1000000007;
int n;
const int kq[16]={1,0,18,0,1800,0,136,0,2035,0,37460,0,649050,0,687721184,0};
int main()
{
    //freopen("D285.in","r",stdin);
    //freopen("","w",stdout);
    cin>>n;
    int res=kq[n-1];
    FOR(i,1,n)
    res=(res*i)%cmod;
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

