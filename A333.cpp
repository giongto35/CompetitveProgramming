
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
const int maxn = 1000+10;
int spt;
long long n,c[maxn],m;
long long M3[maxn];
int vt;
int main()
{
    //freopen("A333.inp","r",stdin);
    //freopen("A333.out","w",stdout);
    cin>>n;
    M3[0]=1;
    for(int i=1;M3[i-1]<=n;i++)
    {
        spt=i;
        M3[i]=M3[i-1]*3;
    }
    m=n;
    DOW(i,spt,0)
    {
        c[i]=n/M3[i];n=n%M3[i];
        if (c[i]!=0) vt=i;
        //cout<<c[i]<<' ';
    }
    m=m/M3[vt+1];
    cout<<m+1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
