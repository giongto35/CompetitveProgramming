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
const int maxn = 300+10;
const long long oo = 1100000000000000000LL;
struct range
{
    int l,r;
    long long c;
} u,a[100000+10];
vector<int> ke[maxn];
long long F[maxn][maxn];
long long g[maxn];
int i,j,n,m,sk;
int main()
{
    //freopen("D313.inp","r",stdin);
    //freopen("D313.out","w",stdout);
    cin>>n>>m>>sk;
    FOR(i,1,m)
    {
        cin>>a[i].l>>a[i].r>>a[i].c;

        ke[a[i].r].push_back(i);
    }
    FOR(i,0,n) FOR(j,0,n) F[i][j]=oo;
    F[0][0]=0;
    FOR(i,1,n)
    {
        FOR(j,1,i) g[j]=oo;
        FOR(j,0,ke[i].size()-1)
        {
            u=a[ke[i][j]];
            g[u.l]=min(g[u.l],u.c);
        }
        FOR(j,2,i) g[j]=min(g[j],g[j-1]);
        FOR(j,0,n)
        {
            F[i][j]=min(F[i][j],F[i-1][j]);
            DOW(k,i-1,0)
            if (j>=(i-k))
            F[i][j]=min(F[i][j],F[k][j-(i-k)]+g[k+1]);
        }
    }
    long long res=oo;
    FOR(i,sk,n) res=min(res,F[n][i]);
    if (res>=oo) cout<<-1; else
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

