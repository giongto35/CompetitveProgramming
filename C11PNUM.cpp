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
const int smax=2642300;
bool prime[smax];
unsigned long long p[smax];
unsigned long long sp,kq,k,n,t;
void sieve(unsigned long long n)
{
    memset(prime,true,sizeof(prime));
    unsigned long long i=2;
    while (i*i<=n)
    {
        unsigned long long j=i*i;
        if (prime[j])
        while (j<=n)
        {
            prime[j]=false;
            j+=i;
        }
        i++;
    }
    FOR(i,2,smax) if (prime[i]) p[++sp]=i;
}

void check()
{
    kq=0;
        unsigned long long res=1;
        FOR(i,1,k)
        {
            if (res>n/p[i])return ;
            res=res*p[i];
        }
        if (res<=n) kq=res;
        FOR(i,k+1,sp)
        {
            //cout<<res<<endl;
            res=res/p[i-k];
            if (res>n/p[i])return ;
            res=res*p[i];
            if (res<=n) kq=res;
        }
}

int main()
{
    //freopen("C11PNUM.inp","r",stdin);
    //freopen("C11PNUM.out","w",stdout);
    scanf("%d",&t);
    sieve(2642245);
    //FOR(i,1,sp) cout<<p[i]<<' ';
    //cout<<sp<<endl;
    //return 0;
    FOR(st,1,t)
    {
        cin>>n>>k;
        check();
        if (kq==0) cout<<-1<<endl;else
        cout<<kq<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

