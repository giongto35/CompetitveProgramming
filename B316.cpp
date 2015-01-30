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
const int maxn=1000+10;
int bf[maxn];
int bl[maxn];
int g[maxn];
int d[maxn];
int y;
int n,x,cnt;
int vt[maxn];
bool F[maxn];

void rec(int u)
{
    if (g[u]!=0) return;
    if (bf[u]==0) {g[u]=u;vt[u]=0;bl[g[u]]++; return;}
    rec(bf[u]);
    vt[u]=vt[bf[u]]+1;
    g[u]=g[bf[u]];
    bl[g[u]]++;
}

int main()
{
    //freopen("B316.inp","r",stdin);
    //freopen("B316.out","w",stdout);
    cin>>n>>x;
    FOR(i,1,n)
    {
        cin>>bf[i];
        if (bf[i]==0)
        d[++cnt]=i;
    }
    FOR(i,1,n) rec(i);
    F[0]=true;
    y=g[x];
    //FOR(i,1,n) cout<<i<<' '<<g[i]<<' '<<vt[i]<<endl;
    FOR(i,1,cnt)
    {
        if (d[i]==y) continue;
        int c=bl[d[i]];
        //cout<<c<<' '<<d[i]<<' '<<bl[d[i]]<<endl;
        DOW(j,n,c) if (F[j-c]==true) F[j]=true;
    }
    FOR(i,0,n)
        if (F[i]) cout<<i+1+vt[x]-vt[g[x]]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

