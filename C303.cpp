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
const int maxn = 5000+10;
const int maxd = 1000000+10;
int a[maxn];
int cnt[maxd];
int diff[maxd];
int tick[maxd];
vector<int> p[maxd];
int n,k;
int main()
{
    //freopen("C303.inp","r",stdin);
    //freopen("C303.out","w",stdout);
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) FOR(j,i+1,n) diff[abs(a[i]-a[j])]++;
    FOR(i,1,1000001)
    {
        int cnt=0;
        for(int j=i;j<=1000001;j+=i) cnt+=diff[j];
        if (cnt>(k+1)*k/2) continue;
        int res=0;
        FOR(j,1,n)
        {
            if (tick[a[j]%i]!=i) tick[a[j]%i]=i;
            else res++;
        }
        if (res<=k)
        {
            cout<<i;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

