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
const int cmod=1000000007;
const int maxn=10000+10;
int F[maxn],a[maxn];
int n;
int next[maxn][100+10];
int res;
int main()
{
    freopen("C314.inp","r",stdin);
    //freopen("C314.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(j,0,100) next[n][j]=n+1;
    DOW(i,n-1,0)
    {
        FOR(j,0,100) next[i][j]=next[i+1][j];
        next[i][a[i+1]]=i+1;
    }
    F[0]=1;
    FOR(i,0,n)
    {
        FOR(j,a[i],100)
        if (next[i][j]!=n+1)
        {
            F[next[i][j]]=(F[next[i][j]]+F[i]*j)%cmod;
        }
        if (i>0)
        res=(res+F[i])%cmod;
        cout<<F[i]<<' ';
    }
    cout<<endl;
    cout<<res<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

