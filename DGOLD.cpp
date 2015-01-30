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
map <int, int> c;
int a[100];
int res;
int n;

void GEN(int vt,int sum,int sum2)
{
    if (vt==n/2+1)
    {
        c[sum]=max(c[sum],sum2);
        return;
    }
    GEN(vt+1,sum+a[vt],sum2+a[vt]);
    GEN(vt+1,sum-a[vt],sum2);
    GEN(vt+1,sum,sum2);
}

void GEN2(int vt,int sum,int sum2)
{
    if (vt==n+1)
    {
        int v=c[-sum];
        if (v!=0) //cout<<c[-sum]<<' '<<' '<<sum<<' '<<sum2;
        res=max(res,v+sum2);
        return;
    }
    GEN2(vt+1,sum+a[vt],sum2+a[vt]);
    GEN2(vt+1,sum-a[vt],sum2);
    GEN2(vt+1,sum,sum2);
}

int main()
{
    //freopen("DGOLD.inp","r",stdin);
    //freopen("DGOLD.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    GEN(1,0,0);
    GEN2(n/2+1,0,0);
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


