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
long long res;
long long T;
int n;
const int maxn = 100000;
long long a[maxn];
long long b[maxn];
int spt;

long long GCD(long long a,long long b) {return !b?a:GCD(b,a%b);}
int main()
{
    //freopen("Coolguys.inp","r",stdin);
    //freopen("Coolguys.out","w",stdout);
    cin>>T;
    FOR(i,1,T)
    {
        cin>>n;
        spt=0;
        for(int i=1;i*i<=n;i++)
        {
            a[++spt]=i;
            b[spt]=n/i;
        }
        a[spt+1]=b[spt];
        b[spt+1]=a[spt];
        res=0;
        FOR(i,1,spt)
        {
            res=res+b[i];
            res=res+(b[i]-b[i+1])*a[i];
        }
        long long m=(long long)n*n;
        long long g=GCD(res,m);
        res/=g;
        m/=g;
        cout<<res<<'/'<<m<<endl;
        /*res=0;
        FOR(i,1,n) res=res+n/i;
        cout<<res<<endl;*/
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

