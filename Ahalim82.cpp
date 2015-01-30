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
const int maxn=19;
const int oo=1000000000;
int a[maxn][maxn];
int F[maxn][(1<<maxn)-1];
int mb,n,st;

int main()
{
    freopen("Ahalim8.inp","r",stdin);
    //freopen("Ahalim8.out","w",stdout);
    scanf("%d",&st);
    FOR(c,1,st)
    {
        scanf("%d",&n);
        FOR(i,0,n-1)
        FOR(j,0,n-1)
        scanf("%d",&a[i][j]);
        mb=(1<<n)-1;

        FOR(i,0,n-1) FOR(j,0,mb) F[i][j]=oo;
        FOR(i,0,n-1) F[i][1<<i]=a[i][0];
        FOR(j,0,mb)
        FOR(i,0,n-1)
        {
            if (F[i][j]!=oo) continue;
            F[i][j]=oo;
            FOR(k,0,n-1)
            {
                if (k!=i&&(((j>>k)&1)==0))
                F[k][j|(1<<k)]=min(F[k][j|(1<<k)],F[i][j]+a[k][i]);
            }
            //cout<<i<<' '<<j<<' '<<F[i][j]<<endl;
        }
        cout<<F[0][mb]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


