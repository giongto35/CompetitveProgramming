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
const int maxn=100000+10;
int next[maxn];
int root[maxn];
int GH;
int D[maxn];
bool SNode[maxn];

void TraceSameD(int &u,int v)
{
    if (D[u]<D[v]) {tg=u;u=v;v=tg;}
    while (D[u]!=D[v])
    {
        delta=D[u]-D[v];
        GH=log2(delta);
        u=lab[u][GH];
    }
}

void query(int u,int v)
{
    int i,j,tg;
    if (D[u]<D[v]){tg=u;u=v;v=tg;}
    int z=u;;
    TraceSamdeD(u,v);
    if (u==v)
    {
        if (SNode[u]==false)
        {
            cout<<d[z]-d[v];
        }
    }
}
int main()
{
    freopen("specialg.in","r",stdin);
    freopen("specialg.out","w",stdout);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

`
