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
// Note: indices from 0
const int maxn=100000+10;
int num[maxn + 5], low[maxn + 5], visited[maxn + 5];
int Counter, numSCC;
vector <int> S;
vector <int> ke[maxn + 5];
int n,m,u,v;

void tarjanSCC(int u) {
    low[u] = num[u] = Counter++;
    S.push_back(u);
    visited[u] = 1;
    REP (j, SIZE(ke[u])) {
        int v = ke[u][j];
        if (num[v] == -1) tarjanSCC(v);
        if (visited[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]) {
            numSCC++;
        //printf("SCC %d:", numSCC);
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            //printf(" %d", v);
            if (u == v) break;
        }
        //printf("\n");
    }
}
int main() {
    freopen("Graph_.inp","r",stdin);
    //freopen("Graph_.out","w",stdout);
    // Initialize V, G.
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d%d",&u,&v),ke[u].push_back(v);
    RESET(num, -1); RESET(low, 0); RESET(visited, 0);
    Counter = numSCC = 0;
    FOR(i,1,n) if (num[i] == -1) tarjanSCC(i);
    cout<<numSCC;
}
