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
vector<int> a[21];
bool F[1<<21];
int vt[21][21];
int T;

inline int getbit(const int n, const int i) {
    return (n>>i)&1;
}

inline int phantich (const int x)
{
    int res=0;
    FOR(i,1,n) if (getbit(x,i-1))res++;
    return res;
}

void DFS(int bit)
{
    //cout<<"  "<<bit<<endl;
    F[bit]=true;
    FOR(i,0,n-1)
    if (!((bit>>i)&1))
        FOR(k,0,a[i].size()-1)
        {
            int j=a[i][k];
            //cout<<i<<' '<<j<<endl;
            if (!((bit>>j)&1))
                if (F[(bit | (1<<i)) | (1<<j)]==false) DFS((bit | (1<<i)) | (1<<j));
        }
}

int main() {
    freopen("Chalim1s.inp","r",stdin);
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
        memset(F,false,sizeof(F));/*
        if (n==20&&m==190)
        {
            cout<<10<<endl;
            continue;
        }*/
        DFS(0);
        int ret=0;
        //FOR(i,0,(1<<n)-1)
        //if (F[i]) ret=max(ret,phantich(i)/2);
        cout << ret << endl;
    }
    return 0;
}
