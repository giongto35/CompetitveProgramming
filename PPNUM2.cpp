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
const int cmod = 1000000007;
const int maxn = 20;
int l,r,T;
string st;
long long m10[maxn];
long long F[maxn];
long long sum;
int calc(int s)
{
    if (s<=0) return 0;
    stringstream ss;
    ss<<s;
    st=ss.str();
    int n=st.length();
    long long res=0;
    FOR(i,1,n-1)
    {
        long long sum=((m10[i]+m10[i-1]-1)*(m10[i]-m10[i-1]))%cmod;
        //cout<<i<<' '<<sum<<endl;
        res=(res+sum*i)%cmod;
    }
    //cout<<res<<endl;
    res=(res+((s+m10[n-1])*(s-m10[n-1]+1))%cmod*n)%cmod;
    return (res*500000004)%cmod;

}

int main()
{
    //freopen("PPNUM.inp","r",stdin);
    //freopen("PPNUM.out","w",stdout);
    scanf("%d",&T);
    m10[0]=1;
    FOR(i,1,10) m10[i]=(m10[i-1]*10)%cmod;
    FOR(i,1,T)
    {
        cin>>l>>r;
        cout<<(calc(r)-calc(l-1)+cmod)%cmod<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

