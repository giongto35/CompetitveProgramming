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
long long a,b,c;
const long long cmod = 1000000007;
int T;
long long A[5];

long long mul(long long a,long long b, long long c)
{
    return (((a*b)%cmod)*c)%cmod;
}

long long mul(long long a,long long b)
{
    return (a*b)%cmod;
}

int main()
{
//    freopen("threediff.inp","r",stdin);
//    freopen("threediff.out","w",stdout);
    cin>>T;
    while (T>0)
    {
        cin>>A[1]>>A[2]>>A[3];
        sort(A+1,A+4);
        a=A[1];b=A[2];c=A[3];
        c=c-b;b=b-a;
        a%=cmod;b%=cmod;c%=cmod;
        cout<<(mul(a,a-1,a-2)+mul(a,a-1,b+c)+mul(a,b,a-1)+mul(a,b,b-1)+mul(a,b,c))% cmod<<endl;
        T--;
        //if (T>0) cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

