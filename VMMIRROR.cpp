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
const int maxn = 100000+10;
int a[maxn],n,q;
int s,t;
int gcd1;

int gcd(int a,int b)
{
    if (b==0) return a;
    return gcd(b,a % b);
}
int main()
{
    //freopen("VMMIRROR.inp","r",stdin);
    //freopen("VMMIRROR.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    gcd1=(a[1]-a[n]);
    FOR(i,2,n-1) gcd1=gcd(gcd1,a[i]-a[n]);
    cin>>q;
    FOR(i,1,q)
    {
        cin>>s>>t;
        if ((s+t-2*a[n])%2==0&&((s+t-2*a[n])/2)%gcd1==0) cout<<"YES"<<endl; else
        if ((t-s)%2==0&&((t-s)/2)%gcd1==0) cout<<"YES"<<endl; else
        cout<<"NO"<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

