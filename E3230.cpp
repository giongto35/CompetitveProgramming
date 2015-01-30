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

const int maxn = 100000;
const int max_node = 10000;
int T;
int n,m,k;
vector<int> a[maxn];
stack<int> s;
int C;
int num[maxn];
int low[maxn];
int visited[maxn];
int counter;
int numSCC;
int D[maxn];
int s1,a1,s2,a2,u,v;
int E;
map<int,bool> chk[maxn];

void DFS(int u)
{
    low[u] = num[u] = counter++;
    s.push(u);
    visited[u] = 1;
    //cout<<u<<endl;
    FOR(i,0,a[u].size()-1)
    {
        int v = a[u][i];
        //cout<<u<<' '<<v<<endl;
        if (num[v] == -1) DFS(v);
        if (visited[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]){
        numSCC++;
        while(true){
            int v = s.top(); s.pop();
            D[v] = numSCC;visited[v] = 0;
            if (u == v) break;
        }
    }
}

int Not(int u)
{
    if (u % 2 == 0) return u + 1; else return u - 1;
}

void link(int u,int v)
{
    //cout<<Not(u)<<' '<<v<<endl;
    if (chk[Not(u)][v] == false)
    {
        a[Not(u)].push_back(v);chk[Not(u)][v] = true;
        E++;
    }
    if (chk[Not(v)][u] == false)
    {
        a[Not(v)].push_back(u);chk[Not(v)][u] = true;
        E++;
    }
}

int main()
{
    //freopen("E3230.inp","r",stdin);
    //freopen("E3230.out","w",stdout);
    scanf("%d",&T);
    for (int sT = 1; sT <= T; sT++)
    {
        scanf("%d",&m);
        int n = 0;
        for (int i = 0; i <= max_node; i++) a[i].clear(),chk[i].clear();
        E = 0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d",&u,&v);
            n = max(n, abs(u));
            n = max(n, abs(v));
            if (u==-(v)) continue;
            int nu = (abs(u) - 1 ) * 2;
            int nv = (abs(v) - 1 ) * 2;
            if ( u < 0 ) nu += 1;
            if ( v < 0 ) nv += 1;

            link(nu,nv);
        }
        /*
        printf("%d %d\n",n*2,E);
        for (int i = 0; i <= n * 2 - 1; i ++)
        {
            sort(a[i].begin(),a[i].end());
            FOREACH(it, a[i])
            printf("%d %d\n",i,*it);

        }
        */
        FOR(i,1,2*n) {visited[i] = 0; num[i] = -1; low[i] = -1; D[i] = 0;}
        counter = numSCC = 0;
        FOR(i,1,2*n) if (num[i] == -1) DFS(i);
        bool res = true;
        //FOR(i,1,2*(n+m)) cout<<D[i]<<endl;
        FOR(i,1,n) if (D[(i-1) * 2] == D[(i - 1) * 2 + 1]) {res = false; break;}
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

