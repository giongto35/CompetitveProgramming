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
const int maxn = 2*100000+10;
const int cmod = 1000000000;
int a[maxn];
int F[maxn];

int main()
{
    freopen("E1.inp","r",stdin);
    freopen("E1.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,n) cin>>a[i];
    F[0]=1;
    F[1]=1;
    FOR(i,2,n)
    F[i]=(F[i-2]+F[i-1])%cmod;
    FOR(i,1,m)
    {
        cin>>t>>l>>r;
        if (t==1)
            a[l]=r;
        else
        {
            long long res=0;
            FOR(i,l,r)
                res=(res+(long long)(a[i]*F[i-l]))%cmod;
            cout<<res<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

