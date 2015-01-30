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
const int maxn=100000+10;
int l,r,n;
int a[maxn];
int main()
{
    //freopen("A286.in","r",stdin);
    //freopen("A286.out","w",stdout);
    cin>>n;
    if (n%4==2||n%4==3)
        cout<<-1;
    else
    {
        l=1;
        r=n;
        while (r-l+1>=4)
        {
            a[l]=l+1;
            a[l+1]=r;
            a[r]=r-1;
            a[r-1]=l;
            l+=2;
            r-=2;
        }
        if (l==r)
            a[l]=l;
        FOR(i,1,n) cout<<a[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

