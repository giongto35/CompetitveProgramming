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
const int maxn = 100000+10;
int a[maxn],n,m;
long long res;

int road(int u,int v)
{
    //return min(abs(u-v),n-abs(u-v));
    if (u>v) return n+(v-u);else return v-u;
}
int main()
{
    //freopen("B339.inp","r",stdin);
    //freopen("B339.out","w",stdout);
    cin>>n>>m;
    FOR(i,1,m) scanf("%d",&a[i]);
    a[0]=1;
    res=0;
    FOR(i,1,m)
    {
        //int sum=1000000000;
        //sum=min(sum,road(a[i-1],1)+road(1,i)+road(i,a[i]));
        //sum=min(sum,road(a[i-1],i)+road(i,1)+road(1,a[i]));doc sai de
        //cout<<sum<<endl;
        //cout<<road(a[i-1],a[i]);
        res=res+road(a[i-1],a[i]);
    }
    cout<<res<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

