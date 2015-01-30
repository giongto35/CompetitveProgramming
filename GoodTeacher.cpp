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
#define RESET(c,x) memset (c, x, sizeof (c))
#define oo 1000111000
#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

const int maxn = 2000+10;
int T;
int q;
int u;
string c[maxn];
int n;
int main()
{
    //freopen("GoodTeacher.inp","r",stdin);
    //freopen("GoodTeacher.out","w",stdout);
    cin>>n;
    FOR(i,1,n) cin>>c[i];
    cin>>q;
    FOR(i,1,q)
    {
        cin>>u;
        if (c[u] != "?") cout<<c[u]; else{
        int l = u;
        int r = u;
        FOR(i,u+1,n)
            if (c[i]!="?") {r = i;break;}
        DOW(i,u-1,1)
            if (c[i]!="?") {l = i;break;}
        if (l == u || (l!=u && r!=u && r - u < abs(l - u))){ FOR(j,u,r - 1) cout<<"left of "; cout<<c[r];}  else
        if (r == u || (r!=u && l!=u && abs(l - u) < r - u)){ DOW(j,u,l + 1) cout<<"right of "; cout<<c[l];} else
        if (r - u == abs(l - u)) cout<<"middle of "<<c[l]<<" and "<<c[r];
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

