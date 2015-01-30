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
int a[maxn];
long long F[maxn][maxn][2];
int u,n;
const long long oo=1000000000000000000;
int main()
{
    freopen("cowrun.in1","r",stdin);
    freopen("cowrun.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    a[++n]=0;
    sort(a+1,a+n+1);

    DOW(i,n,1)
    FOR(j,i,n)
    FOR(k,0,1)
    {
        if (i==j)
        {
            F[i][j][k]=oo;
            if (a[i]==0) F[i][j][k]=0;
            continue;
        }
        F[i][j][k]=oo;
        FOR(l,0,1)
        {
            if (k==1&&F[i][j-1][l]<oo)
            F[i][j][k]=min(F[i][j][k],F[i][j-1][l]+(long long)(n-(j-i))*abs(a[j]-(1-l)*a[i]-l*a[j-1]));
            //if (i==2&&j==4&&k==1) cout<<"abc"<<' '<<F[i][j-1][l]<<' '<<abs(a[j]-l*a[i]-(1-l)*a[j-1])<<' '<<F[i][j][k]<<endl;
            if (k==0&&F[i+1][j][l]<oo)
            F[i][j][k]=min(F[i][j][k],F[i+1][j][l]+(long long)(n-(j-i))*abs(a[i]-(1-l)*a[i+1]-l*a[j]));
        }
    }
    cout<<min(F[1][n][0],F[1][n][1]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

