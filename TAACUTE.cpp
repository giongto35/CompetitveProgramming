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
const int maxn = 2000+10;
struct point
{
    int x;
    int y;
} a[maxn],b[maxn];
using namespace std;

bool mycmp(point a,point b)
{
    return a.x*b.y<a.y*b.x;
}

int main()
{
    freopen("TAACUTE.inp","r",stdin);
    freopen("TAACUTE.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>a[i].x>>a[i].y;
    FOR(i,1,n)
    {
        int spt=0;
        FOR(j,1,n) if (j!=i) b[++spt]=a[i];
        sort(b+1,b+1+n,mycmp);
        FOR(i,1,spt)
        {

        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

