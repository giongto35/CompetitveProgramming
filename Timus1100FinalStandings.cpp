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
struct kdl
{
    int vt;
    int id;
    int l;
} a[150000+10];
int n;

bool mycmp(kdl u,kdl v)
{
    if (u.l==v.l) return u.vt<v.vt;
    else return u.l>v.l;
}

int main()
{
    //freopen("FinalStandings.inp","r",stdin);
    //freopen("FinalStandings.out","w",stdout);
    cin>>n;
    FOR(i,1,n) scanf("%d%d\n",&a[i].id,&a[i].l),a[i].vt=i;
    sort(a+1,a+1+n,mycmp);
    FOR(i,1,n) cout<<a[i].id<<' '<<a[i].l<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

