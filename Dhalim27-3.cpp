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
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
const int maxn=100000;
long long a[maxn],n;
void factorize(long long n)
{
    long long i=2;
    int k=0;
    while (i*i<=n)
    {
         while (n%i==0)
            {
                a[++k]=i;
                n/=i;
            }
        i++;
    }
    if (n>1) a[++k]=n;
    sort(a+1,a+1+k);
    FOR(i,1,k-1) cout<<a[i]<<' ';
    cout<<a[k]<<endl;
}

int main()
{
    //freopen("Dhalim27-3.inp","r",stdin);
    //freopen("Dhalim27-3.out","w",stdout);
    while (true)
    {
        cin>>n;
        if (n==0) break;
        factorize(n);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

