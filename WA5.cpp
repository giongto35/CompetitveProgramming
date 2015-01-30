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
const int maxn=20000;
const double eps=0.0000001;
double GT[maxn];
long long res;
int main()
{
    //freopen("WA5.in","r",stdin);
    //freopen("WA5.out","w",stdout);
    GT[0]=log(1);
    FOR(i,1,20000) GT[i]=GT[i-1]+log(i);
    res=0;
    FOR(n,4,10000)
    FOR(k,1,10000)
    if (abs(GT[n]+GT[k]-GT[n+k-3])<=eps)
    {
        cout<<n<<endl;
        res=res+n;
        break;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

