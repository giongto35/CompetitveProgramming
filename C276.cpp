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
const int maxn=2*100000+10;
long long res;
int n,q,l,r;
int a[maxn],s[maxn];
int main()
{
    //freopen("C276.inp","r",stdin);
    //freopen("C276.out","w",stdout);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,q)
    {
        cin>>l>>r;
        s[l]++;
        s[r+1]--;
    }
    FOR(i,1,n)
        s[i]=s[i-1]+s[i];
    sort(s+1,s+1+n);
    sort(a+1,a+1+n);
    FOR(i,1,n)res+=(long long)s[i]*a[i];
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
