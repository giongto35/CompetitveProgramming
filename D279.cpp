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
const int maxn=30;
int a[maxn];
int n;
int vt[maxn][maxn];
bool F[(1<<23)-1];

int cnt(int bit)
{
    int res=0;
    FOR(i,0,n-1) if ((bit>>i)&1==1) res++;
    return res;
}
int main()
{
    //freopen("D279.inp","r",stdin);
    //freopen("D279.out","w",stdout);
    cin>>n;
    FOR(i,0,n-1) cin>>a[i];
    FOR(i,0,n-1) FOR(j,0,n-1) vt[i][j]=-1;
    FOR(i,0,n-1)
    FOR(j,0,n-1)
    FOR(k,0,n-1)
        if (a[i]+a[j]==a[k]) vt[k][i]=j;

    memset(F,false,sizeof(F));
    F[1]=true;
    FOR(i,1,(1<<(n-1))-1)
    {
        if (F[i]==false) continue;
        int bd= log2(i);
        FOR(k,0,bd)
        if (vt[bd+1][k]!=-1)
        if ((i>>k)&1==1)
        if ((i>>vt[bd+1][k])&1==1)
        {
            F[i|(1<<(bd+1))]=true;
            FOR(j,0,bd)
            {
                //if (((i^(1<<j))|(1<<(bd+1)))==4) cout<<"abc"<<i<<' '<<j<<' '<<bd+1<<' '<<k<<' '<<vt[bd+1][k]<<endl;
                if ((i>>j)&1==1) F[(i^(1<<j))|(1<<(bd+1))]=true;
            }
            break;
        }
    }
    int res=n+1;
    FOR(i,0,(1<<n)-1)
    {
        if ((int)log2(i)==n-1&&F[i])
            res=min(res,cnt(i));
    }
    if (res==n+1) cout<<-1;
    else cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

