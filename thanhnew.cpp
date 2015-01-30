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
#include <cstring>
#include <cstdlib>
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
int n, m, cnt;
map<string, int> id;
pair<int, int> edge[400];
int f[2][1<<20];
vector<int> a[20];
int T;

inline int getbit(const int n, const int i) {
    return (n>>i)&1;
}

int main() {
    freopen("Chalim1.inp","r",stdin);
    //freopen("Chalim1.out","w",stdout);

    for(scanf("%d", &T); T; T--) {
        cin >> n >> m;
        cnt = 0;
        id.clear();
        for(int i = 0; i < n; i++) a[i].clear();
        for(int i = 1; i <= m; i++) {
            string u, v;
            cin >> u >> v;
            if (!id[u]) id[u] = ++cnt;
            if (!id[v]) id[v] = ++cnt;
            if (id[u] > id[v]) a[id[u]-1].push_back(id[v]-1);
            else a[id[v]-1].push_back(id[u]-1);
        }
        memset(f, 0, sizeof f);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < (1<<(i+1)); j++) {
                if (!getbit(j, i)) f[i][j] = f[i-1][j];
                else
                    for(int k = 0; k < a[i].size(); k++)
                        if (!getbit(j, a[i][k]))
                            f[i][j] = max(f[i][j], f[i-1][j-(1<<i)-(1<<a[i][k])] + 1);
            }
        }
        int ret = 0;
        for(int j = 0; j < (1<<n); j++) ret = max(ret, f[n-1][j]);

        cout << ret << endl;
    }
    return 0;
}
