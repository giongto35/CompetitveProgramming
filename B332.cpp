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
const int maxn=200000+10;
int n,k;
long long a[maxn],s[maxn],F[maxn],G[maxn];
int vt1,vt2;
long long res;
int main()
{
    freopen("B332.inp","r",stdin);
    //freopen("B332.out","w",stdout);
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i],s[i]=s[i-1]+a[i];
    FOR(i,k,n)
    {
        //cout<<F[i-1]<<' '<<s[i]-s[i-k]<<endl;
        if (F[i-1]>=s[i]-s[i-k])
        {
            F[i]=F[i-1];
            G[i]=G[i-1];
        }
        else
        {
            F[i]=s[i]-s[i-k];
            G[i]=i;
        }
    }
    res=-1;
    FOR(i,k+1,n-k+1)
    {
        if (res<F[i-1]+s[i+k-1]-s[i-1])
        {
            res=F[i-1]+s[i+k-1]-s[i-1];
            vt1=G[i-1];
            vt2=i;
        }
        else
        if (res==F[i-1]+s[i+k-1]-s[i-1])
        {
            if (G[i-1]<vt1)
                vt1=G[i-1];
            else
            if (G[i-1]==vt1)
                vt2=min(vt2,i);
        }
    }
    //cout<<res<<endl;
    cout<<vt1-k+1<<' '<<vt2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

