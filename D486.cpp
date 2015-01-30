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

const int cmod = 1000000007;
const int maxn = 2000+10;
int a[maxn];
int b[maxn];
vector<int> ke[maxn];
int mind;
bool vis[maxn];
long long res;
int d,n,u,v;
int F[maxn];
long long tempres;

void DFS(int u) {
    vis[u] = true;

    F[u] = b[u];
    for (int i = 0; i < ke[u].size(); i++){
        int v = ke[u][i];
        if (vis[v] == false) {
            DFS(v);
            F[u] = ((long long)F[u] * (1 + F[v])) % cmod;
        }
    }
    tempres = (tempres + F[u]) % cmod;
}

long long calc(){
    memset(vis, false, sizeof(vis));
    tempres = 0;
    DFS(1);
    return tempres;
}

int main()
{
    //freopen("D486.inp","r",stdin);
    //freopen("","w",stdout);
    scanf("%d%d",&d,&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <= n - 1; i ++){
        scanf("%d%d",&u,&v);
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    for (mind = 0; mind <= 2000; mind++){
        for (int i = 1; i <= n; i++){
            if (a[i] >= mind && a[i] <= mind + d) {
                b[i] = 1;
            } else b[i] = 0;
        }
        long long res1 = calc();
        for (int i = 1; i <= n; i++){
            if (a[i] > mind && a[i] <= mind + d) {
                b[i] = 1;
            } else b[i] = 0;
        }
        long long res2 = calc();
        res = (res + res1 - res2) % cmod;
    }

    cout<<(res % cmod + cmod) % cmod<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

