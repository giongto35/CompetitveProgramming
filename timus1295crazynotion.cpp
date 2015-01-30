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
const int max0=2;
long long g[4][300001][max0+1];
long long r[300001][max0+1];
long long m10[max0+1];
int n;
//dint res[300001];
int smax;
int main()
{
    //freopen("crazynotion.inp","r",stdin);
    //freopen("crazynotion.out","w",stdout);
    cin>>n;
    m10[0]=1;
    FOR(i,1,max0) m10[i]=m10[i-1]*10;
    FOR(t,0,3)
    {
        FOR(j,1,max0)
        g[t][0][j]=1;
        FOR(i,1,n)
        FOR(j,1,max0)
        {
            g[t][i][j]=(g[t][i-1][j]*(t+1))%m10[j];
            r[i][j]=(r[i][j]+g[t][i][j])%m10[j];
        }
    }
    smax=0;
    FOR(j,1,max0) if (r[n][j]==0) smax=j;
    cout<<smax;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

