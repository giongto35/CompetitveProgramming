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
const int maxn=100+10;
int a[maxn];
int main()
{
    //freopen("WA2.in","r",stdin);
    //freopen("WA2.out","w",stdout);
    FOR(i,1,7) a[i]=21;
    FOR(i,8,100) a[i]=20;
    long long res=0;
    FOR(i,1,100)
    FOR(j,i+1,100)
    FOR(k,j+1,100)
    {
        res=res+a[i]*a[j]*a[k];
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
