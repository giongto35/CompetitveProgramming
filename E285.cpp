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
const int cmod =1000000007;
long long F[maxn][maxn][5];
int s1,s0;
int n,k;
int main()
{
    //freopen("E285.in","r",stdin);
    //freopen("E285.out","w",stdout);
    cin>>n>>k;
    F[1][0][4]=1;
    FOR(i,1,n-1)
    FOR(j,0,i)
    FOR(t,0,4)
    {
        if (F[i][j][t]==0) continue;
        //cout<<i<<' '<<j<<' '<<t<<' '<<F[i][j][t]<<endl;
        if (t==4)
        {
            s1=j;
            s0=i-j-1;
            F[i+1][j][0+0]=(F[i+1][j][0+0]+F[i][j][t]*s0)%cmod;
            F[i+1][j-1][0+0]=(F[i+1][j-1][0+0]+F[i][j][t]*s1)%cmod;
            F[i+1][j+2][2+1]=(F[i+1][j+2][2+1]+F[i][j][t])%cmod;
            F[i+1][j][4]=(F[i+1][j][4]+F[i][j][t])%cmod;
            continue;
        }
        int bstn=t/2;
        int bn=t%2;
        if (bstn==1) s1=j-1,s0=i-j;else s1=j,s0=i-j-1;
        if (bn==1) s1--;else s0--;

        F[i+1][j][0]=(F[i+1][j][0]+F[i][j][t]*s0)%cmod;
        F[i+1][j-1][0]=(F[i+1][j-1][0]+F[i][j][t]*s1)%cmod;
        F[i+1][j+(bstn==0)][0+1]=(F[i+1][j+(bstn==0)][0+1]+F[i][j][t])%cmod;//swap voi so bstn
        F[i+1][j+(bn==0)][2+0]=(F[i+1][j+(bn==0)][2+0]+F[i][j][t])%cmod;
        F[i+1][j][4]=(F[i+1][j][4]+F[i][j][t])%cmod;

    }
    int res=0;
    FOR(t,0,4) res=(res+F[n][k][t])%cmod;
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

