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
const int maxn = 100;
double F[1<<17];
int n;
int p[maxn],a[maxn],b[maxn];
int kb[1<<17],T;
double res;
int main()
{
    //freopen("LEEXAMS.inp","r",stdin);
    //freopen("LEEXAMS.out","w",stdout);
    cin>>T;
    FOR(i,1,(1<<16)-1) kb[i]=kb[i & (i-1)]+1;
    FOR(i,1,T)
    {
        cin>>n;
        FOR(i,1,n)
        {
            cin>>p[i]>>a[i]>>b[i];
            a[i]--;
            b[i]--;
        }
        memset(F,0,sizeof(F));
        F[0]=1;
        res=0;
        FOR(i,0,(1<<16)-1)
        {
            if (kb[i]==n) res=res+F[i];
            if (kb[i]>=n) continue;
            if (F[i]!=0)
            {
                //cout<<i<<' '<<F[i]<<endl;
                int j=kb[i]+1;
                if (((i>>a[j])&1)==0)
                    F[i|(1<<a[j])]+=F[i]*((p[j]+0.0)/100);
                if (((i>>b[j])&1)==0)
                    F[i|(1<<b[j])]+=F[i]*((100-p[j]+0.0)/100);
            }
        }
        cout<<fixed<<setprecision(6)<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

