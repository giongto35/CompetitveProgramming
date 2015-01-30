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
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn=100+10;
const double eps = 0.0000001;
double F[2][maxn*maxn];
int i,a[maxn],s,p[maxn],T,n;
int main()
{
    //freopen("SHIRO.inp","r",stdin);
    //freopen("SHIRO.out","w",stdout);
    cin>>T;
    while (T>0)
    {
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",&a[i]);
        FOR(i,1,n) scanf("%d",&p[i]);
        int t=0;
        memset(F,0,sizeof(F));
        F[0][0]=1;
        s=0;
        FOR(t,0,n-1)
        {
            i=t%2;
            s=s+a[t];
            memset(F[1-i],0,sizeof(F[1-i]));
            FOR(j,0,s)
            {
                //if (abs(F[i][j])<eps)continue;
                //cout<<t<<' '<<i<<' '<<j<<' '<<F[i][j]<<' '<<F[i][j]*((p[t]+0.0)/100)<<' '<<endl;
                F[1-i][j+a[t+1]] = F[1-i][j+a[t+1]]+F[i][j]*((p[t+1]+0.0)/100);
                F[1-i][j]        = F[1-i][j]     +F[i][j]*(1-((p[t+1]+0.0)/100));
            }
        }
        s+=a[n];
        double res=0;
        FOR(j,(s+1)/2,s) res+=F[n%2][j];
        cout<<fixed<<setprecision(6)<<res<<endl;
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

