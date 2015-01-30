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

const int maxn = 100000+10;
int n,a,b;
int p[maxn];
map<int,int> ma;
int res[maxn];
pair<int,int> c[maxn];
int main()
{
    freopen("B468.inp","r",stdin);
    //freopen("B468.out","w",stdout);
    scanf("%d%d%d",&n,&a,&b);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&p[i]);
        ma[p[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        c[i].second = i;
        if (ma[a - p[i]] != 0) c[i].first ++;
        if (ma[b - p[i]] != 0) c[i].first ++;
    }
    sort(c + 1 , c + 1 + n);
    for (int i = 1; i <= n; i++) res[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        int u = c[i].second;
        if (res[u] != -1) continue;
        cout<<c[i].first<<' '<<c[i].second<<endl;
        if (ma[a - p[u]] != 0 && res[ma[a - p[u]]] == -1) {
            res[u] = 0;
            res[ma[a - p[u]]] = 0;
        }
        if (ma[b - p[u]] != 0 && res[ma[b - p[u]]] == -1) {
            res[u] = 1;
            res[ma[b - p[u]]] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        cout<<res[i]<<' ';
    for (int i = 1; i <= n; i++)
        if (res[i] == -1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for (int i = 1; i <= n; i++) cout<<res[i]<<' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

