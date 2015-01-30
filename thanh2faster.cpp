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
bool f[2][1<<21];
int g[1<<21],t[1<<21],sb[1<<21];
int spt,k,j;
int T;

inline int getbit(const int &n, const int &i) {
    return (n>>i)&1;
}

inline int bitdau (const int &x)
{
    //DOW(i,n-1,0) if (getbit(x,i)) return i;
    return log2(x);
}

inline int phantich (const int &x)
{
    int res=0;
    FOR(i,1,n) if (getbit(x,i-1))res++;
    return res;
}

int main() {
    freopen("Chalim1s.inp","r",stdin);
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
            if (edge[i].first<edge[i].second){int tg=edge[i].first;edge[i].first=edge[i].second;edge[i].second=tg;}
        }
        sort(edge+1,edge+m+1);
        spt=0;
        /*for(int j = 0; j < (1<<n); j++)
            if (phantich(j)%2==0)
                {
                    g[++spt]=j;
                    t[spt]=bitdau(j);
                }
        */
        for(int j = 0; j < (1<<n); j++)
        {
            int bd=bitdau(j);
            if (j!=0)
            sb[j]=sb[j^(1<<bd)]+1;
            if (sb[j]%2==0)
                {
                    g[++spt]=j;
                    t[spt]=bd;
                }
        }
        cout<<spt<<endl;
        t[1]=0;

        memset(f, false, sizeof f);
        f[0][0]=true;

        for(int ii = 1; ii <= m; ii++) {
            int i = ii&1;
            for(int k = 1; k <= spt; k++) {
                j=g[k];
                if (t[k]>edge[ii].first) break;
                f[i][j]=  (f[i^1][j]||(((j>> edge[ii].first)&1) && ((j>> edge[ii].second)&1)&&f[i^1][j ^ (1<<edge[ii].first) ^ (1<<edge[ii].second)]));
            }
        }
        int ret = 0;
        m &= 1;
        for(int j = 0; j < (1<<n); j++) {
            if (f[m][j])
            ret = max(ret, sb[j]/2);
        }
        cout << ret << endl;
    }
    return 0;
}
