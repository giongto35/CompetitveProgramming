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
#include <iomanip>
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
const int maxn = 2000+10;
long double C[maxn][maxn],rest,resm;
int a[maxn][maxn];
int n,k;
int main()
{
    //freopen("D332.inp","r",stdin);
    //freopen("D332.out","w",stdout);
    cin>>n>>k;
    C[0][0]=1;
    FOR(i,1,n)
    {
        C[i][0]=1;
        FOR(j,1,n) C[i][j]=C[i-1][j-1]+C[i-1][j];
        a[i][i]=-1;
    }
    FOR(i,1,n)
    FOR(j,i+1,n)
    {
        scanf("%d",&a[i][j]);
        a[j][i]=a[i][j];
    }
    FOR(i,1,n)
    {
        int cnt=0;
        FOR(j,1,n) if (a[i][j]!=-1) cnt++;
        FOR(j,1,n) if (a[i][j]!=-1)
        {
            rest=rest+C[cnt-1][k-1]*a[i][j];
        }
        resm=resm+C[cnt][k];
    }
    //cout<<rest<<' '<<resm<<endl;
    cout<<(long long)(rest/resm);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

