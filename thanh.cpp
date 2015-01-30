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
int T;

inline int getbit(const int n, const int i) {
    return (n>>i)&1;
}

int main() {
    //freopen("Chalim1.inp","r",stdin);
    //freopen("Chalim1.out","w",stdout);

    for(scanf("%d", &T); T; T--) {

        cin >> n >> m;
        cnt = 0;
        id.clear();
        for(int i = 1; i <= m; i++) {
            string a, b;
            cin >> a >> b;
            if (!id[a]) id[a] = ++cnt;
            if (!id[b]) id[b] = ++cnt;
            edge[i] = make_pair(id[a]-1, id[b]-1);
        }

        memset(f, 0, sizeof f);

        for(int ii = 1; ii <= m; ii++) {
            int i = ii&1;
            memset(f[i], 0, sizeof f[i]);
            for(int j = 0; j < (1<<n); j++) {
                f[i][j] = max(f[i][j], f[i^1][j]);
                if (getbit(j, edge[ii].first) && getbit(j, edge[ii].second))
                    f[i][j] = max(f[i][j], f[i^1][j - (1<<edge[ii].first) - (1<<edge[ii].second)]+1);
            }
        }
        int ret = 0;
        m &= 1;
        for(int j = 0; j < (1<<n); j++) {
            ret = max(ret, f[m][j]);
        }

        cout << ret << endl;
    }
    return 0;
}
