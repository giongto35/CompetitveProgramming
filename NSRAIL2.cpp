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
const int maxn=500+10;
int F[maxn][maxn][maxn];
int G[maxn][maxn];//den i thang gan nhat la j
int a[maxn][maxn];
int n,sk;
int res;
int main()
{
    //freopen("NSRAIL.inp","r",stdin);
    //freopen("NSRAIL.out","w",stdout);
    cin>>n>>sk;
    FOR(i,1,n)
    FOR(j,1,n)
    cin>>a[i][j];
    FOR(i,1,n)
    FOR(j,i+1,n)
    {
        a[i][j]=a[i][j]+a[j][i];
        a[j][i]=a[i][j];
    }
    FOR(i,2,n)
    {
        FOR(j,1,i-1)
        G[i][j]=G[i][j-1]+a[i][j];
    }
    //cout<<G[3][2]<<endl;
    FOR(i,1,n)
    {
        FOR(j,0,min(i-1,sk))
        FOR(k,1,i)
        {
            //ko chon tram giua i voi i+1
            if (j>0)
            F[i+1][j][k]=max(F[i+1][j][k],F[i][j][k]+G[i+1][k]);
            //chon tram giua i voi i+1
            F[i+1][j+1][i]=max(F[i+1][j+1][i],F[i][j][k]+G[i+1][i]);
            //if (F[i+1][j+1][i]==41) cout<<i<<' '<<j<<' '<<k<<' '<<F[i][j][k]<<' '<<G[i+1][i]<<endl;
            //if (F[3][1][2]==16)  cout<<i<<' '<<j<<' '<<k<<' '<<F[i][j][k]<<' '<<G[i+1][i]<<endl;
        }
    }
    res=0;
    //cout<<F[3][1][2]<<endl;
    //cout<<G[3][2]<<endl;
    FOR (k,1,n)
    res=max(res,F[n][sk][k]);
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

