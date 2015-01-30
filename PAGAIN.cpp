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
#define FOR(i,a,b) for( unsigned int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( unsigned int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<unsigned int> VI ;
typedef vector<string> VS ;
template<class T> inline unsigned int size(const T&c) { return c.size(); }

using namespace std;

unsigned int T,n;

unsigned int pow(unsigned int a,unsigned int n,unsigned int m)
{
    if (n==0) return 1;
    if (n%2==1) return ((unsigned long long)a*pow(a,n-1,m))%m;
    else
    {
        unsigned long long temp=pow(a,n/2,m);
        return (temp*temp)%m;
    }
}

bool rabinmiller(unsigned int n,unsigned int k)
{
    if (n == 2) return true;
    if (n % 2 ==0) return false;
    unsigned int d=n-1;
    unsigned int s=0;
    while (d%2==0) d/=2,s++;
    FOR(i,1,k)
    {
        unsigned int a=rand()%(n-2)+2;
        unsigned long long x=pow(a,d,n);
        if (x==1||x==n-1) continue;
        FOR(r,1,s-1)
        {
            x=(x*x)%n;
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
    cout<<rabinmiller(1,6)<<endl;/*
    cin>>T;
    while (T>0)
    {
        scanf("%ud",&n);
        n--;
        while (n>0)
        {
            if (rabinmiller(n,6))
            {
                cout<<n<<endl;
                break;
            }
            n--;
        }
        T--;
    }*/
    fclose(stdin);
    fclose(stdout);
    return 0;
}

