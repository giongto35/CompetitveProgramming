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
#include <cstring>
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
int F[2][maxn][maxn];
int G[maxn][maxn];//den i thang gan nhat la j
int a[maxn][maxn];
int n,sk,t;
int res;
int main()
{
    freopen("NSRAIL.inp","r",stdin);
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
    t=0;
    FOR(i,1,n-1)
    {
        memset(F[1-t],0,sizeof(F[1-t]));
        FOR(j,0,min(i-1,sk))
        FOR(k,1,i)
        {
            //ko chon tram giua i voi i+1
            if (j>0)
            F[1-t][j][k]=max(F[1-t][j][k],F[t][j][k]+G[i+1][k]);
            //chon tram giua i voi i+1
            F[1-t][j+1][i]=max(F[1-t][j+1][i],F[t][j][k]+G[i+1][i]);
        }
        t=1-t;
    }
    res=0;
    //cout<<F[3][1][2]<<endl;
    //cout<<G[3][2]<<endl;
    FOR (k,1,n)
    res=max(res,F[t][sk][k]);
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

