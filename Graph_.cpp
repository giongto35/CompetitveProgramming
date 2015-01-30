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
#define RESET(a,i) memset(a,i,sizeof(a))
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))
#define fi first
#define se second

typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
const int maxn=100000+10;

vector <int> ke[maxn + 5];

int low[maxn + 5], num[maxn + 5], parent[maxn + 5];
int Counter, dfsRoot, rootChildren;
bool articulation_vertex[maxn + 5];
int n,m,u,v;
int SBridge,SCut;
void articulationPointAndBridge(int u) {
    low[u] = num[u] = Counter++;
    REP (j, ke[u].size()) {
        int v = ke[u][j];
        if (num[v] == -1) {
            parent[v] = u;
            if (u == dfsRoot) rootChildren++;
            articulationPointAndBridge(v);
            if (low[v] >= num[u])
                articulation_vertex[u] = true;
            if (low[v] > num[u]) SBridge++;
            low[u] = min(low[u], low[v]);
        } else if (v != parent[u])
            low[u] = min(low[u], num[v]);
    }
}
int main() {
    // init graph, indices from 0
    //freopen("GRAPH_.inp","r",stdin);
    //freopen("GRAPH_.out","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,m) {scanf("%d%d",&u,&v);ke[u].push_back(v);ke[v].push_back(u);}
    Counter = 0; RESET(num, -1); RESET(low, 0);
    RESET(parent, 0); RESET(articulation_vertex, 0);
    //printf("Bridges:\n");
    FOR(i,1,n) if (num[i] == -1) {
        dfsRoot = i; rootChildren = 0;
        articulationPointAndBridge(i);
        articulation_vertex[dfsRoot] = (rootChildren > 1);
    }
    FOR(i,1,n) if (articulation_vertex[i]) SCut++;
    cout<<SCut<<' '<<SBridge;
    //printf("Articulation Points:\n");
    //FOR(i,1,n) if (articulation_vertex[i])
        //printf(" Vertex %d\n", i);
}
