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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const int maxn = 100+10;
pair<int,int> a[maxn];
int c[maxn];
int b[maxn];
int kq[maxn];
int spt;
int F[2][maxn][maxn][maxn];
int n,res;
int s;
int main()
{
    freopen("B353.inp","r",stdin);
    //freopen("B353.out","w",stdout);
    cin>>n;
    n*=2;
    FOR(i,1,n) cin>>a[i].first,a[i].second=i;
    sort(a+1,a+1+n);
    a[0].first=-123123;
    FOR(i,1,n)
    {
        if (a[i].first!=a[i-1].first)
        {
            spt++;
            b[spt]=a[i].first;
        }
        c[spt]++;
    }
    F[0][0][0][0]=1;
    FOR(i,0,spt-1)
    {
        memset(F[(i+1)%2],0,sizeof(F[(i+1)%2]));
        FOR(j,0,i)
        FOR(k,0,i)
        FOR(t,0,s)
        {
            if (F[i%2][j][k][t]==0) continue;
            FOR(l,0,c[i+1])
            {
                F[(i+1)%2][j+(l>0)][k+(c[i+1]-l>0)][t+l]
                =max(F[(i+1)%2][j+(l>0)][k+(c[i+1]-l>0)][t+l],F[i%2][j][k][t]+j*(c[i+1]-l>0)+k*(l>0));
            }
        }
        s=s+c[i+1];
    }
    int res=0;
    FOR(j,0,spt)
    FOR(k,0,spt)
    FOR(t,0,s)
    res=max(res,F[spt%2][j][k][n/2]);
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
