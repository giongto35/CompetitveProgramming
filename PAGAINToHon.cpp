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
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( unsigned long long  i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( unsigned long long  i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<unsigned long long > VI ;
typedef vector<string> VS ;
template<class T> inline unsigned long long  size(const T&c) { return c.size(); }

using namespace std;
const unsigned long long lim=1000000000000000000LL;
unsigned long long  T,n;

unsigned long long mul(unsigned long long a,unsigned long long b,unsigned long long m)
{
    if (a==0||b==0) return 0;
        if (a<=lim/b) return (a*b)%m;
        if (b%2==0)
        {
            unsigned long long x=mul(a,b/2,m);
            return (x*2)%m;
        }
        else
            return (mul(a,b-1,m)+a)%m;
}

unsigned long long  pow(unsigned long long  a,unsigned long long  n,unsigned long long  m)
{
    if (n==0) return 1;
    if (n%2==1) return mul(a,pow(a,n-1,m),m);
    else
    {
        unsigned long long temp=pow(a,n/2,m);
        return mul(temp,temp,m);
    }
}

bool rabinmiller(unsigned long long  n,unsigned long long  k)
{
    if (n == 2) return true;
    if (n % 2 ==0) return false;
    unsigned long long  d=n-1;
    unsigned long long  s=0;
    while (d%2==0) d/=2,s++;
    FOR(i,1,k)
    {
        unsigned long long  a=rand()%(n-2)+2;
        unsigned long long x=pow(a,d,n);
        if (x==1||x==n-1) continue;
        FOR(r,1,s-1)
        {
            x=mul(x,x,n);
            if (x==1) return false;
            if (x==n-1) break;
        }
        if (x!=n-1) return false;
    }
    return true;
}

int main()
{
    //freopen("PAGAIN.inp","r",stdin);
    //freopen("PAGAIN.out","w",stdout);
    cin>>T;
    while (T>0)
    {
        //scanf("%ulld",&n);
        cin>>n;
        n--;
        while (n>0)
        {
            if (rabinmiller(n,20))
            {
                cout<<n<<endl;
                break;
            }
            n--;
        }
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

