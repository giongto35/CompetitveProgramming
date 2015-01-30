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

int m,c,u,n;
double r,d;
int vt,T;
double res;
int main()
{
    //freopen("HELLO.inp","r",stdin);
    //freopen("HELLo.out","w",stdout);
    cin>>T;
    FOR(i,1,T)
    {
        scanf("%lf%d%d",&d,&u,&n);
        vt=0;
        res=d*u;
        FOR(i,1,n)
        {
            scanf("%d%lf%d",&m,&r,&c);
            //cout<<m<<' '<<r<<' '<<c<<' '<<c+r*u<<endl;
            if (res>((c+0.0)/m+r*u))
            {

                res=(c+0.0)/m+r*u;
                vt=i;
            }
        }
        cout<<vt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

