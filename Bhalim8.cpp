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
const int maxn=16;
const int oo=1000000000;
int a[maxn][maxn];
long long F[(1<<maxn)][2][2];
int cnt[(1<<maxn)];
int mb,n,st,i;

int calc(int bit)
{
    int res=0;
    FOR(i,0,maxn-1) if ((bit>>i)&1==1) res++;
    return res;
}

int main()
{
    //freopen("Bhalim8.inp","r",stdin);
    //freopen("Ahalim8.out","w",stdout);
    scanf("%d",&st);
    FOR(j,0,(1<<maxn)-1) cnt[j]=calc(j);
    FOR(c,1,st)
    {
        scanf("%d",&n);
        FOR(i,0,n-1)
        FOR(j,0,n-1)
        scanf("%d",&a[i][j]);
        mb=(1<<n)-1;

        FOR(i,0,mb)
        FOR(j,0,1)
        FOR(k,0,1)
        F[i][j][k]=0;

        F[0][0][1]=1;
        FOR(j,0,mb-1)
        FOR(k,0,1)
        FOR(l,0,1)
        {
            if (F[j][k][l]==0) continue;
            i=cnt[j];
            FOR(u,0,n-1)
            if (((j>>u)&1)==0)
            {
                //cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<(j|(1<<u))<<' '<<(k|(a[i][u]==2))<<' '<<(l&(a[i][u]==1))<<endl;
                F[j|(1<<u)][k|(a[i][u]==2)][l&(a[i][u]==1)]+=F[j][k][l];
            }
        }
        long long res=0;
        FOR(k,0,1)
        res+=F[mb][k][1-k];
        cout<<"Case "<<c<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


