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
//#include "conio.h"
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
long long a[100000+10],k[100000+10];
const long long sll=9223372036854775807LL;
long long m,l,r,gtmax,smax,vmax;
long long res;
int n;
bool check(long long x)
{
    long long sl;
    FOR(i,1,n)
    {
        if (2*(x-a[i])>=smax) sl=vmax; else
        sl = (long long)1<<(long long)(2*(x-a[i]));
    //cout<<x<<' '<<sl<<endl;
    //getch();
        if (sl<k[i]) return false;
    }
    return true;
}

int main()
{
    //freopen("a269.inp","r",stdin);
    //freopen("a269.out","w",stdout);
    cin>>n;
    gtmax=0;
    smax=0;
    long long v=1;
    FOR(i,1,1000000000)
    {
        if (v<=sll/2)
        {
            v=v*2;
            smax=i;
            vmax=v;
        }
        else
            break;
    }
    FOR(i,1,n)
    {
        cin>>a[i]>>k[i];
        gtmax=max(gtmax,a[i]);
    }
    l=gtmax+1;
    r=gtmax+smax;
    //cout<<l<<' '<<r<<endl;
    while (l<=r)
    {
        m=(l+r)/2;
        if (check(m)) res=m,r=m-1;
        else l=m+1;
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
