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
const int maxn=1000+10;
int b[maxn][maxn];
int a[maxn];int n;

int main()
{
    //freopen("sume.inp","r",stdin);
    //freopen("sume.out","w",stdout);
    cin>>n;
    if (n==2)
    {
        cout<<1<<' '<<1<<endl;
        return 0;
    }
    FOR(i,0,n-1)
    FOR(j,0,n-1)
    cin>>b[i][j];
    FOR(i,0,n-1)
        cout<<(b[i][(i-1+n)%n]+b[i][(i+1)%n]-b[(i-1+n)%n][(i+1)%n])/2<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

