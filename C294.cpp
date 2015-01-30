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
const int cmod=1000000007;
int pow2[maxn],a[maxn],n,m;
int C[maxn][maxn];
long long res;
int main()
{
    //freopen("C294.in","r",stdin);
    //freopen("C294.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,m)
    cin>>a[i];
    C[0][0]=1;
    pow2[0]=1;
    FOR(i,1,n)
    {
        C[i][0]=1;
        FOR(j,1,i)
        C[i][j]=(C[i-1][j]+C[i-1][j-1])%cmod;
        pow2[i]=(pow2[i-1]*2)%cmod;
    }
    sort(a+1,a+1+m);
    a[m+1]=n+1;
    res=1;
    int sum=0;
    FOR(i,1,m+1)
    {
        int x=a[i]-a[i-1]-1;
        //cout<<x<<' '<<sum<<endl;
        sum+=x;
        res=(res*C[sum][x])%cmod;
        //cout<<res<<' '<<C[sum][x<<endl;
        if (i!=1&&i!=m+1&&x>1)
            res=(res*pow2[x-1])%cmod;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

