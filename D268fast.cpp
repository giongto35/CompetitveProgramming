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
const int maxn = 1000+10;
const int cmod=1000000009;
const int maxh = 30+2;
int F[2][maxh][maxh][maxh][2];
int G[3];
int res,n,h,i;

inline int Add(int &res,int gt)
{
    res=res+gt;
    if (res>cmod) res-=cmod;
}

int main()
{
    //freopen("D268.inp","r",stdin);
    //freopen("D268.out","w",stdout);
    cin>>n>>h;
    F[1][1][1][1][0]=4;
    G[0]=1;

    if (h==1) G[0]=h+1;
    G[1]=h+1;
    FOR(ii,1,n-1)
    {
        i=ii%2;
        memset(F[1-i],0,sizeof(F[1-i]));
        FOR(j,0,h+1)
        FOR(l,0,h+1)
        FOR(x,0,1)
        FOR(k,0,h+1)
        {
            if (F[i][j][l][k][x]==0) continue;
//            cout<<i<<' '<<j<<' '<<l<<' '<<k<<' '<<x<<' '<<h<<endl;
            Add(F[1-i][min(j+1,h+1)][min(l+1,h+1)][min(k+1,h+1)][x],F[i][j][l][k][x]);
            Add(F[1-i][G[x]][min(l+1,h+1)][min(k+1,h+1)][j+1>h],F[i][j][l][k][x]);
            Add(F[1-i][min(j+1,h+1)][G[x]][min(k+1,h+1)][l+1>h],F[i][j][l][k][x]);
            Add(F[1-i][min(j+1,h+1)][min(l+1,h+1)][G[x]][k+1>h],F[i][j][l][k][x]);

        }
    }
    res=0;
    n%=2;
    FOR(j,0,h+1)
    FOR(k,0,h+1)
    FOR(l,0,h+1)
    FOR(x,0,1)
    if (j<=h-1||k<=h-1||l<=h-1||x==0)
    res=(res+F[n][j][k][l][x])%cmod;
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

