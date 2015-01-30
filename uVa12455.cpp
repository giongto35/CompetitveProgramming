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

const int maxn = 30+10;
int T,n;
long long a[maxn];
map<long long, bool> F;
long long sum;
long long l;
bool res;

void gen(int i,int kt,int t)
{
    if (i == kt + 1)
    {
        if (t == 1) F[sum] = true;
        else
        if (F[l - sum]){
            res = true;
        }
        return;
    }
    gen(i+1,kt,t);
    if (res) return;
    sum+=a[i];
    gen(i+1,kt,t);
    if (res) return;
    sum-=a[i];

}
int main()
{
    //freopen("uva12455.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d",&T);
    FOR(st,1,T)
    {
        scanf("%d",&l);
        scanf("%d",&n);
        for(int i = 1 ; i <= n; i ++)
            scanf("%d",&a[i]);
        res = false;
        sum = 0 ;
        F.clear();
        gen(1,n / 2,1);
        gen(n / 2 + 1,n,2);
        if (res) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

