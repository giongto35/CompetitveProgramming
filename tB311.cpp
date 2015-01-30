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
int n,m,p;
int main()
{
    //freopen("B311.inp","r",stdin);
    freopen("B311.inp","w",stdout);
    cin>>n>>m>>p;
    cout<<n<<' '<<m<<' '<<p<<endl;
    FOR(i,1,n-1) cout<<rand()%10000+1<<' ';
    cout<<endl;
    FOR(i,1,m)
    cout<<rand()%n+1<<' '<<((long long)rand()*rand())%1000000000<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

