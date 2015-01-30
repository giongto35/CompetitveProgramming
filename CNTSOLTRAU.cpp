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
const int cmod=1000000007;
map<int,int> c;
int x,T,upper,d,m,n;
long long res;
int smod[maxn];
int bd,ck;
int modpow(const int a,const int n,const int m)
{
    if (n==0) return 1;
    if (n%2==1) return ((long long)modpow(a,n-1,m)*a)% m;
    else
    {
        long long s=modpow(a,n/2,m);
        return (s*s)%m;
    }
}
int main()
{
    freopen("CNTSOL.inp","r",stdin);
    //freopen("CNTSOL.out","w",stdout);

    cin>>T;
    FOR(i,1,T)
    {
        cin>>upper>>d>>m>>n;
        x=1;
        res=0;
        FOR(i,0,upper)
        {
            FOR(j,0,upper)
            FOR(k,0,upper)
            {

                if ((modpow(i,d,n)+modpow(j,d,n)+modpow(k,d,n))%n==m)
                {
                    //cout<<i<<' '<<j<<' '<<k<<' '<<(modpow(i,d,n)+modpow(j,d,n)+modpow(k,d,n))<<' '<<m<<endl;
                    res=(res+1)%cmod;
                }
            }
        }
        cout<<res<<endl;
    }
    /*
    FOR(i,1,40)
    {
        FOR(j,0,40)
        {
            x=1;
            FOR(k,0,100)
            {
                x=(x*j)%i;
                cout<<x<<' ';
            }
            cout<<endl;
        }
    }*/
    fclose(stdin);
    fclose(stdout);
    return 0;
}

