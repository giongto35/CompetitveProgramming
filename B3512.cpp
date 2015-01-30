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

double res;
long long C[3000][3000];
long double m50[1000000+10];
int n,sp;
int dem;
int main()
{
    freopen("B351.inp","r",stdin);
    //freopen("B351.out","w",stdout);
    //cin>>n;
    n=7;
    m50[0]=1;
    FOR(i,1,1000000) m50[i]=m50[i-1]*0.5;
    C[0][0]=1;
    FOR(i,1,100)
    {
        C[i][0]=1;
        FOR(j,1,100)
        C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    sp=n/2;
    dem=0;
    for(int i=n;i<=100;i+=2)
    {
        res=res+i*C[sp][dem]*m50[sp];
        cout<<i<<' '<<sp<<' '<<m50[sp]<<' '<<C[sp][dem]<<' '<<res<<endl;
        dem++;
        //cout<<i<<' '<<m50[sp]<<endl;
        sp++;
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

