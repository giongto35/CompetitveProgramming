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
const int maxn=100000+10;
double F[maxn],G[maxn];
long long R,m;
double res;
int main()
{
    //freopen("B336.inp","r",stdin);
    //freopen("B336.out","w",stdout);
    cin>>m>>R;
    F[0]=0;
    G[0]=sqrt(R*R+R*R);
    FOR(i,1,m)
    {
        if (i==2) G[i]=G[i-1]+G[0];else
        G[i]=G[i-1]+2*R;
        F[i]=F[i-1]+G[i];
    }
        //cout<<sqrt(R*R+R*R)<<endl;
    //cout<<fixed<<setprecision(6)<<G[1]<<' '<<G[2]<<' '<<G[3]<<endl;
    //cout<<fixed<<setprecision(6)<<F[1]<<' '<<F[2]<<' '<<F[3]<<endl;
    FOR(i,1,m)
    {
        res=res+F[m-i]+F[i-1]+2*R;
        //cout<<F[m-i]<<' '<<F[i-1]<<endl;
    }
    //cout<<res<<' '<<m*m<<endl;
    cout<<fixed<<setprecision(6)<<(res+0.0)/(m*m)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

