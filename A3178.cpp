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
const int maxn=100000+10;
int n;
long long a[maxn],s,j;
int main()
{
    //freopen("A3178.inp","r",stdin);
    //freopen("A3178.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    s=0;
    FOR(i,1,n-1)
    {
        s=s+a[i];
        j=(int)log2(n-i);
        a[i+(1<<j)]+=a[i];
        cout<<s<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

